# Getting information
###### tags: `database learn`

With a few revisions present we can get some information about the state of things.

### view the current revision:
```cmd=
$ alembic current
```

`head` is displayed only if the revision identifier for this database matches the head revision.

### view history
We can also view history with `alembic history`; the `--verbose` option (accepted by several commands, including `history`, `current`, `heads` and `branches`) will show us full information about each revision:
```cmd=
$ alembic history --verbose
```

