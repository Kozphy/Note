#database 


## example
- `Mo Binni is managed by m1`  = foreign key references the primary key.
![](Pasted%20image%2020240509155027.png)

## create table with constraint
```sql
-- Creating the Employees table with a primary key
CREATE TABLE Employees (
    id INT PRIMARY KEY,
    firstName VARCHAR(50),
    lastName VARCHAR(50),
    sex char(1),
    dob DATE,
    email VARCHAR(100),
    managerId VARCHAR(10),
	FOREIGN KEY (managerId) 
	REFERENCES Managers(managerId)
);

-- Creating the Managers table with a primary key
CREATE TABLE Managers (
    managerId VARCHAR(10) PRIMARY KEY,
    firstName VARCHAR(50),
    lastName VARCHAR(50),
	sex char(1)
);
```

## add constraint  not during the creation of the database
```sql
-- Adding a foreign key constraint to the Employees table
ALTER TABLE Employees
ADD CONSTRAINT FK_Manager
FOREIGN KEY (managerId) REFERENCES Managers(managerId);
```