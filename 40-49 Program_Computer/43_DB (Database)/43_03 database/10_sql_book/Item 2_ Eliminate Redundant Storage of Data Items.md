###### tags: `sql book`

## what is redundant 
Redundant storage of data causes many problems, including inconsistent data; insert, update, and delete anomalies.

Normalization is a process that involves dividing information by subject to help eliminate problems associated with storing duplicate data.

We are more `concerned with` cases where `users enter the same piece of data in more than one place`.

Such redundancy is necessary to maintain the relational link between tables.

One goal of normalization is to `minimize the need to repeat data`, either in the same table or in different tables throughout a database.

![](https://i.imgur.com/Ee8mswt.png)



## splitting data into tables by subject
The customer sales data shown in **Figure 1.3** can logically be divided into four tables:
1. Customers table (name, address, etc.)
2. Employees table (salesperson name, hire date, etc.)
3. AutomobileModels table (model year, model, etc.)
4. SalesTransactions table

This design allows you to enter customer, employee, and automobile model information once into the respective tables. All tables include a unique identifier that can be set as a primary key. The **SalesTransactions** table uses foreign keys to store the details of each sales transaction. See **Figure 1.4**.

![](https://i.imgur.com/DdSnN6V.png)



## Things to Remember
- A goal of database normalization is the `elimination of redundant data and minimizing resource use when processing data`.
- By eliminating redundant data, you eliminate insert, update, and delete anomalies.
- By eliminating redundant data, you minimize the occurrence of inconsistent data.
