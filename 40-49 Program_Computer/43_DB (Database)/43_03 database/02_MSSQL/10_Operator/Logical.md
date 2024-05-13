#mssql 

![](Pasted%20image%2020240512194427.png)
## AND
```sql
select first_name, last_name
from Customers
where country= 'USA' AND last_name='Luna';
```
## OR
```sql
select first_name, last_name
from Customers
where country='USA' OR last_name='Luna';
```

## NOT
```sql
select first_name, last_name
from Customers
where not country='USA';
```

## LIKE
```sql
select first_name, last_name
from Customers
where country like 'UK';
```

