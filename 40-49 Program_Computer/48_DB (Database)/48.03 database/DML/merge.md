#mssql 

## Source
https://www.sqlshack.com/understanding-the-sql-merge-statement/#:~:text=The%20MERGE%20statement%20in%20SQL,update%2C%20or%20delete%2C%20etc.


```sql
MERGE TargetProducts AS Target
USING SourceProducts AS Source
ON Source.ProductID = Target.ProductID

-- For Inserts
WHEN NOT MATCHED BY Target THEN
    INSERT (ProductID,ProductName, Price)
    VALUES (Source.ProductID,Source.ProductName, Source.Price)

-- For Updates
WHEN MATCHED THEN UPDATE SET
    Target.ProductName = Source.ProductName,
    Target.Price = Source.Price

-- For Deletes
WHEN NOT MATCHED BY Source THEN
    DELETE
```

- `when matched`: 當目標和來源資料表符合 `ON` 子句條件，就執行此子句的內容
- `when not matched [by target]`: 此子句的 `By target` 可有可無，紀錄存在`來源資料表`，但是`不存在目標資料表`
- `when not matched by source`: 紀錄存在`目標資料表`；但是`不存在來源資料表`，通常在此子句是針對目標資料表執行 update and delete 指令
