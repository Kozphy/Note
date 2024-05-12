#database 

- [[#Source|Source]]
- [[#concat|concat]]

## Source
```sql
select * from 學生;
```
![](Pasted%20image%2020240510110540.png)

## concat
- we use `single quotes for text`.
- `double quote` are referring to a column name.
```sql
select concat(學號, ' ', 姓名) as 學生與學號 from 學生;
```
![](Pasted%20image%2020240510110702.png)