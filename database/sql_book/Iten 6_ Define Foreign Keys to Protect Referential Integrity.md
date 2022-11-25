# Iten 6: Define Foreign Keys to Protect Referential Integrity
###### tags: `sql book`
![](https://i.imgur.com/i7Bf7U0.png)

The key symbol on one end of each relationship line indicates that the relationship is from the primary key of one table, and the infinity symbol on the other end of the line indicates a “many” relationship to a foreign key in the second table.

These relationship definitions serve two purposes:
- The graphical query designer for the database knows how to correctly construct **JOIN** clauses when you use the designer to create a new view or stored procedure.
- The database system knows how to enforce data integrity when inserting or changing a table on the “many” side of a relationship or changing or deleting a table on the “one” side of a relationship.

To enable this important feature in your database system, you need to add a **FOREIGN KEY** constraint either when you define a “many” table using **CREATE TABLE**, or by adding the constraint after the fact using **ALTER TABLE**.

First, let’s create the Customers table. **Listing 1.9** shows how.
![](https://i.imgur.com/ixqLbA1.png)

Next, let’s create the **Orders** table and then execute an **ALTER TABLE** to define the relationship. **Listing 1.10** shows how.
![](https://i.imgur.com/0RbFwlt.png)

>**Note**
>if you first create the two tables, add data to both of them, and then decide to add the **FOREIGN KEY** constraint, your attempt to alter the **Orders** table might fail if data in the tables fails the referential integrity check.

You can also define the constraint when you create the child table. **Listing 1.11** shows how.
![](https://i.imgur.com/ESnwBN5.png)

On some database systems (notably Microsoft Access), defining a referential integrity constraint automatically creates an index on the foreign key column(s), so there may be an added performance benefit when performing a join. For those database systems that do not automatically create an index on a foreign key (such as DB2), **it is good practice to create an index to optimize constraint checking**.

## Things to Remember
- Making foreign keys explicit helps ensure data integrity between related tables by ensuring that no child row exists without a matching parent row.
- Attempting to add a **FOREIGN KEY** constraint to tables that contain data will fail if data exists that violates the constraint.
- In some systems, the performance of joins may be improved because defining a **FOREIGN KEY** constraint automatically builds indexes. On other systems, you must take care to create an index to cover the **FOREIGN KEY** constraint. Even without indexes, some systems’ optimizer may treat a column differently and produce better query plans.

