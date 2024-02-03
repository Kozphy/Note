#sql
## Source 
### bingGPT
[sql server - What is the use of mdf and ldf in sql? - Stack Overflow](https://stackoverflow.com/questions/36114669/what-is-the-use-of-mdf-and-ldf-in-sql)
[5 Basic Facts about MDF and LDF files in SQL Server (datanumen.com)](https://www.datanumen.com/blogs/5-basic-facts-mdf-ldf-files-sql-server/)
## `.mdf`
The **.mdf** file is the `primary data` file that contains all the main information about the database, such as tables, functions, stored procedures, views, and more.
- It contains all the main information of the database that is part of the server.
- It plays a crucial role in information storage.

## `.ldf`
**.ldf** file stores changes related to `inserts, deletions, updates, and additions`,

| **.mdf** file                                        | **.ldf** file                                                              | 
| ---------------------------------------------------- | -------------------------------------------------------------------------- |
| Contains all the main information about the database | Stores changes related to inserts, deletions, updates, and additions, etc. |
| Primary data file                                    | Transaction log file                                                       |
| Stores user data                                     | Stores transaction logs                                                    |
| Can be backed up and restored                        | Can be truncated to free up space                                          |
| Can be moved to a different location                 | Cannot be moved to a different location                                    |