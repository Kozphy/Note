#sql 

## foreign key name convention
- `fk_<referencing_table>_<referenced_table>` 
-  `FK_ForeignKeyTable_PrimaryKeyTable`

`<referencing_table>` is the name of the table that contains the `foreign key column`, and 

`<referenced_table>` is the name of the table that the `foreign key column references`.

## example
Suppose we have two table `orders` and `customers`.

`orders` have foreign key column `customer_id` => `fk_orders_customers`