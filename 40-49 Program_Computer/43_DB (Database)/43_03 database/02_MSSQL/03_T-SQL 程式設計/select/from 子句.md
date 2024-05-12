#mssql 

## from 子句可以使用的資料表種類
- 長存資料表 (`Permanent Tables`)
- 暫存資料表 (`Temporary Tables`): 以 `#` 或 `##` 開頭的資料表，由子查詢取得中間結果紀錄資料的暫存資料表
- 檢視表 (`Views`): 一種建立在長存資料表上的虛擬資料表

## T-SQL 函數
- `LEFT()`
- `CONVERT()`
- `GETDATE()`
- `DATEDIFF()`

## like
`%`: 代表 0 或更多任意長度字元的任何字串
`_`: 代表一個字元長度的任何字元
`[]`: 符合括號內字元清單的任何一個字元，ex: `[EO]`
`[-]`: 符合括號內 `-` 字元範圍的任何一個字元，ex:`[A-J]`
`[^]`: 符合不在括號內字元清單的字元，ex: `[^K-Y]`


## 聚合函數(aggregate function)
- `MIN()` - returns the smallest value within the selected column
- `MAX()` - returns the largest value within the selected column
- `COUNT()` - returns the number of rows in a set
- `SUM()` - returns the total sum of a numerical column
- `AVG()` - returns the average value of a numerical column



