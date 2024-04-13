#mssql 

- [[#original procedure|original procedure]]
	- [[#original procedure#Execute|Execute]]
- [[#alter procedure|alter procedure]]

## original procedure
```sql
CREATE PROCEDURE GetEmployee @EmployeeID INT
AS
SELECT * FROM Employees WHERE EmployeeID = @EmployeeID;
```

### Execute
```
EXEC GetEmployee @EmployeeID = 123;
```

## alter procedure
```sql
ALTER PROCEDURE GetEmployee @EmployeeID INT, @DepartmentID INT
AS
SELECT * FROM Employees WHERE EmployeeID = @EmployeeID AND DepartmentID = @DepartmentID;
```
