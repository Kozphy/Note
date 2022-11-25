# Working with virtualenv

## [Source](https://pdm.fming.dev/latest/usage/venv/)

## VirtualEnv

Virtual environments will be used if the project interpreter(the interpreter stored in **.pdm.toml**, which can be checked by **pdm info**) is from a virtualenv.

## Virtualenv auto-creation

When you run `pdm install` the first time on a new PDM-managed project, whose Python interpreter is not decided yet, PDM will create a virtualenv in `<project_root>/.venv`, and install dependencies into it.

You can choose the following backend used by PDM

- `virtualenv` (default)
- `venv`
- `conda`

You can change it by `pdm config venv.backend [virtualenv|venv|conda]`

## create virtualenv

```cmd
# Assign a different name other than the version string
pdm venv create --name for-test 3.8

# Use venv as the backend to create, support 3 backend virtualenv(default), venv, conda
pdm venv create --with venv 3.9
```

## List all virtualenvs created with this project

```cmd
pdm venv list
```

## Remove a virtualenv

```cmd
pdm venv remove <ProjectName>
```

## Using virtualenv

```cmd
eval $(pdm venv activate <venvName>)
```

`venv activate` does **not switch the Python interpreter used by the project**. It only changes the shell by **injecting** the virtualenv paths to environment variables.

Use `pdm use` to switch python interpreter.

When you activate a virtualenv, the prompt will show: **{project_name}-{python_version}**.

if your project is named **test-project**:

```cmd
$ eval $(pdm venv activate test-project)
(test-project-3.10)
```

The prompt name can be changed by following

- `venv.prompt` configuration
- `PDM_VENV_PROMPT` (before a `pdm init` or `pdm venv create`)

```cmd
PDM_VENV_PROMPT='{project_name}-py{python_version}' pdm venv create --name test-prompt

eval $(pdm venv activate test-prompt)
```

## deactivate virtualenv

```cmd
pdm config
```

## The location of virtualenvs

For the first time, PDM will try to create a virtualenv in project, unless `.venv` already exists.

**Other virtualenvs file go to the location specified by** the `venv.location` config, which are named as `<project_name>--<path_hash>--<name_or_python_version>`.

A virtualenv created with `--name` option will always go to this location.

You can `disable` the in-project virtualenv creation by `pdm config venv.in_project false`.
