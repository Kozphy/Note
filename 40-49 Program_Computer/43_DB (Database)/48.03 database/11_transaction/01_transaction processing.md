#database 

## SQL Server 交易模式
The default is `Autocommit Transactions`, It has `three type` of transactions Mode in SQL Server.

### 自動認可交易模式 Autocommit Transactions Mode
In the default transaction model in MSSQL, every T-SQL instruction is automatically treated as a transaction. If a statement encounters an error, it automatically rolls back; otherwise, it commits the transaction.

| Alter table | Create | Delete         | Drop   |
| ----------- | ------ | -------------- | ------ |
| Fetch       | Grant  | Insert         | Open   |
| Revoke      | select | Truncate table | Update |

### 明顯交易模式 Explicit Transactions Mode
It uses `BEGIN TRAN`, `COMMIT TRAN`, and `ROLLBACK TRAN` to combine multiple T-SQL statements, creating a transaction.

| Alter database   |     | backup log       | create database   |
| ---------------- | --- | ---------------- | ----------------- |
| disk init        |     | drop database    | dump transaction  |
| load database    |     | load transaction | reconfigure       |
| restore database |     | restore log      | update statistics |

### 隱含交易模式 (Implicit Transactions Mode)
If we want to active this mode, we type following instruction.
```sql
set implicit_transactions on
```
After executing above instruction, MSSQL will enter implicit transaction mode, it will remain in this mode until `COMMIT TRAN` or `ROLLBACK TRAN` is issued. After that, it will automatically begin another transaction. Ending the transaction mode requires setting the option to `off`.
```sql
set implicit_transactions off
```

