# Viewing History Range
###### tags: `database learn`

### view history with -r option
Using the `-r` option to `alembic history`, we can also view various slices of history. The `-r` argument accepts an argument `[start]:[end]`, where either may be a revision number, symbols like head, `heads` or `base`, `current` to specify the current revision(s), as well as negative relative ranges for `[start]` and positive relative ranges for `[end]`:
```cmd=
$ alembic history -r1975ea:ae1027
```
A relative range starting from three revs ago up to current migration.
```cmd=
$ alembic history -r-3:current
```

> Note:
> As illustrated above, to use ranges that start with a negative number (i.e. a dash), due to a bug in argparse , either the syntax `-r-<base>:<head>`, without any space, must be used as above or if using `--rev-range`, an equals sign must be used:
>  ```cmd=
>  $ alembic history --rev-range=-3:current
>  ```
>  Using quotes or escape symbols will not work if there’s a space after the argument name.

View all revisions from 1975 to the `head`:
```cmd=
$ alembic history -r1975ra:
```
