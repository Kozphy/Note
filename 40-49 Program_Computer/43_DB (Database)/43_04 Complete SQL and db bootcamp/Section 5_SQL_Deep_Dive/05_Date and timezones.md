#database 

## TimeStamp
```sql
SELECT
	SYSDATETIME() as datetime
   ,SYSDATETIMEOFFSET()
   ,SYSUTCDATETIME() as sysUtcTimestamp
   ,CURRENT_TIMESTAMP as timestamp
   ,GETDATE() as date
   ,GETUTCDATE() as utcdate;
```

## CURRENT_TIMEZONE()
```sql
SELECT
	CURRENT_TIMEZONE();
```