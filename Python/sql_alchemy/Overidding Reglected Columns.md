# Overidding Reglected Columns
###### tags: `database learn`

Individual columns can be overridden with explicit values when reflecting tables; this is handy for specifying custom datatypes, constraints such as primary keys that may not be configured within the database, etc.:
```python=
mytable = Table('mytable', metadata_obj,
Column('id', Integer, primary_key=True),   # override reflected 'id' to have primary key
Column('mydata', Unicode(50)),    # override reflected 'mydata' to be Unicode
# additional Column objects which require no change are reflected normally
autoload_with=some_engine)
```