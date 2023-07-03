# Item 3: Get Rid of Repeating Groups
###### tags: `sql book`

## what is repeating group
An example of repeating groups of data is shown in Figure 1.6, with a **DrawingNumber** being associated with up to five **Predecessors**. The table has a one-to-many relationship between drawing numbers and predecessor values.
![](https://i.imgur.com/2eEWWqw.png)


The example in **Figure 1.6** shows a single attribute, **Predecessor**, as a repeat

If you were to see columns named **Quantity1, ItemDescription1, Price1, Quantity2,
ItemDescription2, Price2 . . . QuantityN, ItemDescriptionN, PriceN**, you
should recognize them as a repeating group pattern.

## repeating group defect
In the example in **Figure 1.6**, if you later had a need to add *Predecessor* values or reduce the number of allowed *Predecessors*, the current design would require adding or removing table columns.

You would also need to modify the design of all queries (views), forms, and reports that depend on the data in this table. 

## focal point
A useful mnemonic to remember is:
- Columns are expensive.
- Rows are cheap.

A red flag should be raised in your mind if the table design requires adding or removing columns to accommodate future data requirements with similar data.

A much better design involves adding or removing rows as needed.
![](https://i.imgur.com/cxhtOZ4.png)

## UNION quries
**UNION queries** are useful for dealing with repeating groups. We can use a UNION query to “normalize” our data in a read-only view **if we do not have the ability to create a properly normalized design**.

> NOTE:
> A UNION query requires that the columns be of the same data type, and in the same order, for each SELECT statement.

## Things to remember
- A goal of database normalization is the `elimination of repeating groups of data and minimizing the schema change`.
- By eliminating repeating groups of data, you can use `indexing to prevent accidental duplication of data`, and you greatly simplify any queries needed.
- Removing repeating groups of data makes the design more flexible because adding a new group simply requires adding another row of data, not changing the table design to add more columns.

