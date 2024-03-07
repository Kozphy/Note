# Manage dependencies

## [Source](https://pdm.fming.dev/latest/usage/dependency/)

## init project

```cmd
pdm init
```

## Add dependencies

```cmd
pdm add requests
```

Using  `-G/--group <name> option` to get several dependency which will add dependencies to `[project.optional-dependencies.<name>]` in pyproject.toml.

```toml
[project]
name = "foo"
version = "0.1.0"

[project.optional-dependencies]
socks = ["pysocks"]
jwt = ["pyjwt"]
all = ["foo[socks,jwt]"]

```

You can view `pdm.lock` to see the resolved result of all dependencies.

### Local dependencies

Local packages can be added with their paths. The `path` can be a `file or a directory`:

```cmd
pdm add ./sub-package
pdm add ./first-1.0.0-py2.py3-none-any.whl
```

The paths MUST start with a `.`, otherwise it will be recognized as a normal named requirement.

### Add development only dependencies

PDM also supports defining groups of dependencies that are useful for development.

We usually **don't want these dependencies appear in the distribution's metadata** so using optional-dependencies is probably not a good idea.

```cmd
pdm add -dG test pytest
```

This will result in `pyproject.toml` as following:

```toml
[tool.pdm.dev-dependencies]
test = ["pytest"]
```

## update existing dependencies

To update all dependencies in lock file:

```cmd
pdm update
```

To update the specified package(s):

```cmd
pdm update requests
```

To update multiple groups of dependencies:

```cmd
pdm update -G security -G http
```

## Remove dependencies

```cmd
# Remove requests from the default dependencies
pdm remove requests
# Remove h11 from the 'web' group of optional-dependencies
pdm remove -G web h11
# Remove pytest-cov from the `test` group of dev-dependencies
pdm remove -dG test pytest-cov
```

## install the packages pinned in lock file

There are a few similar commands to do this job with slight differences

- `pdm sync` installs packages from the lock file.
- `pdm update` will update lock file, then `sync`
- `pdm install` will check the project file for changes, update the lock file if needed, then `sync`.

`sync` also has a few options to manage installed packages:

- `--clean`: will remove packages no longer in the lockfile
- `--only-keep`: only selected packages (using options like `-G` or `--prod`) will be kept.

## show what packages are installed

```cmd
pdm list
```
