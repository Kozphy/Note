#sql

- [[#Source|Source]]
	- [[#Source#SQLShack|SQLShack]]
	- [[#Source#bingGPT|bingGPT]]
- [[#Database Files|Database Files]]
	- [[#Database Files#`.mdf` (Primary)|`.mdf` (Primary)]]
	- [[#Database Files#`.ndf` (Secondary)|`.ndf` (Secondary)]]
	- [[#Database Files#`.ldf` (Transaction Log)|`.ldf` (Transaction Log)]]
- [[#Logical and Physical FIle Names|Logical and Physical FIle Names]]
	- [[#Logical and Physical FIle Names#[SQL Server files have two file name types]([Renaming Logical and Physical file names in SQL Server on Linux (sqlshack.com)](https://www.sqlshack.com/renaming-logical-and-physical-file-names-in-sql-server-on-linux/)):|[SQL Server files have two file name types]([Renaming Logical and Physical file names in SQL Server on Linux (sqlshack.com)](https://www.sqlshack.com/renaming-logical-and-physical-file-names-in-sql-server-on-linux/)):]]
- [[#Data File Pages|Data File Pages]]
- [[#檔案群組 (Filegroups)|檔案群組 (Filegroups)]]
	- [[#檔案群組 (Filegroups)#Why we need fileGroups|Why we need fileGroups]]
- [[#how to change the file path for a SQL Server database?|how to change the file path for a SQL Server database?]]
	- [[#how to change the file path for a SQL Server database?#Set new file path|Set new file path]]

## Source 
### SQLShack
[How to move SQL database files (MDF and LDF) to another location](https://www.sqlshack.com/move-sql-database-files-mdf-ldf-another-location/)

### bingGPT
[sql server - What is the use of mdf and ldf in sql? - Stack Overflow](https://stackoverflow.com/questions/36114669/what-is-the-use-of-mdf-and-ldf-in-sql)

[5 Basic Facts about MDF and LDF files in SQL Server (datanumen.com)](https://www.datanumen.com/blogs/5-basic-facts-mdf-ldf-files-sql-server/)

## Database Files
### `.mdf` (Primary)
The **.mdf** file is the `primary data` file that contains all the main information about the `database`, such as `tables`,`functions`, `stored procedures`, `views`, and more.
- It contains all the main information of the database that is part of the server.
- It plays a crucial role in information storage.
- Every database has one primary data file.

### `.ndf` (Secondary)
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
### [SQL Server files have two file name types]([Renaming Logical and Physical file names in SQL Server on Linux (sqlshack.com)](https://www.sqlshack.com/renaming-logical-and-physical-file-names-in-sql-server-on-linux/)):
- `logical_file_name`
- `physical_file_name`
![](Pasted%20image%2020240228152321.png)
## Data File Pages

## 檔案群組 (Filegroups)
### Why we need fileGroups
1. **Data Organization and Placement**:
2. **Backup and Restore Strategy**:

## how to change the file path for a SQL Server database?
### Set new file path
```sql
USE master;
ALTER DATABASE [教務系統]
MODIFY FILE (NAME = [教務系統_Data], FILENAME = 'E:\New_location\教務系統_Data.mdf');
ALTER DATABASE [教務系統]
MODIFY FILE (NAME = [教務系統_Log], FILENAME = 'E:\New_location\教務系統_Log.ldf');

```
- `NAME = [教務系統_Data]`: This specifies the `logical name` of the file within the database.
- `FILENAME = 'E:\New_location\教務系統_Data.mdf'`: This specifies the `new physical path and filename` for the database file.


