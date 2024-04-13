#mssql 
- [[#`@[Tablename]`|`@[Tablename]`]]
- [[#`#[TableName]`|`#[TableName]`]]
- [[#`##[TableName]`|`##[TableName]`]]


## `@[Tablename]`
這是一個局部變數，僅對創建它的用戶可見。它在 T-SQL 中用於保存單個值，例如整數、字符串或日期。它不是一個實際的表，而是一個變數，用於在查詢或存儲過程中保存臨時數據。
```sql
declare @temp1 as Table
(
	id bigint,
	name nvarchar(20)
)

select * from @temp1
waitfor delay '00:00:15'
```

## `#[TableName]`
這是一個局部臨時表，僅對創建它的用戶可見。它在 T-SQL 中用於提供處理批處理或存儲過程中的中間結果的工作空間。它是一個臨時表，當會話結束時，它將自動被刪除。
```sql
CREATE TABLE #MyTempTable (
    ID INT,
    Name VARCHAR(50)
);
```
![](Pasted%20image%2020240413154534.png)

## `##[TableName]`
這是一個全局臨時表，對所有用戶可見。它的生存週期不僅限於創建它的會話，而是在整個 SQL Server 實例中持久存在。它通常用於在不同的會話之間共享臨時數據。

```sql
CREATE TABLE ##temp2 (
  ID BIGINT,
  [NAME] NVARCHAR(20)
);
```