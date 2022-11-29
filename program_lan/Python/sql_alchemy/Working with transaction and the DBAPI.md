# Working with transaction and the DBAPI
###### tags: `database learn`

## Getting Connection
The sole purpose of the Engine object from a user-facing perspective is to provide a unit of connectivity to the database called the Connection.

As the Connection represents an open resource against the database, we want to always limit the scope of our use of this object to a specific context, and the best way to do that is by using Python context manager form, also known as the **with** statement. 
```python=
from sqlalchemy import create_engine
from sqlalchemy import text

engine = create_engine("sqlite+pysqlite:///:memory:", echo=True, future=True)

with engine.connect() as conn:
    result = conn.execute(text("select 'hello world'"))
    print(result.all())
```

The default behavior of the Python DBAPI includes that a transaction is always in progress; when the scope of the connection is released, a ROLLBACK is emitted to end the transaction. The transaction is **not committed automatically**; when we want to commit data we normally need to call **Connection.commit()** as we’ll see in the next section.

## Committing Changes
### commit as use go style
SQLAlchemy refers to following style as **commit as you go**.
```python=
with engine.connect() as conn:
    conn.execute(text("CREATE TABLE some_table (x int, y int)"))
    conn.execute(
        text("INSERT INTO some_table (x, y) VALUES (:x, :y)"),
        [{"x": 1, "y": 1}, {"x": 2, "y": 4}]
    )
    conn.commit()
```
Above, we emitted two SQL statements that are generally transactional, a “CREATE TABLE” statement and an “INSERT” statement that’s parameterized (the parameterization syntax above is discussed a few sections below in Sending Multiple Parameters). As we want the work we’ve done to be committed within our block, we invoke the Connection.commit() method which commits the transaction. 

**After we call this method inside the block, we can continue to run more SQL statements and if we choose we may call Connection.commit() again for subsequent statements**.


### begin once style
The following style may be referred towards as **begin once**.
```python=
from sqlalchemy import create_engine
from sqlalchemy import text

engine = create_engine("sqlite+pysqlite:///:memory:", echo=True, future=True)

with engine.begin() as conn:
    conn.execute(text("CREATE TABLE some_table (x int, y int)"))
    conn.execute(
        text("INSERT INTO some_table (x, y) VALUES(:x, :y)"),
        [{"x": 6, "y": 8}, {"x": 9, "y": 10}]
    )
```

This method will both manage the scope of the Connection and also enclose everything inside of a transaction with COMMIT at the end, assuming a successful block, or ROLLBACK in case of exception raise. 

> What's "**BEGIN (implicit)"**
> You might have noticed the log line “BEGIN (implicit)” at the start of a transaction block. “implicit” here means that SQLAlchemy **did not actually send any command** to the database; it just considers this to be the start of the DBAPI’s implicit transaction. You can register event hooks to intercept this event, for example.

## Basics of Statement Execution
### Fetching Rows
```python=
from sqlalchemy import create_engine
from sqlalchemy import text

engine = create_engine("sqlite+pysqlite:///:memory:", echo=True, future=True)

with engine.connect() as conn:
    conn.execute(text("CREATE TABLE some_table (x int, y int)"))
    conn.execute(
        text("INSERT INTO some_table (x, y) VALUES (:x, :y)"),
        [{"x": 1, "y": 1}, {"x": 2, "y": 4}]
    )
    result = conn.execute(text("SELECT x, y FROM some_table"))
    for row in result:
        print(f"x: {row.x} y: {row.y}")
```

The Row objects themselves are intended to act like Python named tuples. Below we illustrate a variety of ways to access rows.

- Tuple Assignment: This is the most Python-idomatic style, which is to assign variables to each row positionally as they are recevied:
```python=
result = conn.execute(text("select x, y from some_table"))

for x, y in result:
    # ...
```
- Integer Index: Tuples are Python sequences, so regular integer access is available too:
```python
result = conn.execute(text("select x, y from some_table"))

for row in result:
    x = row[0]
```

- Attribute Name - As these are Python named tuples, the tuples have dynamic attribute names matching the names of each column. These names are normally the names that the SQL statement assigns to the columns in each row. While they are usually fairly predictable and can also be controlled by labels, in less defined cases they may be subject to database-specific behaviors:
```python=
result = conn.execute(text("delect x, y from some_table"))

for row in result:
    y = row.y
    
    # illustrate use with Python f-strings
    print(f"Row: {row.x} {row.y})
```

- Mapping Access: - To receive rows as Python **mapping** objects, which is essentially a read-only version of Python’s interface to the common dict object, the Result may be **transformed** into a MappingResult object using the Result.mappings() modifier; this is a result object that yields dictionary-like RowMapping objects rather than Row objects
```python=
result = conn.execute(text("select x, y from some_table"))

for dict_row in result.mappings():
    x = dict_row['x']
    y = dict_row['y']
```

### Sending Parameters
if we wanted to limit our SELECT statement only to rows that meet a certain criteria, such as rows where the “y” value were greater than a certain value that is passed in to a function.

In order to achieve this such that the SQL statement can remain fixed and that the driver can properly sanitize the value, we add a WHERE criteria to our statement that names a new parameter called “y”; the text() construct accepts these using a colon format “:y”. The actual value for “:y” is then passed as the second argument to **Connection.execute()** in the form of a dictionary:
```python=
from sqlalchemy import create_engine
from sqlalchemy import text

engine = create_engine("sqlite+pysqlite:///:memory:", echo=True, future=True)

with engine.connect() as conn:
    conn.execute(text("CREATE TABLE some_table (x int, y int)"))
    conn.execute(
        text("INSERT INTO some_table (x, y) VALUES (:x, :y)"),
        [{"x": 1, "y": 1}, {"x": 2, "y": 4}]
    )
    result = conn.execute(text("SELECT x, y FROM some_table WHERE y > :y"), {"y": 2})
    for row in result:
        print(f"x: {row.x} y: {row.y}")
```

In the logged SQL output, we can see that the bound parameter :y was converted into a question mark when it was sent to the SQLite database.

> Always use bound parameters
> As mentioned at the beginning of this section, textual SQL is not the usual way we work with SQLAlchemy. However, when using textual SQL, a Python literal value, even non-strings like integers or dates, should **never be stringified into SQL string directly**; a parameter should **always** be used. This is most famously known as how to avoid SQL injection attacks when the data is untrusted.

## Sending Multiple Parameters
In the example at Committing Changes, we executed an INSERT statement where it appeared that we were able to INSERT multiple rows into the database at once. For statements that **operate upon data, but do not return result sets**, namely DML statements such as “INSERT” which don’t include a phrase like “RETURNING”, we can send **multi params** to the Connection.execute() method by passing a list of dictionaries instead of a single dictionary, thus allowing the single SQL statement to be invoked against each parameter set individually:
```python=
from sqlalchemy import create_engine
from sqlalchemy import text

engine = create_engine("sqlite+pysqlite:///:memory:", echo=True, future=True)

with engine.connect() as conn:
    conn.execute(text("CREATE TABLE some_table (x int, y int)"))
    conn.execute(
        text("INSERT INTO some_table (x, y) VALUES (:x, :y)"),
        [{"x": 11, "y": 12}, {"x": 13, "y": 14}]
    )
    result = conn.execute(text("SELECT x, y FROM some_table WHERE y > :y"), {"y": 2})
    for row in result:
        print(f"x: {row.x} y: {row.y}")
```

## Bundling Parameters with a Statement
The two previous cases illustrate a series of parameters being passed to accompany a SQL statement. For single-parameter statement executions, SQLAlchemy’s use of parameters is in fact more often than not done by **bundling** the parameters with the statement itself, which is a primary feature of the SQL Expression Language and makes for queries that can be composed naturally while still making use of parameterization in all cases.

For a brief preview, the text() construct itself being part of the SQL Expression Language supports this feature by using the TextClause.bindparams() method; this is a generative method that returns a new copy of the SQL construct with additional state added, in this case the parameter values we want to pass along:
```python=
from sqlalchemy import create_engine
from sqlalchemy import text

engine = create_engine("sqlite+pysqlite:///:memory:", echo=True, future=True)

stmt = text("SELECT x, y FROM some_table WHERE y > :y ORDER BY x, y").bindparams(y=6)

with engine.connect() as conn:
    conn.execute(text("CREATE TABLE some_table (x int, y int)"))
    conn.execute(
        text("INSERT INTO some_table (x, y) VALUES (:x, :y)"),
        [{"x": 1, "y": 11}, {"x": 2, "y": 4}]
    )
    result = conn.execute(stmt)
    for row in result:
        print(f"x: {row.x} y: {row.y}")
```

## Executing with an ORM Session
The fundamental transactional / database interactive object when using the ORM is called the **Session**.

When the **Session** is used with non-ORM constructs, it passes through the SQL statements we give it and does not generally do things much differently from how the **Connection** does directly,

```python=
from sqlalchemy import create_engine
from sqlalchemy import text
from sqlalchemy.orm import Session

engine = create_engine("sqlite+pysqlite:///:memory:", echo=True, future=True)

stmt = text("SELECT x, y FROM some_table WHERE y > :y ORDER BY x, y").bindparams(y=6)

with Session(engine) as session:
    session.execute(text("CREATE TABLE some_table (x int, y int)"))
    session.execute(
        text("INSERT INTO some_table (x, y) VALUES (:x, :y)"),
        [{"x": 1, "y": 11}, {"x": 2, "y": 4}]
    )
    result = session.execute(stmt)
    for row in result:
        print(f"x: {row.x} y: {row.y}")
```

Also, like the **Connection**, the **Session** features “commit as you go” behavior using the **Session.commit()** method, illustrated below using a textual UPDATE statement to alter some of our data:
```python=
from sqlalchemy import create_engine
from sqlalchemy import text
from sqlalchemy.orm import Session

engine = create_engine("sqlite+pysqlite:///:memory:", echo=True, future=True)

stmt = text("SELECT x, y FROM some_table WHERE y > :y ORDER BY x, y").bindparams(y=6)

with Session(engine) as session:
    session.execute(text("CREATE TABLE some_table (x int, y int)"))
    session.execute(
        text("INSERT INTO some_table (x, y) VALUES (:x, :y)"),
        [{"x": 1, "y": 11}, {"x": 2, "y": 4}]
    )
    session.execute(stmt)
    result = session.execute(text("UPDATE some_table SET y=:y WHERE x=:x"), [{"x": 9, "y": 11}, {"x": 13, "y": 15}])
    session.commit()
```

> Tip
> The **Session** doesn’t actually hold onto the **Connection** object after it ends the transaction. It gets a new Connection from the **Engine** when executing SQL against the database is next needed.

