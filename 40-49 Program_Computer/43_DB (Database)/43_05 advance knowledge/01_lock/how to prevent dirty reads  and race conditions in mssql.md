#mssql 
- [[#Row Versioning|Row Versioning]]
- [[#Update rows atomically|Update rows atomically]]
	- [[#Update rows atomically#Explicit Transactions|Explicit Transactions]]
	- [[#Update rows atomically#Isolation Levels|Isolation Levels]]
	- [[#Update rows atomically#Lock Hints|Lock Hints]]
	- [[#Update rows atomically#Merge Statement|Merge Statement]]
- [[#Use Transactions with Locks|Use Transactions with Locks]]
- [[#Merge Statement with HOLDLOCK|Merge Statement with HOLDLOCK]]

## Row Versioning
```sql
ALTER DATABASE [<DBNAME>] SET ALLOW_SNAPSHOT_ISOLATION ON;
ALTER DATABASE [<DBNAME>] SET READ_COMMITTED_SNAPSHOT ON;
```

## Update rows atomically
### Explicit Transactions
Wrap your `UPDATE` statement within a transaction to ensure atomicity.
```sql
BEGIN TRANSACTION;
UPDATE YourTable
SET Column1 = 'NewValue'
WHERE SomeCondition;
COMMIT;
```
###  Isolation Levels
- Set an appropriate isolation level for your transaction. Common levels include:
    - `READ COMMITTED`: Reads only committed data.
    - `REPEATABLE READ`: Prevents other transactions from modifying data while your transaction is active.
    - `SERIALIZABLE`: Ensures that no other transactions can modify data until your transaction completes.
```sql
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
BEGIN TRANSACTION;
-- Your update statement here
COMMIT;
```

### Lock Hints
- Use lock hints to control how SQL Server locks rows during an `UPDATE`.
- For example, `WITH (UPDLOCK)` acquires an update lock on the rows being modified:
```sql
BEGIN TRANSACTION;
UPDATE YourTable
SET Column1 = 'NewValue'
WHERE SomeCondition
WITH (UPDLOCK);
COMMIT;
```

### Merge Statement
- The `MERGE` statement combines `INSERT`, `UPDATE`, and `DELETE` operations into a single statement.
- Use it with appropriate locking hints
```sql
MERGE INTO YourTargetTable AS target
USING YourSourceTable AS source
ON target.PrimaryKeyColumn = source.PrimaryKeyColumn
WHEN MATCHED THEN
    UPDATE SET target.Column1 = source.NewValue
WHEN NOT MATCHED THEN
    INSERT (Column1, Column2, ...)
    VALUES (source.NewValue, source.OtherValue, ...);

```

## Use Transactions with Locks
- Wrap your queries within a single transaction to ensure consistency.
- Use the `FOR UPDATE` hint to lock rows during a `SELECT` query:
```sql
BEGIN;
SELECT id_file FROM filenames WHERE pending = 1 LIMIT 1 FOR UPDATE;
-- Perform other operations
UPDATE filenames SET pending = 2 WHERE id_file = <id_of_select_query>;
COMMIT;
```
- [The `FOR UPDATE` lock prevents other transactions from modifying the same row until the transaction is complete](https://stackoverflow.com/questions/25559230/select-update-at-the-same-time-race-condition)[3](https://stackoverflow.com/questions/25559230/select-update-at-the-same-time-race-condition).

## Merge Statement with HOLDLOCK
Use the `MERGE` statement along with the `HOLDLOCK` hint to make the operation thread-safe:
```sql
MERGE tblWords WITH (HOLDLOCK) AS w
-- Specify your conditions and actions
```
- [This ensures that concurrent operations do not interfere with each other](https://stackoverflow.com/questions/43869042/preventing-conditional-insert-update-race-condition-in-ms-sql)[4](https://stackoverflow.com/questions/43869042/preventing-conditional-insert-update-race-condition-in-ms-sql)
