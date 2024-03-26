#mssql 

## Source
https://stackoverflow.com/questions/1307990/why-use-the-include-clause-when-creating-an-index


## Content
If the column is not in the `WHERE/JOIN/GROUP BY/ORDER BY`, but only in the column list in the `SELECT` clause is where you use `INCLUDE`.

The `INCLUDE` clause adds the data at the lowest/leaf level, rather than in the index tree. This makes the index smaller because it's not part of the tree

`INCLUDE columns` are not key columns in the index, so they are not ordered. This means it isn't really useful for predicates, sorting etc as I mentioned above. However, it _may_ be useful if you have a residual lookup in a few rows from the key column(s)