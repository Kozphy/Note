#mssql 

## what is grant
- The `GRANT` statement gives users access privileges to the database.
```sql
GRANT SELECT, UPDATE ON Customers TO user1;
```

## what is revoke
- The `REVOKE` statement removes previously granted permissions from users.
```sql
REVOKE DELETE, UPDATE ON Orders FROM user1;
```
