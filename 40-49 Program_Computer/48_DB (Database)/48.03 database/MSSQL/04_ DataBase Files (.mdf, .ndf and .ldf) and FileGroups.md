#sql
## Source 
### bingGPT
[sql server - What is the use of mdf and ldf in sql? - Stack Overflow](https://stackoverflow.com/questions/36114669/what-is-the-use-of-mdf-and-ldf-in-sql)

[5 Basic Facts about MDF and LDF files in SQL Server (datanumen.com)](https://www.datanumen.com/blogs/5-basic-facts-mdf-ldf-files-sql-server/)

## Database Files
### `.mdf` (Primary)
The **.mdf** file is the `primary data` file that contains all the main information about the `database`, such as `tables`,`functions`, `stored procedures`, `views`, and more.
- It contains all the main information of the database that is part of the server.
- It plays a crucial role in information storage.
- Every database has one primary data file.

### `ndf` (Secondary)
Optional user-defined data files. Data can be spread across multiple disks by putting each file on a different disk drive.

### `.ldf` (Transaction Log)
**.ldf** holds information used to recover the database. There must be at least one log file for each database.

| **.mdf** file                                        | **.ldf** file                                                              | 
| ---------------------------------------------------- | -------------------------------------------------------------------------- |
| Contains all the main information about the database | Stores changes related to inserts, deletions, updates, and additions, etc. |
| Primary data file                                    | Transaction log file                                                       |
| Stores user data                                     | Stores transaction logs                                                    |
| Can be backed up and restored                        | Can be truncated to free up space                                          |
| Can be moved to a different location                 | Cannot be moved to a different location                                    |

## Logical and Physical FIle Names
### SQL Server files have two file name types:
- `logical_file_name`: 
- `os_file_name`:

## Data File Pages

## 檔案群組 (Filegroups)
### Why we need fileGroups
1. **Data Organization and Placement**:
2. **Backup and Restore Strategy**: