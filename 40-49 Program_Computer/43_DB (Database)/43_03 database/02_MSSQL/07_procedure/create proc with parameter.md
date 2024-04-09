#mssql 

```sql
-- create procedure with parameter procedures
CREATE PROCEDURE 課程查詢 @c_no CHAR(5)
AS
BEGIN
SELECT
	課程編號
   ,名稱
   ,學分
FROM 課程
WHERE 課程編號 = @c_no
END

EXEC 課程查詢 CS349;

SELECT
	*
FROM 課程;

-- create procedure
CREATE PROC 員工查詢 @salary MONEY,
@tax MONEY
AS
BEGIN
IF @salary <= 0
SET @salary = 30000
	IF @tax <= 0
SET @tax = 300
SELECT
	身份證字號
   ,姓名
   ,(薪水 - 扣稅) AS 所得額
FROM 員工
WHERE 薪水 >= @salary
AND 扣稅 >= @tax
END

EXEC 員工查詢 @salary = 20000
		 ,@tax = 1000;

EXEC 員工查詢 50000
		 ,500;

-- create procedure with default parameter
CREATE PROC 地址查詢 @city CHAR(5) = '台北',
@street VARCHAR(30) = '中正路'
AS
BEGIN
SELECT
	身份證字號
   ,姓名
   ,(薪水 - 扣稅) AS 所得額
   ,(城市 + 街道) AS 地址
FROM 員工
WHERE 城市 LIKE @city
AND 街道 LIKE @street
END

EXEC 地址查詢;

-- execute proc with default parameter
EXEC 地址查詢 '桃園'
		 ,DEFAULT

-- execute nesting proc
CREATE PROC 呼叫程序 @proc_name VARCHAR(10)
AS
PRINT '開始層數: ' + CAST(@@NESTLEVEL AS CHAR)

PRINT '結束層數: ' + CAST(@@NESTLEVEL AS CHAR)
GO

CREATE PROC 測試程序
AS
PRINT '層數: ' + CAST(@@NESTLEVEL AS CHAR)

EXEC 呼叫程序 '測試程序';

-- return value for stored procedure
/*
	Using RETURN or OUTPUT keyword
*/
CREATE PROC 新增課程 
	@c_no CHAR(5),
	@title VARCHAR(30),
	@credits INT
AS
BEGIN
	DECLARE @errorNo INT
	INSERT INTO 課程
		VALUES (@c_no, @title, @credits)
	SET @errorNo = @@ERROR
	IF @errorNo <> 0
	BEGIN
    	IF @errorNo = 2627
			PRINT '錯誤! 重複索引鍵!'
		ELSE
			PRINT '錯誤! 未知錯誤發生!'
		RETURN @errorNo
	END
END

-- exec procedure 
DECLARE @retVar int
EXEC @retVar = 新增課程
				@c_no = 'CS222'
				,@title = '資料庫程式設計'
				,@credits = 3;

PRINT '傳回代碼:' + CONVERT(VARCHAR, @retVar);

/* 
	Using output keyword which 
	allow store procedure getting returning value
*/
create PROC 薪水查詢
	@name varchar(12),
	@salary money OUTPUT
AS
BEGIN
	SELECT @salary = 薪水
	from 員工
	WHERE 姓名 = @name
END

EXEC 薪水查詢 @name= N'王心零',  @salary=50000;

/* 
	In following query, the keyword 'OUTPUT' is used to 
	store the output result.
*/
DECLARE @mySalary MONEY
EXEC 薪水查詢 '張無忌', @salary = @mySalary OUTPUT
PRINT N'Joe''s 薪水: ' + convert(varchar, @mySalary)


```