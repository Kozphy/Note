# The initialization of the `sys.path` module search pat

## [Source](https://docs.python.org/3/library/sys_path_init.html#sys-path-init)

## intro

A module search path is initialized when Python starts. This module search path may be accessed at `sys.path`.

### sys.path

A list of strings that specifies the search path for modules. Initialized from the environment variable `PYTHONPATH`, plus an installation-dependent default.

By default, as initialized upon program startup, a **potentially unsafe path** is **prepended to sys.path** (before the entries inserted as a result of `PYTHONPATH`):

- `python -m module`: prepend the **current working directory**.
- `python script.py`: prepend the **script's directory**. If it's a symbolic link, resolve symbolic links.
- `python -c code` and `python` (REPL):  prepend an **empty string**, which means the **current working directory**.

**To not prepend this potentially unsafe path**, use the `-P` command line option `or` the `PYTHONSAFEPATH` environment variable.

A program is **free to modify** this list for its own purposes. **Only strings should be added to `sys.path`**; all other data types are ignored during import.

> See also

- Module `site` This describes how to use `.pth` files to extend `sys.path`
