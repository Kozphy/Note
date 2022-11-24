# pyproject.toml

## PEP 621 Metadata

### [Source](https://pdm.fming.dev/latest/pyproject/pep621/)

### intro

The project metadata are stored in the `pyproject.toml`

In the following part of this document, metadata should be written under `[project]` table if not given explicitly.

### Multiline description

```toml
description = """\
    Lorem ipsum dolor sit amet, consectetur adipiscing elit, \
    sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. \
    Ut enim ad minim veniam, quis nostrud exercitation ullamco \
    laboris nisi ut aliquip ex ea commodo consequat.\
"""
```

### Dependency specification

The project.dependencies is an array of dependency specification strings following the `PEP 440` and `PEP 508`

```toml
[project]
...
dependencies = [
    # Named requirement
    "requests",
    # Named requirement with version specifier
    "flask >= 1.1.0",
    # Requirement with environment marker
    "pywin32; sys_platform == 'win32'",
    # URL requirement
    "pip @ git+https://github.com/pypa/pip.git@20.3.1"
]

```

### Console scripts (Entry points)

#### [Reference of entry points](https://setuptools.pypa.io/en/latest/userguide/entry_point.html)

```toml
[project.scripts]
mycli = "mycli.__main__:main"
```

Other type of entry points:

```toml
[project.entry-points.pytest11]
myplugin = "mypackage.plugin:pytest_plugin"

[project.entry-points."flake8.extension"]
myplugin = "mypackage.plugin:flake8_plugin"
```

---

## Build configuration

### [Source](https://pdm.fming.dev/latest/pyproject/build/)

### intro

`pdm` uses the PEP 517 to build the package.

To use it, include the following in your `pyproject.toml`(It will be done automatically if you use the `pdm init` or `pdm import` to create the file):

```toml
[build-system]
requires = ["pdm-pep517"]
build-backend = "pdm.pep517.api"
```

### Static version

```toml
[project]
version = "1.0.0"
```

### Dynamic version

`pdm-pep517` supports dynamic versions from two sources. To enable dynamic versioning, remember to include `version` in the `dynamic` field of PEP 621 metadata:

```toml
[project]
...
dynamic = ["version"]
```

### Dynamic version from file

```toml
[tool.pdm]
version = { source = "file", path = "mypackage/__version__.py" }
```

The backend will search for the pattern `__version__ = "{version}"` in the given file and use the value as the version.

 Above is equal following

```toml
[tool.pdm.version]
source = "file"
path = "mypackage/__version__.py"
```

or

```toml
[tool.pdm]
version.source = "file"
version.path = "mypackage/__version__.py"
```

### include and exclude files

To include extra files and/or exclude files from the distribution, give the paths in `includes` and `excludes` configuration, as glob patterns:

```toml
[tool.pdm.build]
includes = [
    "**/*.json",
    "mypackage/",
]
excludes = [
    "mypackage/_temp/*"
]
```

you want some files to be included in `source`

```toml
[tool.pdm.build]
includes = [...]
excludes = [...]
source-includes = ["tests/"]
```

Note that the files defined in `source-includes` will be **excluded** automatically from binary distributions.
