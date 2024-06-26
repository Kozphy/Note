#mssql 

## Source
https://medium.com/codestorm/stored-procedure-vs-function-1011a23bd8b1#:~:text=The%20main%20purpose%20of%20stored,%2C%20update%2C%20and%20delete%20data.&text=Functions%20improve%20the%20performance%20and,compiled%20and%20cached%20before%20use.

## Stored Procedure
`Stored Procedures are pre-compiled objects` which are compiled for the first time and their compiled format is saved, which executes (compiled code) whenever it is called.
```sql
CREATE PROCEDURE SelectAllCustomers
    @City NVARCHAR(30),
    @PostalCode NVARCHAR(10)
AS
BEGIN
    SELECT *
    FROM Customers
    WHERE City = @City AND PostalCode = @PostalCode;
END;
```
## Function
`A function is compiled and executed every time whenever it is called`. A function must return a value and cannot modify the data received as parameters.
```sql
CREATE FUNCTION CalculateSquare (@input_number INT)
RETURNS INT
AS
BEGIN
    RETURN @input_number * @input_number;
END;
```
