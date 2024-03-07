# 13: Using databases and SQL
###### tags: `python learn`

## What is a database?
A database is a file that is organized for storing data. Most databases are organized like a dictionary in the sense that they map from keys to values. The biggest difference is
that the database is on disk (or other permanent storage), so it persists after the program ends. Because a database is stored on permanent storage, it can store far more data than
a dictionary, which is limited to the size of the memory in the computer.

## Database concepts
When you first look at a database it looks like a spreadsheet with multiple sheets. The primary data structures in a database are: tables, rows, and columns.

In technical descriptions of relational databases the concepts of table, row, and column are more formally referred to as relation, tuple, and attribute, respectively.

![](https://i.imgur.com/1pqkylv.png)

## Database Browser for SQLite
While this chapter will focus on using Python to work with data in SQLite database files, many operations can be done more conveniently using software called the Database Browser for SQLite which is freely available from:

http://sqlitebrowser.org/

Using the browser you can easily create tables, insert data, edit data, or run simple SQL queries on the data in the database.

## SQLite basic introduce
SQLite is "typeless". This means that you can store any kind of data you want in any column of any table, regardless of the declared datatype of that column.

Even though SQLite allows the datatype to be omitted, it is still a good idea to include it in your CREATE TABLE statements, since the data type often serves as a good hint to other programmers about what you intend to put in the column.

SQLite accepts all the usual datatypes. For example:

![](https://i.imgur.com/vqF940o.png)

## The SQLite integer primary key
One exception to the typelessness of SQLite is a column whose type is INTEGER PRIMARY KEY. (And you must use "INTEGER" not "INT". A column of type INT PRIMARY KEY is typeless just like any other.) INTEGER PRIMARY KEY columns must contain a 32-bit signed integer. Any attempt to insert non-integer data will result in an error.

INTEGER PRIMARY KEY columns can be used to implement the equivalent of AUTOINCREMENT. If you try to insert a NULL into an INTEGER PRIMARY KEY column, the column will actually be filled with an integer that is one greater than the largest key already in the table.

## Comparison and Sort Order
SQLite is typeless for the purpose of deciding what data is allowed to be stored in a column. But some notion of type comes into play when sorting and comparing data. For these purposes, a column or an expression can be one of two types: **numeric** and **text**.



## Creating a database table
When we create a database table we must tell the database in advance the names of each of the columns in the table and the type of data which we are planning to store in each column. When the database software knows the type of data in each column, it can choose the most efficient way to store and look up the data based on the type of data.


The code to create a database file and a table named Tracks with two columns in the database is as follows:
```python=
import sqlite3

conn = sqlite3.connect('music.sqlite')
cur = conn.cursor()

cur.execute('DROP TABLE IF EXISTS Tracks')
cur.execute('CREATE TABLE Tracks (title TEXT, plays INTEGER)')

conn.close()
```
The connect operation makes a “connection” to the database stored in the file `music.sqlite3` in the current directory. If the file does not exist, it will be created.

A cursor is like a file handle that we can use to perform operations on the data stored in the database. Calling `cursor()` is very similar conceptually to calling `open()` when dealing with text files.
![](https://i.imgur.com/L1Yc7uD.png)

Once we have the cursor, we can begin to execute commands on the contents of the database using the `execute()` method.

As a convention, we will show the SQL keywords in uppercase and the parts of the command that we are adding (such as the table and column names) will be shown in lowercase.

The first SQL command removes the Tracks table from the database if it exists. This pattern is simply to allow us to run the same program to create the Tracks table over and over again without causing an error. Note that the `DROP TABLE` command deletes the table and all of its contents from the database (i.e., there is no “undo”).
```python=
cur.execute('DROP TABLE IF EXISTS Tracks ')
```

The second command creates a table named `Tracks` with a text column named `title` and an integer column named `plays`.
```python=
cur.execute('CREATE TABLE Tracks (title TEXT, plays INTEGER)')
```

Now that we have created a table named `Tracks`, we can put some data into that table using the SQL `INSERT` operation.

The SQL `INSERT` command indicates which table we are using and then defines a new row by listing the fields we want to include `(title, plays)` followed by the VALUES we want placed in the new row. We specify the values as question marks `(?, ?)` to indicate that the actual values are passed in as a tuple `( 'My Way', 15 )` as the second parameter to the `execute()` call.
```python=
import sqlite3

conn = sqlite3.connect('music.sqlite')
cur = conn.cursor()

cur.execute('INSERT INTO Tracks (title, plays) VALUES (?,?)', ('Thunderstruck', 20))
cur.execute('INSERT INTO Tracks (title, plays) VALUES (?,?)', ('My Way', 15))
conn.commit()

print('Tracks:')
cur.execute('SELECT title, plays FROM Tracks')
for row in cur:
	print(row)

cur.execute('DELETE FROM Tracks WHERE plays < 100')

cur.close()
```

First we `INSERT` two rows into our table and use `commit()` to force the data to be written to the database file.


Then we use the `SELECT` command to retrieve the rows we just inserted from the table. On the `SELECT` command, we indicate which columns we would like ``(title, plays)``
and indicate which table we want to retrieve the data from. After we execute the `SELECT` statement, the cursor is something we can loop through in a `for` statement.

## SQL summary

```python=
CREATE TABLE Tracks (title TEXT, plays INTEGER)
INSERT INTO Tracks (title, plays) VALUES ('My Way', 15)
SELECT * FROM Tracks WHERE title = 'My Way'
SELECT title,plays FROM Tracks ORDER BY title
DELETE FROM Tracks WHERE title = 'My Way'
UPDATE Tracks SET plays = 16 WHERE title = 'My Way'
```
## Basic data modeling
The real power of a relational database is when we create multiple tables and make links between those tables. The act of deciding how to break up your application data into multiple tables and establishing the relationships between the tables is called data modeling.
The design document that shows the tables and their relationships is called a data model.

## Three kinds of key
There are generally three kinds of keys used in a database model.
-  A logical key is a key that the “real world” might use to look up a row. In our example data model, the `name` field is a logical key. It is the screen name for the user and we indeed look up a user’s row several times in the program using the name field. You will often find that it makes sense to add a `UNIQUE` constraint to a logical key. Since the logical key is how we look up a row from the outside world, it makes little sense to allow multiple rows with the same value in the table.
-  A primary key is usually a number that is assigned automatically by the database. It generally has no meaning outside the program and is only used to link rows from different tables together. When we want to look up a row in a table, usually searching for the row using the primary key is the fastest way to find the row. Since primary keys are integer numbers, they take up very little storage and can be compared or sorted very quickly. In our data model, the `id` field is an example of a primary key.
-  A foreign key is usually a number that points to the primary key of an associated row in a different table. An example of a foreign key in our data model is the `from_id`