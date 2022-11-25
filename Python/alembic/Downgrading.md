# Downgrading
###### tags: `database learn`

We can illustrate a downgrade back to nothing, by calling alembic downgrade back to the beginning, which in Alembic is called `base`:
```cmd=
$ alembic downgrade base
```

Back to nothing - and up again:
```cmd=
$ alembic upgrade head
```
