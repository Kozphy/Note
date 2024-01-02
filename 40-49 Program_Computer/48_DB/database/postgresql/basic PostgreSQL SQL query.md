# basic PostgreSQL SQL query
###### tags: `database learn`

# prodcuts table example
![](https://i.imgur.com/ek5XEMQ.png)


## LIKE
```sql=
select * from products where name like 'TV%';
select * from products where name like 'r%';
select * from products where name like '%e';
select * from products where name not like '%e';
select * from products where name like '%en%';
```
![](https://i.imgur.com/zW6MN2p.png)
![](https://i.imgur.com/dI6tIR4.png)
![](https://i.imgur.com/MNTGL8X.png)
![](https://i.imgur.com/Lr8wr75.png)


## IN
```sql=
select * from products where id in (1,2,3);
```
![](https://i.imgur.com/0KqLTae.png)

## order by
### ascending order
```sql=
select * from products order by price;
```
![](https://i.imgur.com/ne2EGUy.png)

### descending order
```sql=
select * from products order by price desc;
```
![](https://i.imgur.com/hfwuuti.png)

### combine ascending and descending
```sql=
select * from products order by inventory desc, price asc;
```
![](https://i.imgur.com/zAbJ4Am.png)

### conbime with where
```sql=
select * from products where price > 20 order by create_at desc;
```
![](https://i.imgur.com/zKPeeLR.png)


## LIMIT
select how many row do you want
```sql=
select * from products LIMIT 10;
```

### combine with where
```sql=
select * from products where price > 10 limit 2;
```

### comebine with order by
```sql=
select * from products order by id limit 5;
```
![](https://i.imgur.com/fbwiL2b.png)

#### with offset
skip first 2 result
```sql=
select * from products order by id limit 5 offset 2;
```
![](https://i.imgur.com/Qn8Sx7x.png)


## insert
```sql=
insert into products (name, price, inventory) values ('tortilla', 4, 1000);
```

### with returning
with returning it will return what content you insert.
```sql=
insert into products (name, price, inventory ) values ('car', 4, 1000) returning *;
```

```sql=
insert into products (name, price, inventory ) values ('car', 4, 1000) returning create_at, name;
```


### insert muti row
```sql=
insert into products (name, price, inventory ) values ('car', 4, 1000), ('laptop', 50, 25) returning *;
```

## delete
```sql=
delete from products where id = 10;
```

### with returning
```sql=
delete from products where id = 10 returning *;
```

### with where
```sql=
delete from products where inventory = 0 returning *;
```

## update
```sql=
update products set name='flour tortilla', price = 40 where id = 14 returning *;
```