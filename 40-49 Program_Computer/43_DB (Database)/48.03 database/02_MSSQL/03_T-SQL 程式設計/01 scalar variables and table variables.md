#mssql 

## 變數值的種類
- `純量變數 (Scalar variables)`: 一種儲存標準資料類型的單一值，在之前宣告的變數都是一種純量變數
- `資料表變數 (Table Variables)`: 一種儲存整個資料表內容的變數，我們可以在資料表變數使用 select 、insert、update、delete 指令，視為標準資料表來使用
```sql
-- declare students
DECLARE @students TABLE
(std_no CHAR(4), name VARCHAR(12))

INSERT @students
SELECT 學號, 姓名 FROM 學生
WHERE 性別 = '男';

SELECT * FROM @students
```

## 變數的範圍
```sql

```