#mssql 

## Source
###  From tutorialsPoint
https://www.tutorialspoint.com/sql/sql-using-views.htm
### From ChatGpt
#### With check option
1. **With CHECK OPTION**: If you create a view with the "WITH CHECK OPTION" clause, any data modification made through the view `must adhere to the WHERE clause conditions defined in the view`. If a modification violates these conditions, it will be rejected.

```sql
-- create view with check option
CREATE VIEW dbo.生日_檢視_有WCO
-- WITH ENCRYPTION, SCHEMABINDING, VIEW_METADATA
AS
SELECT
	學號
   ,姓名
   ,生日
FROM dbo.學生
WHERE 生日 > '2003-03-01'
```

```sql
/* Error */
INSERT INTO 生日_檢視_有WCO
VALUES ('S016', '江峰', '2003-01-01')
GO
```

####  without check option
2. **Without CHECK OPTION**: If you create a view without the "WITH CHECK OPTION" clause, there are no restrictions imposed by the view on data modifications. This means modifications can violate the conditions specified in the WHERE clause of the view.