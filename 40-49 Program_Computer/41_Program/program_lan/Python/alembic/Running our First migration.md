# Running our First migration
###### tags: `database learn`

We now want to run our migration. Assuming our database is totally clean, it’s as yet unversioned. The `alembic upgrade` command will run upgrade operations, proceeding from the current database revision, in this example None, to the given target revision.

We can specify `revision identifiers` as the revision we’d like to upgrade to, but it’s easier in most cases just to tell it “the most recent”, in this case `head`:
```cmd
alembic upgrade head
```

The process which occurred here included that Alembic first checked if the database had a table called `alembic_version`, and if not, created it. It looks in this table for the current version, if any, and then calculates the path from this version to the version requested, in this case head, which is known to be `revision identifers`. It then invokes the `upgrade()` method in each file to get to the target revision.
