# setuptools quickstart

## [Source](https://setuptools.pypa.io/en/latest/userguide/quickstart.html)

## install

```cmd
pip install --upgrade setuptools
```

When creating new Python packages, it is recommended to use a command line tool called build.

```cmd
pip install --upgrade build
```

This will allow you to run the cmd: `python -m build`

Every python package must provide a `pyproject.toml` and specify the backend (build system) it wants to use.

## Basic Use

When creating a Python package, you must provide a pyproject.toml file containing a `build-system` section.

```
[build-system]
requires = ["setuptools"]
build-backend = "setuptools.build_meta"
```

This section declares what are your build system dependencies, and which library will be used to actually do the packaging.
