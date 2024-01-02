# mysql cmd

## connect

```cmd
mysql -u <user> -p <password>
```

## use

```sql
use <database>
```

## create

```sql
CREATE TABLE <table_name> (
    column1 <datatype>,
    column2 <datatype>,
    column3 <datatype>,
   ....
);
```

## select

show table column and type

```sql
SELECT column_name, data_type from INFORMATION_SCHEMA.COLUMNS where
table_schema = <"yourDatabaseName"> and table_name = <"yourTableName">;
```

## show

show all databases

```sql
show <databases>;
show schema;
```

show all tables

```sql
show tables;
```

show tables field constraints

```sql
SHOW CREATE TABLE <table_name>;
```

## update

```sql
update table_name SET column1=value1, column2=value2, ... WHERE condition;
```

### filter

```sql
show <databases> like 'pattern'
```

## alter

```sql
alter TABLE <table_name>
alter COLUMN <column_name> <datatype>
```

add primary key to table's field

```sql
alter table <table_name> add primary key (<column_name>)
```

## drop

```sql
DROP TABLE <table_name>;
```
