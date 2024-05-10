#database 

## Source
[sql - Storing sex (gender) in database - Stack Overflow](https://stackoverflow.com/questions/4175878/storing-sex-gender-in-database)

```sql
Data Type   Bytes Taken          Number/Range of Values
------------------------------------------------
TinyINT     1                    255 (zero to 255)
INT         4            -       2,147,483,648 to 2,147,483,647
BIT         1 (2 if 9+ columns)  2 (0 and 1)
CHAR(1)     1                    26 if case insensitive, 52 otherwise
```

## ## Conclusion
using `char(1)` for gender