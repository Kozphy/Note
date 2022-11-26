# sqlite
###### tags: `python module`

## connect to sqlite
```python=
import sqlite3

conn = sqlite3.connect('mydata.db')
```

This right here creates the new file **mydata.db** and connects to this database. It returns a connection object which we save in the variable conn .

## executing statements
So, we have established a connection to the database. But in order to execute SQL statements, we will need to create a so-called **cursor** .
```python=
c = conn.cursor()
```

## creating tables
```python=
c.execute("""CREATE TABLE persons(
    first_name TEXT,
    last_name TEXT,
    age INTEGER
)""")
```

Now our statement is written but in order to really execute it, we ne need to commit to our connection.
```python=
conn.commit()
```
When we do this, our statement gets executed and our table created. Notice that this works only once, since after that the table already exists and can’t be created again.

At the end, don’t forget to close the connection, when you are done with everything.
```python=
conn.close()
```

## Inserting values
```python=
c.execute("""INSERT INTO persons VALUES
    ('John', 'Smith', 25),
    ('Anna', 'Smith', 30),
    ('Mike', 'Johnson', 45)""")
conn.commit()
conn.close()
```

## Selecting values
```python=
c.execute("""SELECT * FROM persons
    WHERE last_name = 'Smith'""")

print(c.fetchall())

conn.commit()
conn.close()
```

As you can see, our **SELECT** statement that gets all the entries where the last_name has the value Smith . We then need to use the method fetchall of the cursor, in order to get our results. It returns a list of tuples, where every tuple is one entry. Alternatively, we could use the method **fetchone** to only get the first entry or **fetchmany** to get a specific amount of entries. In our case however, the result looks like this:
```
[('John', 'Smith', 25), ('Anna', 'Smith', 30)]
```

## Classes and tables
Now in order to make the communication more efficient and easier, we are going to create a **Person** class that has the columns as attributes.
```python=
class Person():
    def __init__(self, first=None, last=None, age=None):
        self.first = first
        self.last = last
        self.age = age
        
    def clone_person(self, result):
        self.first = result[0]
        self.last = result[1]
        self.age = result[2]
```
Here we have a constructor with default parameters. In case we don’t specify any values, they get assigned the value **None** . Also, we have a function **clone_person** that gets passed a sequence and assigns the values of it to the object. In our case, this sequence will be the tuple from the fetching results.

## from table to object
So let’s create a new Person object by getting its data from our database.
```python=
c.execute("""SELECT * FROM persons
    WHERE last_name ='Smith'""")

person1 = Person()

person1.clone_person(c.fetchone())

print(person1.first)
print(person2.last)
print(person1.age)
```

## from object to table
We can also do that the other way around. Let’s create a person objects, assign values to the attributes and then insert this object into our database.
```python=
person2 = Person("Bob", "Davis", 23)

c.execute("""INSERT INTO persons VALUES
    ('{}', '{}', '{}')""".format(person2.first,
                                 person2.last,
                                 person2.age))

conn.commit()
conn.close()
```

## prepare statements
There is a much more secure and elegant way to put the values of our attributes into the SQL statements. We can use **prepared** statements .
```python=
person = Person("Julia", "Johnson", 28)

c.execute("INSERT INTO persons VALUES (?, ?, ?)",
         (person.first, person.last, person.age))

conn.commit()
conn.close()
```


