#csharp 

## LinqPad intro
- linqpad 沒辦法直接把檔案編譯成 `.exe` 檔
- 所有 code 都要寫在一個檔案裏面
- `linqpad 2 ~ 5 `以 `.net framework` 為基礎
- `linqpad 6 ~ 8` 以 `.net core 3.1 ~ .net 8.0` 為基礎
## LinqPad data context driver
### What is this?
- component of linqpad that enables you to connect to a specfic data source, such as a database or web service.
### built-in
- LINQPad comes with several built-in data context drivers for popular databases such as `SQL Server`, `Oracle`, `MySQL`, and `PostgreSQL`.

## 序號
- linqpad 8 的序號可以往前相容，v2、v3、... v8
- 最多可以安裝在三台機器上

## UI or shortcut
- `Ctrl + ,` search query file with name.
- `Ctrl + shift + F` can search file content for `Query` and `Sample`.

## Support Language
- [Primary Expression]([C# in a Nutshell - Code Listings (albahari.com)](https://www.albahari.com/nutshell/E12-CH02.aspx)) 
```Csharp
// This is a primary expression. Notice the "Language" dropdown above is set to "Expression" - this
// allows a pure expression to execute in LINQPad without extra baggage:

Math.Log(1)
```
### statement
- [Statement](https://www.programiz.com/csharp-programming/expressions-statements-blocks) => method
```Csharp
// You may declare multiple variables of the same type in a comma-separated list:

string someWord = "rosebud";
int someNumber = 42;
bool rich = true, famous = false;
```

- Program => multiple method
## lambda
![](Pasted%20image%2020240114162625.png)
LINQ query syntax => LINQ method syntax
- 只有搜尋 db 才會有用

## Data context
- [LINQ to SQL]([What You Can Do With LINQ to SQL - ADO.NET | Microsoft Learn](https://learn.microsoft.com/en-us/dotnet/framework/data/adonet/sql/linq/what-you-can-do-with-linq-to-sql)) (optimized for SQL Server)
	- 
- [Entity Framework Core]([Overview of Entity Framework Core - EF Core | Microsoft Learn](https://learn.microsoft.com/en-us/ef/core/)) (multi-provider) => DBFirst
		- Model

> [entity framework vs LINQ to SQL](https://stackoverflow.com/questions/8676/entity-framework-vs-linq-to-sql)