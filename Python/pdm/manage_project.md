# Manage project

## [Source](https://pdm.fming.dev/latest/usage/project/)

## setting python interpreter

```cmd
pdm init
```

## change setting

```cmd
pdm use <python_version_or_path>
```

The argument can be either a `version specifier of any length`, or a `relative or absolute path to the python interpreter`, but remember the Python interpreter must conform with the `requires-python` constraint in the project file.

## How `requires-python` controls the project

PDM respects the value of `requires-python` in the way that it tries to pick package candidates that can work on all python versions that `requires-python` contains.

### application or library

1. if `project.name` field is **not empty** in `pyproject.toml` which pdm will consider as library.
2. A library can be built by `pdm build` or other PEP 517 builders, and itself will be installed in editable mode every time you execute `pdm sync` or `pdm install`, unless opted out with `--no-self` option.

## Build distribution artifacts

```cmd
pdm build
```

The artifacts will be available at `dist/` and able to upload to PyPI.

## Configure the project

Show the current configurations:

```cmd
pdm config
```

Get one single configuration:

```cmd
pdm config pypi.url
```

Change a configuration value **globally** and store in home configuration:

```cmd
pdm config pypi.url "https://test.pypi.org/simple"
```

By default, the configuration are **changed globally**, if you want to make the config seen by this project only, add a `--local` flag:

```cmd
pdm config --local pypi.url "https://test.pypi.org/simple"
```

Any local configurations will be stored in `.pdm.toml` under the project root directory.

The configuration files are searched in the following order:

1. `<PROJECT_ROOT>/.pdm.toml` - The project configuration
2. `<CONFIG_ROOT>/config.toml` - The home configuration
3. `<SITE_CONFIG_ROOT>/config.toml` - The site configuration

## Show the current python env

```cmd
$ pdm info

$ pem info --env
```
