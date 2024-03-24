#mssql 

- After the user goes offline, the temporary stored procedure will be deleted.

```sql
CREATE PROC #學生查詢
AS
BEGIN
	SELECT
		學號
	   ,姓名
	   ,電話
	FROM 學生
END
GO

EXEC #學生查詢
```

