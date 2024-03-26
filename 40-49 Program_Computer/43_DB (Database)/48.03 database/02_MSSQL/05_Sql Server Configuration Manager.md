#mssql 

![](Pasted%20image%2020240125145504.png)

- `SQL Server Services`: 伺服器提供的服務清單
- `SQL Server Network Configuration`:  


![](Pasted%20image%2020240125152250.png)
- `共用記憶體 (Shared Memory)`: 只可以在同一台電腦連線到 SQL Server instance，不適用多個 database.
- `具名管道 (Named Pipes)`:  `UNIX` 作業系統的管道概念，用戶端是 `IPC (inter-process Communication)` 來連線 SQL Server 執行個體
- `TCP/IP`: `Internet` 網際網路使用的通訊協定，可以讓不同硬體架構和作業系統的遠端電腦使用 `IP 位址`來連線 `SQL Server 執行個體`。

