#mssql 

## GETDATE
```sql
select getdate();
-- result example: 2024-05-12 19:50:37.000
```

## DATEADD
```sql
select DATEADD(year, 1, '2024/01/25') as DateAdd;
-- result example: 2025-01-25 00:00:00.000
```