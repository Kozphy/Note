# Relative Migration Identifiers
###### tags: `database learn`

Relative upgrades/downgrades are also supported. To move two versions from the current, a decimal value “+N” can be supplied:
```cmd=
$ alembic upgrade +2
```

Negative values are accepted for downgrades:
```cmd=
$ alembic downgrade -1
```

Relative identifiers may also be in terms of a specific revision. For ex, to upgrade to revision `ae1027a6acf` plus two additional steps:
```cmd=
$ alembic upgrade ae10+2
```


