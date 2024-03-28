# setuptools quick start
###### tags: `python setuptools module`

## setup.cfg
```cfg=
[metadata]
name = fastapi_learn
version = 0.0.1

[options]
package_dir=
    =app
packages = find:
include_package_data=True
install_requires = 
    python_version>="3.10.4"


[options.packages.find]
where=app
include = *

[options.entry_points]
console_scripts = 
    api_service = cmds.api_services:cli
```

## pyproject.toml
```toml=
[build-system]
requires = ["setuptools"]
build-backend = "setuptools.build_meta"
```

## development mode
```cmd=
pip install --editable .
```