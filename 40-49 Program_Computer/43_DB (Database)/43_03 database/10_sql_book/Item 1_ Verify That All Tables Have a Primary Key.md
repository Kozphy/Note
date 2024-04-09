# Item 1: Verify That All Tables Have a Primary Key
###### tags: `sql book`
## Things to Remember
- `All tables should have` a column (or set of columns) designated as a `primary key`.
- If you are concerned about `duplicate values in a non-key column`, you can define a `unique index` on the column to ensure integrity.
- `Use as simple a key` as possible, with values that do `not need to be updated`.
## Content
When tables lack primary keys, all kinds of problems can ensue, including `repeated and inconsistent data, slow-running queries, and inaccurate information` in reports!
![](https://i.imgur.com/qVNClMi.png)

**In Figure 1.1**, all the values are certainly unique from a computer perspective, but it might be the case that they are all the same person, or at least rows 1, 2, and 4 are the same.

what makes a good candidate for a `primary key`? The column(s) considered should have the following characteristics.
- Must hold unique values 
- Can never be null 
- Should be stable (i.e., there is no need to ever update the value)
- Should be as simple as possible (e.g., use an integer data type rather than floating point or character, and prefer a single column over multiple columns)

A common method of achieving this goal is to use an automatically generated meaningless numeric data value as a primary key. This has various names, depending on the relational database management system (RDBMS) software that you are using, such as *IDENTITY* in IBM DB2, Microsoft SQLServer, and Oracle 12c, *AutoNumber* in Microsoft Access, *AUTO_INCREMENT* in MySQL, and *serial* in PostgreSQL.

> We also advise `against using compound primary keys` because they are less efficient, for two reasons:
> 1. When you define a primary key, most database systems enforce the definition with a unique index. A unique index on more than one column requires the database system to do more work.
> 2. Performing a join on a primary key is quite common, but doing so on multiple columns in a primary key is more complex and slower.


