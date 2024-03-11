#mssql
## syntax
```sql
column data_type NOT NULL FOREIGN KEY REFERENCES table_name(column) -- foreign key
```

### syntax
```sql
create table database_name ( [column_name] {type} references {table_name} {(table_column_name)}, foregin key (current_table_column_name1, current_table_column_name2) reference table_name (column_name, column_name) )
```

#### implement
```sql
FOREIGN KEY (PersonID) REFERENCES Persons(PersonID)
```

## foreign key with name
### syntax
```csharp
CONSTRAINT FK FOREIGN KEY (PersonID)  
    REFERENCES Persons(PersonID)
```
### implement
```sql

```

