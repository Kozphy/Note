# Item 7: Be Sure Your Table Relationships Make Sense
###### tags: `sql book`

![](https://i.imgur.com/LTTXgzQ.png)

Let’s focus on three of the tables: **Employees**, **Customers**, and **Vendors**. If you study those three tables, you will see that they have lots of similar fields. Many times this is not perceived to be a problem because the data in the three tables is usually distinct.

But if this company could have vendors or employees who are also the customers of the company, this model **violates the rules against duplicating data**.

It would be better to have a table called **SalesTerritory** that has a foreign key of **EmployeeID**, and the rows in the table would identify the **ZIP codes (TerrZIP)** assigned to that employee. Each ZIP code would be unique within the **SalesTerritory** table because you would not want to assign a ZIP code to more than one employee. It would then be valid to create a relationship from **TerrZIP** to the **Customers** table so that an employee could discover which customers are in his or her territory.

A similar problem exists when the company needs to list all products it sells but also provide detailed data on each product and all of its attributes.

**Listing 1.12** illustrates a possible design for the tables. This is often referred to as the **“entity-attribute-value” or EAV model**.

![](https://i.imgur.com/mIwsxM6.png)

## Things to Remember

- Carefully examine whether it really makes sense to combine tables that appear to contain similar columns in order to simplify relationships.
- You can create a join between columns in two tables as long as the data types match (or can be implicitly casted), but a relationship is valid only if the columns are in the same domain. However, it is optimal to have the same data types on both sides of the join.
- Check whether you are in fact dealing with structured data before including it in your data model. If the data is semistructured, make the necessary provisions.
- It is usually helpful to clearly identify the goals of a data model to help you assess whether a given design justifies the added complexity or anomalies due to simplifications and the design of the applications using the data model.