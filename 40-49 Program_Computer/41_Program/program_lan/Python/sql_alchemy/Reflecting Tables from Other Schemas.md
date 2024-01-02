# Reflecting Tables from Other Schemas
###### tags: `database learn`

The “schema” for a `Table` object, as well as for other objects like views, indexes and sequences, can be set up using the `Table.schema` parameter, and also as the default schema for a `MetaData` object using the `MetaData.schema` parameter.

The use of this schema parameter directly affects where the table reflection feature will look when it is asked to reflect objects. For example, given a `MetaData` object configured with a default schema name “project” via its `MetaData.schema` parameter:
```python=
>>> metadata_obj = MetaData(schema="project")
```

The `MetaData.reflect` will then utilize that configured `.schema` for reflection:
```python=
>>> metadata_obj.reflect(someengine)
```

The end result is that `Table` objects from the "project" schema  will be reflected, and they will be populated as schema-qualified with that name:
```python=
metadata_obj.tables['project.messages']
Table('messages', MetaData(), Column('message_id', INTEGER(), table=<messages>), schema='project')
```
Similarly, an individual Table object that includes the Table.schema parameter will also be reflected from that database schema, overriding any default schema that may have been configured on the owning MetaData collection:
```python=
messages = Table('messages', metadata_obj, schema="project", autoload_with=someengine)
messages
Table('messages', MetaData(), Column('message_id', INTEGER(), table=<messages>), schema='project')
```

Finally, the `MetaData.reflect()` method itself also allows a `MetaData.reflect.schema` parameter to be passed, so we could also load tables from the “project” schema for a default configured `MetaData` object:
```python=
>>> metadata_obj = MetaData()
>>> metadata_obj.reflect(someengine, schema="project")
```

We can call `MetaData.reflect()` any number of times with different `MetaData.schema` arguments (or none at all) to continue populating the `MetaData` object with more objects:
```python=
>>> # add tables from the "customer" schema
>>> metadata_obj.reflect(someengine, schema="customer")
>>> # add tables from the default schema
>>> metadata_obj.reflect(someengine)
```

