# Working with pep 582

## [Source](https://pdm.fming.dev/2.2/usage/pep582/#vscode)

## intro

With PEP 582, dependencies will be installed into `__pypackages__` directory under the project root.

### PEP 582 abstract

This PEP proposes to add to Python a mechanism to automatically recognize a `__pypackages__` directory and prefer importing packages installed in this location over user or global site-packages. This will __avoid the steps to create, activate or deactivate “virtual environments”__. Python will use the **`__pypackages__`** from the base directory of the script when present.

## Enable PEP 582 globally (in linux and mac)

To make the Python interpreters aware of PEP 582 packages, one need to add the `pdm/pep582/sitecustomize.py` to the Python library search path.

The command to change the environment variables can be printed by `pdm --pep582 [<SHELL>]`.

if `<SHELL>` isn't given, PDM will pick one based on some guess.

```cmd
eval "$(pdm --pep582)"
```

### take effective when logging in

```cmd
pdm --pep582 >> ~/.bash_profile
```

You need to restart terminal session to take affect.

## Configure IDE to support PEP 582

Now there are no built-in support or plugins for PEP 582 in most IDEs, you have to configure your tools manually.

PDM will write and store project-wide configurations in `.pdm.toml` and you are recommended to add following lines in the `.gitignore`:

```git
.pdm.toml
__pypackages__/
```

### VsCode

Add the following two entries to the top-level dict in `.vscode/settings.json`:

```json
{
  "python.autoComplete.extraPaths": ["__pypackages__/<major.minor>/lib"],
  "python.analysis.extraPaths": ["__pypackages__/<major.minor>/lib"]
}
```

This file can be auto-generated with plugin [pdm-vscode](https://github.com/frostming/pdm-vscode).
