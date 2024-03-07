# Working with Database Metadata
###### tags: `database learn`

The central element of both SQLAlchemy Core and ORM is the SQL Expression Language which allows for fluent, composable construction of SQL queries. The foundation for these queries are Python objects that represent database concepts like tables and columns. These objects are known collectively as database metadata.

The most common foundational objects for database metadata in SQLAlchemy are known as **MetaData**, **Table**, and **Column**.

## Setting up MetaData with Table objects
When we work with a relational database, the basic structure that we create and query from is known as a **table**. In SQLAlchemy, the “table” is represented by a Python object similarly named **Table**.

Each Table may be **declared**, meaning we explicitly spell out in source code what the table looks like, or may be **reflected**, which means we generate the object based on what’s already present in a particular database. 

Whether we will declare or reflect our tables, we start out with a collection that will be where we place our tables known as the **MetaData** object. This object is essentially a **facade** around a Python dictionary that stores a series of Table objects keyed to their string name. Constructing this object looks like:
```python=
from sqlalchemy import MetaData
metadata_obj = MetaData()
```

Once we have a MetaData object, we can declare some **Table** objects.
We normally assign each Table object to a variable that will be how we will refer to the table in application code:
```python=
from sqlalchemy import Table, Column, Integer, String
user_table = Table(
    "user_account",
    metadata_obj,
    Column('id', Integer, primary_key=True),
    Column('name', String(30)),
    Column('fullname', String)
)
```

We can observe that the above Table construct looks a lot like a SQL CREATE TABLE statement; starting with the table name, then listing out each column, where each column has a name and a datatype. The objects we use above are:
- Table: represents a database table and assigns itself to a MetaData collection.

- Column: represents a column in a database table, and assigns itself to a **Table** object. The **Column** usually includes a string name and a type object. The collection of **Column** objects in terms of the parent **Table** are typically accessed via an associative array located at **Table.c**:
```python=
user_table.c.name

user_table.c.keys()
```

- Integer, String: these classes represent SQL datatypes and can be passed to a Column with or without necessarily being instantiated. Above, we want to give a length of “30” to the “name” column, so we instantiated String(30). But for “id” and “fullname” we did not specify these, so we can send the class itself.

## Declaring Simple Constraints
The primary key itself is normally declared implicitly and is represented by the **PrimaryKeyConstraint** construct, which we can see on the **Table.primary_key** attribute on the **Table** object:
```python=
user_table.primary_key
```

The constraint that is most typically declared explicitly is the **ForeignKeyConstraint** object that corresponds to a **database foreign key constraint**.

A ForeignKeyConstraint that involves only a single column on the target table is typically declared using a column-level shorthand notation via the **ForeignKey** object. 

Below we declare a second table **address** that will have a foreign key constraint referring to the **user** table:
```python=
from sqlalchemy import ForeignKey
address_table = Table(
    "address",
    metadata_obj,
    Column('id', Integer, primary_key=True),
    Column('user_id', ForeignKey('user_account.id'), nullable=False),
    Column('email_address', String, nullable=False)
)
```

> Tip
> When using the **ForeignKey** object within a **Column** definition, we can omit the datatype for that **Column**; it is automatically inferred from that of the related column, in the above example the **Integer** datatype of the **user_account.id** column.

## Emitting DDL to the Database
The first useful thing we can do with this structure will be to emit CREATE TABLE statements, or DDL, to our SQLite database so that we can insert and query data from them.

By invoking the **MetaData.create_all()** method on our MetaData, sending it the Engine that refers to the target database:
```python=
metadata_obj.create_all(engine)
```
The DDL create process by default includes some SQLite-specific PRAGMA statements that test for the existence of each table before emitting a CREATE.


The create process also takes care of emitting CREATE statements in the correct order; above, the FOREIGN KEY constraint is dependent on the user table existing, so the address table is created second.

The MetaData object also features a **MetaData.drop_all()** method that will emit DROP statements in the reverse order.

> Migration tools are usually appropriate
> Overall, the CREATE / DROP feature of MetaData is useful for test suites, small and/or new applications, and applications that use short-lived databases. For management of an application database schema over the long term however, a schema management tool such as **Alembic**, which builds upon SQLAlchemy, is likely a better choice, as it can manage and orchestrate the process of incrementally altering a fixed database schema over time as the design of the application changes.

## Defining Table Metadata with the ORM
When using the ORM, the process by which we declare **Table** metadata is usually combined with the process of declaring mapped classes.

The mapped class is any Python class we’d like to create, which will then have attributes on it that will be linked to the columns in a database table.

### Setting up the Registry
When using the ORM, the **MetaData** collection remains present, however it itself is contained within an ORM-only object known as the **registry**. We create a **registry** by contructing it:
```python=
from sqlalchemy.orm import registry
mapper_registry = registry()
```

The above registry, when constructed, automatically includes a **MetaData** object that will store a collection of **Table** objects:
```python=
mapper_registry.metadata
```

Instead of declaring **Table** objects directly, we will now declare them indirectly through **directives** applied to our mapped classes. In the most common approach, each mapped class descends from a common base class known as the **declarative base**. We get a new declarative base from the registry using the **registry.generate_base()** method:
```python=
Base = mapper_registry.generate_base()
```
> Tip
> The steps of creating the **registry** and “declarative base” classes can be combined into one step using the historically familiar **declarative_base()** function:
> ```python=
> from sqlalchemy.orm import declarative_base
> Base = declarative_base()
> ```

## Declaring Mapped Classes
The **Base** object above is a Python class which will serve as the base class for the ORM mapped classes we declare. We can now define ORM mapped classes for the **user** and **address** table in terms of new classes **User** and **Address**:
```python=
from sqlalchemy import create_engine, Column, Integer, String, ForeignKey
from sqlalchemy.orm import relationship, registry

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

print(User.__table__)
```

The above two classes are now our mapped classes, and are available for use in ORM persistence and query operations, which will be described later. But they also include Table objects that were generated as part of the declarative mapping process, and are equivalent to the ones that we declared directly in the previous Core section. We can see these Table objects from a declarative mapped class using the .__table__ attribute:
```python=
>>> User.__table__
Table('user_account', MetaData(),
    Column('id', Integer(), table=<user_account>, primary_key=True, nullable=False),
    Column('name', String(length=30), table=<user_account>),
    Column('fullname', String(), table=<user_account>), schema=None)
```

## Other Mapped Class Details
For a few quick explanations for the classes above, note the following attributes:
- **the classes have an automatically generated __init__() method**: both classes by default receive an __init__() method that allows for parameterized construction of the objects. We are free to provide our own __init__() method as well. The __init__() allows us to create instances of **User** and **Address** passing attribute names, most of which above are linked directly to **Column** objects, as parameter names:
```python=
sandy = User(name="sandy", fullname="Sandy Cheeks")
```
- **we provided a __repr__() method: this is **fully optional**, and is strictly so that out custom classes have a descriptive string representation and is not otherwise required:
```python=
>>> sandy
User(id=None, name='sandy', fullname='Sandy Cheeks')
```
- **we also included a bidirectional relationship**: this is another fully **optional construct**, where we made use of an ORM construct called **relationship()** on both classes, which indicates to the ORM that these User and Address classes refer to each other in a **one to many / many to one** relationship. The use of **relationship()** above is so that we may demonstrate its behavior later in this tutorial; it is **not required** in order to define the **Table** structure.

## Emitting DDL to the database with ORM
 If we wanted to emit DDL for the Table objects we’ve created as part of our declaratively mapped classes, we still can use **MetaData.create_all()** as before.

```python=
# emit CREATE statements given ORM registry
mapper_registry.metadata.create_all(engine)

# the identical MetaData object is also present on the
# declarative base
Base.metadata.create_all(engine)
```

## Combining Core Table Declarations with ORM Declarative
As an alternative approach to the mapping process shown previously at**Declaring Mapped Classes**, we may also make use of the **Table** objects we created directly in the section **Setting up MetaData with Table objects** in conjunction with declarative mapped classes from a **declarative_base()** generated base class.

This form is called **hybrid table**, and it consists of assigning to the .__table__ attribute directly, rather than having the declarative process generate it:
```python=
mapper_registry = registry()
Base = mapper_registry.generate_base()

class User(Base):
    __table__ = user_table

    addresses = relationship("Address", back_populates="user")

    def __repr__(self):
        return f"User({self.name!r}, {self.fullname!r})"

class Address(Base):
    __table__ = address_table

    user = relationship("User", back_populates="addresses")

    def __repr__(self):
        return f"Address({self.email_address!r})"
```
> Note
> The above example is an **alternative form** to the mapping that’s first illustrated previously at Declaring Mapped Classes. This example is for illustrative purposes only, and is not part of this tutorial’s “doctest” steps, and as such does not need to be run for readers who are executing code examples. The mapping here and the one at Declaring Mapped Classes produce equivalent mappings, but **in general one would use only one of these two forms for particular mapped class**.

## Table Reflection
To round out the section on working with table metadata, we will illustrate another operation that was mentioned at the beginning of the section, that of **table reflection**.

Whereas in the previous sections we’ve been declaring Table objects in Python and then emitting DDL to the database, the **reflection process does it in reverse**.

As an example of reflection, we will create a new Table object which represents the **some_table** object we created manually in the earlier sections of this document. There are again some varieties of how this is performed, however the most basic is to construct a Table object, given the name of the table and a MetaData collection to which it will belong, then instead of indicating individual Column and Constraint objects, pass it the target Engine using the **Table.autoload_with** parameter

```python=
some_table = Table("some_table", metadata_obj, autoload_with=engine)
```

At the end of the process, the **some_table** object now contains the information about the **Column** objects present in the table, and the object is usable in exactly the same way as a Table that we declared explicitly:
```python=
>>> some_table
Table('some_table', MetaData(),
    Column('x', INTEGER(), table=<some_table>),
    Column('y', INTEGER(), table=<some_table>),
    schema=None)
```