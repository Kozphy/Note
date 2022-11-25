# Reflecting All Tables at Once
###### tags: `database learn`

The `MetaData` object can also get a listing of tables and reflect the full set. This is achieved by using the `reflect()` method. After calling it, all located tables are present within the `MetaData` object’s dictionary of tables:
```python=
metadata_obj = MetaData()
metadata_obj.reflect(bind=someengine)
users_table = metadata_obj.tables['users']
addresses_table = metadata_obj.tables['addresses']
```

`metadata.reflect()` also provides a handy way to clear or delete all the rows in a database:
```python=
metadata_obj = MetaData()
metadata_obj.reflect(bind=someengine)
for table in reversed(metadata_obj.sorted_tables):
    someengine.execute(table.delete())
```

