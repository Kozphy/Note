#ODBC

## Source
[Connection encryption troubleshooting - ODBC Driver for SQL Server | Microsoft Learn](https://learn.microsoft.com/en-us/sql/connect/odbc/connection-troubleshooting?view=sql-server-ver16)

## issue
![](Screenshot%202024-02-06%20130048.png)



## Certificate chain errors
Connection encryption is enabled by default in version 18 and newer.
### Error
- "SSL Provider: `The certificate chain was issued by an authority that is not trusted."` 
- "SSL routines::certificate verify failed: unable to get local issuer certificate" in your error

### resolve
- Users can choose to set the `Encrypt` connection string keyword to `no`/`optional` to disable connection encryption

-  If connection encryption is desired, `TrustServerCertificate` can also be set to `yes` to skip server certificate validation.

![](Pasted%20image%2020240206132906.png)