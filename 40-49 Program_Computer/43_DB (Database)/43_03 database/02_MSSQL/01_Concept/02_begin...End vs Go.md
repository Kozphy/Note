#mssql 

## From GPT
- **BEGIN/END** defines code blocks within T-SQL.
- **GO** separates batches for execution in client tools. Choose the appropriate one based on your needs!

## begin...end
```sql
set nocount on
declare @i int = 2
if(@i >= 2)
begin
	set @i=@i+1
	print @i
	set @i = @i + 2
	print @i
end
```

