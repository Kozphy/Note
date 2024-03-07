#mssql 

## 資料庫伺服器管理分為兩種
1. 使用者定義的資料庫 (User-defined Databases)
2. 系統資料庫 (System Databases)

## 系統資料庫
- `master`
	-  master 紀錄執行個體的所有系統層級的資訊
- `model`
	- 建立 SQL Server 使用者資料庫的範本，內含使用者資料庫的基本關聯表和相關系統物件 
- `msdb` 資料庫 
	- SQL Server 代理程式 (SQL Server Agent)
		- 儲存警示(Alert)
		- 作業 (Jobs)
		 	- SQL Server Integration Services 的封裝、資料庫備份還原記錄、複寫和維護計畫等資訊
- `tempdb`
	- 儲存目前 SQL Server 執行所需的暫存資料，包含所有暫存資料表和預存程序
- `Resource` 
	- 唯讀且隱藏的資料庫，必須和 master資料庫在同一個路徑。在 Management Studio 無法直接檢視 Resource 資料庫，資料檔名稱是 `mssqlsystemresource.mdf`; 交易紀錄檔是 `mssqlsystemresource.ldf`
	- The Resource database makes upgrading to a new version of SQL Server an easier and faster procedure.

## 資料庫物件
- 資料庫圖表 (Database Chart)
- 資料表 (Table)
- 檢視 (View)
- 同義字 (Synonym)
- 可程式性 (Programmability)
	- 預存程序 (Stored procedure)
	- 函數 (Function)
	- 資料庫觸發程序 (Database trigger)
	- 規則 (Rule)
	- 預設值 (Default vaule)
	- 順序 (Sequence)
- 儲存體 (Storage)
- 安全性 (Security)
	- 使用者 (User)
	- 角色 (Role)
	- 結構描述 (Schema)
	- 非對稱金鑰 (Asymmetric key)
	- 憑證 (Certificate)
	- 對稱金鑰 (Symmetric key)