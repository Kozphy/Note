#mssql 

## String Comparison (=)
```sql
select 'apple' = 'apple' -- Result: 1 (True)
```

## String Concatenation (+)
```sql
select 'Hello, ' + 'world!';
```

## String Concatenation Assignment (+=)
```sql
declare @message nvarchar(100) = 'Hello, ';
set @message += 'world!';
select @message;a -- Result: 'Hello, world!'
```

## Wildcard Characters
### `%`: Matches any sequence of characters
```sql
select 'apple' like 'a%'; -- Result: 1 (True)
```

### `__ `: Matches any single character
```sql
select 'cat' like '_at'; -- Result: 1 (True)
```

### `[]`: Specifies a character set to match
```sql
select 'dog' like '[cd]og'; -- Reulst (True) (matches 'dog' or 'cog')
```

### `[^]` Specifies a character set not to match
```sql
select 'bat' like '[^cd]at'; -- Result: 1 (True) (matches 'bat' but not 'cat' or 'dat')
```
