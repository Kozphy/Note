# Estalishing connectivity - engine
###### tags: `database learn`

The start of any SQLAlchemy application is an object called the **Engine**.

For this tutorial we will use an in-memory-only SQLite database. This is an easy way to test things without needing to have an actual pre-existing database set up. The **Engine** is created by using **create_engine()**, specifying the **create_engine.future** flag set to True so that we make full use of 2.0 style usage:
```python=
from sqlalchemy import create_engine
engine = create_engine("sqlite+pysqlite:///:memory:", echo=True, future=True)
```

The main argument to create_engine is a string URL, above passed as the string "sqlite+pysqlite:///:memory:". This string indicates to the Engine three important facts:

1. What kind of database are we communicating with? This is the sqlite portion above, which links in SQLAlchemy to an object known as the dialect.

2. What DBAPI are we using? The Python DBAPI is a third party driver that SQLAlchemy uses to interact with a particular database. In this case, we’re using the name pysqlite, which in modern Python use is the sqlite3 standard library interface for SQLite. If omitted, SQLAlchemy will use a default DBAPI for the particular database selected.

3. How do we locate the database? In this case, our URL includes the phrase /:memory:, which is an indicator to the sqlite3 module that we will be using an in-memory-only database. This kind of database is perfect for experimenting as it does not require any server nor does it need to create new files.

> Lazy Connecting
> The Engine, when first returned by **create_engine()**, has not actually tried to connect to the database yet; that happens only the first time it is asked to perform a task against the database. This is a software design pattern known as lazy initialization.

We have also specified a parameter **create_engine.echo**, which will instruct the Engine to log all of the SQL it emits to a Python logger that will write to standard out.