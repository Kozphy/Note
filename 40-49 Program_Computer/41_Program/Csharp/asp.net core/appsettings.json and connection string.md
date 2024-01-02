#csharp 
## Source
https://stackoverflow.com/questions/17615260/the-certificate-chain-was-issued-by-an-authority-that-is-not-trusted-when-conn
[SQL Server connection strings - ConnectionStrings.com](https://www.connectionstrings.com/sql-server/)

## appsettings.json
```json
{
  "Logging": {
    "LogLevel": {
      "Default": "Information",
      "Microsoft.AspNetCore": "Warning"
    }
  },
  "AllowedHosts": "*",
  "ConnectionStrings": {
    "DefaultConnection": "Server=localhost;Database=northwind;Integrated Security=True;Trusted_Connection=True;TrustServerCertificate=True"
  }
}
```
## **Server**
-  The name of the server that `hosts the database`. In this case, the server is **localhost**.
## **Database**
- The name of the database that `you want to connect to`. In this case, the database is **northwind**.
## **Integrated Security**
- This parameter specifies whether to use `Windows Authentication or SQL Server Authentication`. 
	- When set to **True**, it uses `Windows Authentication`. 
	- When set to **False**, it uses `SQL Server Authentication`.
## **Trusted_Connection**
- This parameter is used to specify whether to use `Windows Authentication` to connect to the database. 
	- When set to **True**, it uses `Windows Authentication`. 
	- When set to **False**, it uses `SQL Server Authentication`.
## **TrustServerCertificate**
-  This parameter is used to specify whether to trust the server certificate when using `SSL encryption`. 
	- When set to **True**, it `trusts` the `server certificate`. 
	- When set to **False**, it `does not trust the server certificate`.
## **Integrated Security**
It is used to specify whether to use Windows Authentication or SQL Server Authentication. 
	- When set to `True`, it uses `Windows Authentication`.
	- [When set to `False`, it uses SQL Server Authentication](https://stackoverflow.com/questions/1642483/when-using-trusted-connection-true-and-sql-server-authentication-will-this-affe) [1](https://stackoverflow.com/questions/1642483/when-using-trusted-connection-true-and-sql-server-authentication-will-this-affe).

## Trusted_Connection
It is used to specify whether to use Windows Authentication to connect to the database. 
	- When set to `True`, it uses Windows Authentication. 
	- [When set to `False`, it uses SQL Server Authentication](https://stackoverflow.com/questions/1642483/when-using-trusted-connection-true-and-sql-server-authentication-will-this-affe) [1](https://stackoverflow.com/questions/1642483/when-using-trusted-connection-true-and-sql-server-authentication-will-this-affe).

## The relation of `Integrated Security` and `Trusted_Connection`
[If you set `Integrated Security` to `True`, then `Trusted_Connection` is automatically set to `True` as well](https://stackoverflow.com/questions/1642483/when-using-trusted-connection-true-and-sql-server-authentication-will-this-affe) [1](https://stackoverflow.com/questions/1642483/when-using-trusted-connection-true-and-sql-server-authentication-will-this-affe).

[If you set `Integrated Security` to `False`, then you can set `Trusted_Connection` to either `True` or `False` depending on whether you want to use Windows Authentication or SQL Server Authentication](https://stackoverflow.com/questions/1642483/when-using-trusted-connection-true-and-sql-server-authentication-will-this-affe) [1](https://stackoverflow.com/questions/1642483/when-using-trusted-connection-true-and-sql-server-authentication-will-this-affe).