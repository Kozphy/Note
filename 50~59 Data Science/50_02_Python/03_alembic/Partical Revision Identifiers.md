# Partical Revision Identifiers
###### tags: `database learn`

Any time we need to refer to a revision number explicitly, we have the option to use a partial number. As long as this number uniquely identifies the version, it may be used in any command in any place that version numbers are accepted:
```cmd
$ alembic upgrade ael
```
Above, we use `ae1` to refer to revision `ae1027a6acf`. Alembic will stop and let you know if more than one version starts with that prefix.

