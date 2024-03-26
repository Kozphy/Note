#Developer 

- `djangoapp`: Contains the django app
- `djangoproj`: Contains the project configuration
- `frontend`: HTML and CSS and React front end

## install mamba
[01_install mamba](01_install%20mamba.md)

## Environment setup
### create mamba env
```python
 mamba create -n xrwvm-fullstack_developer_capstone python=3.10
```

### conda mamba env
```python
conda activate xrwvm-fullstack_developer_capstone
```

### install dependency
```python
python -m pip install -U -r requirements.txt

```
### migrate
```python
python manage.py makemigrations
python manage.py migrate
```




