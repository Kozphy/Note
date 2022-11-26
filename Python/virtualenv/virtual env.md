# virtual env
###### tags: `python module`

[virtuanlenv and virtualenv_envwrapper](https://docs.python-guide.org/dev/virtualenvs/)
[conda virtual env](https://docs.conda.io/projects/conda/en/latest/user-guide/tasks/manage-environments.html)

## what is virtula env purpose
virtual env intended to seperate out the packages, dependencies and the versions that you're going to use from project

## create virtual env
```cmd
virtualenv <name>
```

## create env with specific python version
```cmd
virtualenv -p /usr/bin/<python> <projectName>
```

## remove virtual env
```cmd
sudo rm -rf <envname>
```

## Enter created virtual env
```cmd
source <name>/bin/activate
```

## check which python and pip be used
```cmd=
which python
which pip
```

## use global site package to create requirement.txt
```cmd
pip freezze --local > requirement.txt
```

## install requirement.txt package
```cmd
pip install -r requirement.txt
```

## get out env
```python=
deactivate
```




