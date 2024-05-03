#mssql 

## Source
https://www.sqlshack.com/understanding-sql-server-backup-types/

## Full backups
A full backup, as the name implies, `backs up everything`. It is the foundation of any kind of backup.

This is a complete copy, which stores all the objects of the database: `Tables, procedures, functions, views, indexes etc`. 

Having a full backup, you will be able to easily restore a database in exactly the same form as it was at the time of the backup.
### example of full backups
- `with format`: it is used to overwrite the existing media set information.
- `medianame`: 
- `name`:
```sql
BACKUP DATABASE [SQLShackDemoATC]
To DISK='f:\PowerSQL\SQLShackDemoATC.BAK'
WITH FORMAT,
      MEDIANAME = 'Native_SQLServerBackup',
      NAME = 'Full-SQLShackDemoATC backup';
```
## Differential


## Transaction log

## Tail Log backup

## Copy-only backup

## File backups

## Partial backups 