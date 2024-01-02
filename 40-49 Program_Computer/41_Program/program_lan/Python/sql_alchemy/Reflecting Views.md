# Reflecting Views
###### tags: `database learn`

The reflection system can also reflect views. Basic usage is the same as that of a table:
```python=
my_view = Table("some_view", metadata, autoload_with=engine)
```

Above, `my_view` is a `Table` object with `Column` objects representing the names and types of each column within the view “some_view”.

Usually, it’s desired to have at least a primary key constraint when reflecting a view, if not foreign keys as well. View reflection doesn’t extrapolate these constraints.

```python=
my_view = Table("some_view", metadata,
                Column("view_id", Integer, primary_key=True),
                Column("related_thing", Integer, ForeignKey("othertable.thing_id")),
                autoload_with=engine
)
```