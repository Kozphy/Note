# Working with Data
###### tags: `database learn`

## Working with Data
In this section we will combine both concepts above to create, select and manipulate data within a relational database. Our interaction with the database is always in terms of a transaction, even if we’ve set our database driver to use autocommit behind the scenes.

The components of this section are as follows:
- **Inserting Rows with Core**:  to get some data into the database, we introduce and demonstrate the Core Insert construct. INSERTs from an ORM perspective are described in the next section Data Manipulation with the ORM.

- **Selecting Rows with Core or ORM**: this section will describe in detail the Select construct, which is the most commonly used object in SQLAlchemy. The Select construct emits SELECT statements for both Core and ORM centric applications and both use cases will be described here. Additional ORM use cases are also noted in the later section Using Relationships in Queries as well as the ORM Querying Guide.

- **Update and Deleting Rows with Core**: Rounding out the INSERT and SELECTion of data, this section will describe from a Core perspective the use of the Update and Delete constructs. ORM-specific UPDATE and DELETE is similarly described in the Data Manipulation with the ORM section.

## Inserting Rows with Core
When using Core, a SQL INSERT statement is generated using the **insert()** function - this function generates a new instance of **Insert** which represents an INSERT statement in SQL, that adds new data into a table.

### The insert() SQL Expression Construct
A simple example of Insert illustrating the target table and the VALUES clause at once:
```python=
from sqlalchemy import insert
stmt = insert(user_table).values(name='spongbob', fullname='Spongebob Squarepants')
```

The above stmt variable is an instance of **Insert**. Most SQL expressions can be stringified in place as a means to see the general form of what’s being produced:
```python=
>>> print(stmt)
INSERT INTO user_account (name, fullname) VALUES (:name, :fullname)
```
The stringified form is created by producing a **Compiled** form of the object which includes a database-specific string SQL representation of the statement; we can acquire this object directly using the **ClauseElement.compile()** method:
```python=
compiled = stmt.compile()
compiled.params
{'name': 'spongebob', 'fullname': 'Spongebob Squarepants'}
```

## Executing the Statement
Invoking the statement we can INSERT a row into user_table. The INSERT SQL as well as the bundled parameters can be seen in the SQL logging:
```python=
with engine.connect() as conn:
    result = conn.execute(stmt)
    conn.commmit()

```

```sql=
BEGIN (implicit)
INSERT INTO user_account (name, fullname) VALUES (?, ?)
[...] ('spongebob', 'Spongebob Squarepants')
COMMIT
```

In the above case the first row in a SQLite database will normally return 1 for the first integer primary key value, which we can acquire using the **CursorResult.inserted_primary_key** accessor:
```python=
>>> result.inserted_primary_key
(1,)
```

> Tip
> **CursorResult.inserted_primary_key** returns a tuple because a primary key may contain multiple columns. This is known as a **composite primary key**. The **CursorResult.inserted_primary_key** is intended to always contain the complete primary key of the record just inserted, not just a “cursor.lastrowid” kind of value, and is also intended to be populated regardless of whether or not “autoincrement” were used, hence to express a complete primary key it’s a tuple.

## INSERT usually generates the "values" clause automatically
The usual way that **Insert** is used is such that the VALUES clause is generated automatically from the parameters passed to the **Connection.execute()** method; below we INSERT two more rows to illustrate this:
```python=
with engine.connect() as conn:
    result = conn.execute(
        insert(user_table),
        [
            {"name": "sandy", "fullname": "Sandy Cheeks"},
            {"name": "patrick", "fullname": "Patrick Star"}
        ]
    )
    conn.commit()
```

The execution above features “executemany” form first illustrated at **Sending Multiple Parameters**, however unlike when using the **text()** construct, we didn’t have to spell out any SQL.

> Deep Alchemy
> Below is a more advanced example illustrating how the **Insert.values()** method may be used explicitly while at the same time including for additional VALUES generated from the parameters. A **scalar subquery** is constructed, making use of the **select()** construct introduced in the next section, and the parameters used in the subquery are set up using an explicit bound parameter name, established using the **bindparam()** construct.
> 
> This is some slightly deeper alchemy just so that **we can add related rows without fetching the primary key identifiers** from the user_table operation into the application. Most Alchemists will simply use the ORM which takes care of things like this for us.
> ```python=
> from sqlalchemy import select, bindparam
> scalar_subq = (
>    select(user_table.c.id).
>    where(user_table.c.name==bindparam('username')).
>    scalar_subquery()
> )
>
> with engine.connect() as conn:
>    result = conn.execute(
>        insert(address_table).values(user_id=scalar_subq),
>        [
>            {"username": 'spongebob', "email_address":
>            "spongebob@sqlalchemy.org"},
>            {"username":'sandy',
>            "email_address":"sandy@sqlalchemy.org"},
>            {"username": 'sandy', 
>            "email_address": "sandy@squirrelpower.org"},
>        ]
>    )
>    conn.commit()
>
> ```

## INSERT...FROM SELECT
The **Insert** constuct can compose an INSERT that gets rows directly from a SELECT using the **Insert.from_select()** method:
```python=
from sqlalchemy import Table, create_engine, MetaData, text, insert, MetaData, Column,Integer,String, select, ForeignKey

engine = create_engine("sqlite+pysqlite:///:memory:", echo=True, future=True)

metadata_obj = MetaData()
user_table = Table(
    "user_account",
    metadata_obj,
    Column('id', Integer, primary_key=True),
    Column('name', String(30)),
    Column('fullname', String)
)

address_table = Table(
    "address",
    metadata_obj,
    Column('id',Integer , primary_key=True),
    Column('user_id', ForeignKey('user_account.id'), nullable=False),
    Column('email_address',String)
)


metadata_obj.create_all(engine)

select_stmt = select(user_table.c.id, user_table.c.name + "@aol.com") 
insert_stmt = insert(address_table).from_select(
    ['user_id', "email_address"], select_stmt
)
print(insert_stmt)
```
```SQL
INSERT INTO address (user_id, email_address)
SELECT user_account.id, user_account.name || :name_1 AS anon_1
FROM user_account
```

## INSERT...RETURNING
The RETURNING clause for supported backends is used automatically in order to retrieve the last inserted primary key value as well as the values for server defaults. However the RETURNING clause may also be specified explicitly using the **Insert.returning()** method; in this case, the **Result** object that’s returned when the statement is executed has rows which can be fetched:
```python=
>>> insert_stmt = insert(address_table).returning(address_table.c.id, address_table.c.email_address)
>>> print(insert_stmt)
```
```sql=
INSERT INTO address (id, user_id, email_address)
VALUES (:id, :user_id, :email_address)
RETURNING address.id, address.email_address
```

It can also be combined with **Insert.from_select()**,as in the example below that builds upon the example stated in **INSERT...FROM SELECT**:
```python=
select_stmt = select(user_table.id, user_table.c.name + "@aol.com")
insert_stmt = insert(address_table).from_select(
    ["user_id", "email_address"], select_stmt
)
print(insert_stmt.returning(address_table.c.id, address_table.c.email_address))
```
> Tip
> The RETURNING feature is also supported by UPDATE and DELETE statements, which will be introduced later in this tutorial. **The RETURNING feature is generally only supported for statement executions that use a single set of bound parameters**; that is, it wont work with the “executemany” form introduced at Sending Multiple Parameters. Additionally, some dialects such as the Oracle dialect only allow RETURNING to return a single row overall, meaning it won’t work with “INSERT..FROM SELECT” nor will it work with multiple row Update or Delete forms.

## Selecting Rows with Core or ORM
For both Core and ORM, the **select()** function generates a **Select** construct which is used for all SELECT queries. Passed to methods like **Connection.execute()** in Core and **Session.execute()** in ORM

### The select() SQL Expression Construct
The **select()** construct builds up a statement in the same way as that of insert(), using a generative approach where each method builds more state onto the object. Like the other SQL constructs, it can be stringified in place:
```python=
from sqlalchemy import select
stmt = select(user_table).where(user_table.c.name == 'spongebob')
print(stmt)
```
```
SELECT user_account.id, user_account.name, user_account.fullname
FROM user_account
WHERE user_account.name = :name_1
```

Since a SELECT statement returns rows we can always iterate the result object to get Row objects back:
```python=
with engine.connect() as conn:
    for row in conn.execute(stmt):
        print(row)
```

When using the ORM, particularly with a select() construct that’s composed against ORM entities, we will want to execute it using the Session.execute() method on the Session; using this approach, we continue to get Row objects from the result, however these rows are now capable of including complete entities, such as instances of the User class, as individual elements within each row:
```python=
stmt = select(User).where(User.name == 'spongebob')

with Session(engine) as session:
    for row in session.execute(stmt):
        print(row)
```

```
BEGIN (implicit)
SELECT user_account.id, user_account.name, user_account.fullname
FROM user_account
WHERE user_account.name = ?
[...] ('spongebob',)
```

> select() from a Table vs ORM class
> While the SQL generated in these examples looks the same whether we invoke select(user_table) or select(User), in the more general case they do not necessarily render the same thing, as an ORM-mapped class may be mapped to other kinds of “selectables” besides tables. The select() that’s against an ORM entity also indicates that ORM-mapped instances should be returned in a result, which is not the case when SELECTing from a **Table** object.

# Setting COLUMNS and FROM clause
The **select()** function accepts positional elements representing any number of **Column** and/or **Table** expressions, as well as a wide range of compatible objects, which are resolved into a list of SQL expressions to be SELECTed from that will be returned as columns in the result set.
```python=
print(select(user_table))
```
```sql
SELECT user_account.id, user_account.name, user_account.fullname
FROM user_account
```

To SELECT from individual columns using a **Core approach**, Column objects are accessed from the Table.c accessor and can be sent directly.
```python=
print(select(user_table.c.name, user_table.c.fullname))
```

```sql=
SELECT user_account.name, user_account.fullname
FROM user_account
```

## Setting ORM Entities and clause
Below illustrates an example of SELECTing from the User entity, which ultimately renders in the same way as if we had used user_table directly:
```python=
>>> print(select(User))
```
```sql
SELECT user_account.id, user_account.name, user_account.fullname
FROM user_account
```

When executing a statement like the above using the ORM Session.execute() method, there is an important difference when we select from a full entity such as **User**, as opposed to **user_table**, which is that the **entity itself is returned as a single element within each row**.

That is, when we fetch rows from the above statement, as there is only the User entity in the list of things to fetch, we get back **Row** objects that have only one element, which contain instances of the **User** class:
```python=
row = session.execute(select(User)).first()

>>> row
(User(id=1, name='spongebob', fullname='Spongebob Squarepants'),)
```
The above Row has just one element, representing the **User** entity:
```python=
>>> row[0]
User(id=1, name='spongebob', fullname='Spongebob Squarepants')
```

A highly recommended convenience method of achieving the same result as above is to use the **Session.scalars()** method to execute the statement directly; this method will return a **ScalarResult** object that delivers the first “column” of each row at once, in this case, instances of the User class:
```python=
user = session.scalars(select(User)).first()
```

Alternatively, we can select individual columns of an ORM entity as distinct elements within result rows, by using the class-bound attributes
```python=
print(select(User.name, User.fullname))
```

The approaches can also be mixed, as below where we SELECT the **name** attribute of the **User** entity as the first element of the row, and combine it with full **Address** entities in the second element:
```python=
from sqlalchemy import create_engine, Column, Integer, String, ForeignKey,select,text
from sqlalchemy.orm import relationship, registry, Session


engine = create_engine("sqlite+pysqlite:///:memory:", echo=True, future=True)
mapper_registry = registry()

Base = mapper_registry.generate_base()

class User(Base):
    __tablename__ ='user_account'

    id = Column(Integer, primary_key=True)
    name = Column(String(30))
    fullname = Column(String)

    addresses = relationship("Address", back_populates='user')

    def __repr__(self):
        return f'User(id={self.id!r}, name={self.name!r}, fullname={self.fullname!r})'

class Address(Base):
    __tablename__ ='address'

    id = Column(Integer, primary_key=True)
    email_address = Column(String, nullable=False)
    user_id = Column(Integer, ForeignKey('user_account.id'))

    user = relationship("User", back_populates='addresses')

    def __repr__(self):
        return f"Address(id={self.id!r}, email_address={self.email_address!r}"

Base.metadata.create_all(engine)

stmt = select(User).where(User.name == 'spongebob')

with engine.connect() as conn:
    conn.execute(
    text("INSERT INTO user_account (name, fullname) VALUES (:name, :fullname)"),
    [{'name': 'sandy', 'fullname': 'Sandy Cheeks'},
    {'name': 'patrick', 'fullname': 'Patrick Star'}]
    )

    conn.execute(
    text("INSERT INTO address (email_address, user_id) VALUES (:email_address, :user_id)"),
    [{'email_address':'patrick@gmail.com', 'user_id':2},
    {'email_address':'sandy@gmail.com', 'user_id':1}]
    )


    conn.commit()

with Session(engine) as session:
    res = session.execute(
        select(User.name, Address).
        where(User.id==Address.user_id).
        order_by(Address.id)
    ).all()
    print(res)
```

## Selecting from Labeled SQL Expressions
The **ColumnElement.label()** method as well as the same-named method available on ORM attributes provides a SQL label of a column or expression, allowing it to have a specific name in a result set.
```python=
from sqlalchemy import func, cast
stmt = (
    select(
        ("Username: " + user_table.c.name).label("username"),
    ).order_by(user_table.c.name)
)

with engine.connect() as conn:
    for row in conn.execute(stmt):
        print(f"{row.username}"")
```

```sql=
BEGIN (implicit)
SELECT ? || user_account.name AS username
FROM user_account ORDER BY user_account.name
[...] ('Username: ',)
```

