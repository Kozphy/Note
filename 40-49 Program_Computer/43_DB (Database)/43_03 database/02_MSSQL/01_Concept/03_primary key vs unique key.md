#mssql 

## Summary
- A `primary key` is used to enforce entity integrity and `uniquely identify` rows.
- A `unique key` ensures uniqueness but `allows NULL values` and can be used for columns other than the primary key.
## Primary key
- A **primary key** is a column in a table that **uniquely identifies each tuple (row)** in that table.
- Key features of a primary key:
    - **No duplicate rows**: Each value in the primary key column must be unique.
    - **NOT NULL constraint**: Primary keys cannot have NULL values.
    - **Single primary key per table**: Only one primary key is allowed in a table.
    - **Referenced by foreign keys**: The primary key of one table can be referenced by the foreign key of another table.

## Unique key
- A **unique key** also identifies an individual tuple uniquely in a relation or table.
- Key features of a unique key:
    - **Multiple unique keys per table**: Unlike primary keys, a table can have more than one unique key.
    - **Accepts one NULL value**: Unique key constraints allow only one NULL value for the column.
    - **Referenced by foreign keys**: Unique keys can also be referenced by the foreign key of another table.
    - **Not necessarily the primary key**: Unique keys can enforce uniqueness on columns other than the primary key.