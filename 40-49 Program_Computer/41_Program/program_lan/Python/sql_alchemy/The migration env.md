# The migration env
###### tags: `database learn`
```
yourproject/
    alembic/
        env.py
        README
        script.py.mako
        versions/
            3512b954651e_add_account.py
            2b1ae634e5cd_add_order_id.py
            3adcc9a56557_rename_username_field.py
```

The directory includes these directories/files:
- yourproject - this is the root of your application’s source code, or some directory within it.
- env.py - This is a Python script that is run whenever the alembic migration tool is invoked. At the very least, it contains instructions to configure and generate a SQLAlchemy engine, procure a connection from that engine along with a transaction, and then invoke the migration engine, using the connection as a source of database connectivity.
> The exact specifics of how to connect are here, as well as the specifics of how the migration environment are invoked. 
- README - included with the various environment templates, should have something informative.
- script.py.mako - This is a Mako template file which is used to generate new migration scripts.
- version/ - This directory holds the individual version scripts. Users of other migration tools may notice that the files here don’t use ascending integers, and instead use a partial GUID approach.