# Item 4: Store Only One Property per Column
###### tags: `sql book`

## why need to store only one property per colunm
In relational terminology, a relation (table) should describe one and only one subject or action.

It is not a good idea to store more than one property value in a single column because that makes it difficult to isolate that property value when performing searches or aggregating values.

Fundamentally, you should consider putting important individual properties in their own columns.

You can see an example of a table containing multiple properties in columns in **Table 1.1**.
![](https://i.imgur.com/ELWOCoK.png)

A table like this has several problems:
- It is difficult if not impossible to search on last name. Assuming the table contains more than just the four sample rows, and you want to search for someone with a last name of Smith, a LIKE search using wildcards may also return Smithson or Blacksmith.
- You can search for first name, but you have to use the less efficient LIKE or pull out the name as a substring. A LIKE with a trailing wildcard may be processed efficiently, but because the name might have a salutation (such as Mr.), you have to use a leading wildcard to ensure that you find the name you want, and that will cause a data scan.
- You cannot easily search for street name, city, state/province, or postal code.
- When attempting to group the data (perhaps joined with another table that lists assigned chapters and page counts), it is tough to extract the state/province, postal code, or country to do the grouping.

## correct solution
![](https://i.imgur.com/obRCkci.png)

Using the suggested table design, the data can now be split into one attribute per column as shown in **Table 1.2** on the next page.
![](https://i.imgur.com/r8DAmAs.png)

## Things to remember
- Correct table design assigns each individual property to its own column, because when a column contains multiple properties, searching and grouping become difficult if not impossible.
- For some applications, the need to filter the parts in columns such as address or phone number may dictate the level of granularity.
- When you need to reassemble properties for a report or a printed listing, use concatenation.