# Auto Generating Migration
###### tags: `database learn`

### Auto generating migration script
Alembic can view the status of the database and compare against the table metadata in the application, generating the “obvious” migrations based on a comparison. This is achieved using the `--autogenerate` option to the `alembic revision`command, which places so-called **candidate** migrations into our new migrations file.


To use autogenerate, we first need to modify our `env.py`so that it gets access to a table metadata object that contains the target. Suppose our application has a declarative base in `myapp.mymodel`. This base contains a **MetaData** object which contains **Table** objects defining our database. We make sure this is loaded in `env.py` and then passed to **EnvironmentContext.configure()** via the `target_metadata` argument.
```python=
from myapp.mymodel import Base
target_metadata = Base.metadata
```
> Note:
>  The above example refers to the **generic alembic env.py template**, e.g. the one created by default when calling upon `alembic init`, and not the special-use templates such as `multidb`.

If we look later in the script, down in `run_migrations_online()`, we can see the directive passed to **EnvironmentContext.configure()**:
```python=
def run_migrations_online():
    engine = engine_from_config(
                config.get_section(config.config_ini_section), prefix='sqlalchemy.')

    with engine.connect() as connection:
        context.configure(
                    connection=connection,
                    target_metadata=target_metadata
                    )

        with context.begin_transaction():
            context.run_migrations()
```
We can then use the `alembic revision` command in conjunction with the `--autogenerate` option.
```cmd=
$ alembic revision --autogenerate -m "Added account table"
```

We can then view our file `27c6a30d7c24.py` and see that a rudimentary migration is already present: