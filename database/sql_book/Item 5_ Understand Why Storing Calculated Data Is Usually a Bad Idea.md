# Item 5: Understand Why Storing Calculated Data Is Usually a Bad Idea
###### tags: `sql book`

## Why storing calculated data is bad idea
You might sometimes be tempted to store calculated data, especially when the calculation depends on data in a related table. Consider the example in **Listing 1.5**.
![](https://i.imgur.com/Nfbjt5n.png)

The most primitive way to ensure that a calculated column remains current is to attach a trigger to the table containing the source columns for the calculation. 

A trigger is code you write that runs when the target table is inserted, updated, or deleted.

But triggers can be expensive and difficult to write correctly.

Potentially better than triggers, several database systems give you a method for **defining a calculated column** when you create the table.

We say this is better than triggers because defining the calculated column as part of the table definition can avoid the complex code often required in a trigger.

Several RDBMSs, especially in more recent versions, already support defining a calculated column. For instance, **Microsoft SQLServer** gives you the **AS** keyword followed by an expression that defines the computation you require.

**Listing 1.6** shows a sample function and table definition using Microsoft SQLServer.

> Note that because the function depends on data from another table, it is nondeterministic, so you cannot build an index on the calculated field.

> **Deterministic versus Nondeterministic**
> **A deterministic function** is one that always returns the same result any time it is called with a specific set of input values. 
> **A nondeterministic function** may return different results each time it is called with a specific set of input values.

![](https://i.imgur.com/913CGIC.png)
![](https://i.imgur.com/4narHIM.png)

It is actually a very bad idea to do it this way. Because the function is nondeterministic, the column cannot be PERSISTED as a real column in the table.

**In IBM DB2**, there is a similar facility, but the keyword is GENERATED.

If you want to have a calculated column **in Oracle** (called a “virtual column”), use **GENERATED [ALWAYS] AS**. 
https://github.com/TexanInParis/Effective-SQL/blob/master/MySQL/Chapter%2001/Listing%201.008.sql

**Now for the bad news: if this table is meant to be used in a high-volume online data entry system, adding a calculated column like this may result in significant overhead on the server that can negatively affect response times.**

Remember that you won’t be able to create an index on the example from **Listing 1.6** in SQLServer (nor could you for other database systems) because it is **nondeterministic**.

## Things to remember
- Many systems let you define calculated columns when you define your table, but you need to be aware of the performance implications, particularly when using nondeterministic expressions or functions.
- You can also define calculated columns as regular columns and then maintain them with triggers, but the code to do so may be complex.
- Calculated columns cause additional overhead in your database system, so use them only when the benefits outweigh the costs. Most of the time, you will want to create an index on the calculated columns to reap some benefits in exchange for increased storage and slower updates.
- Using views to define calculations is often a desirable alternative to actually storing calculations on a table for cases where indexing does not apply.