# Using Celery in your Application
###### tags: `learn cpp`

## Our Project
```project layout```
```=
proj/__init__.py
    /celery.py
    /tasks.py
```

```proj/celery.py```
```python=
from celery import Celery

app = Celery('proj',
             broker='amqp://',
             backend='rpc://',
             include=['proj.tasks'])

# Optional configuration, see the application user guide.
app.conf.update(
    result_expires=3600,
)

if __name__ == '__main__':
    app.start()
```

- The broker argument specifies the URL of the broker to use.
- The backend argument specifies the result backend to use. 
    - It’s used to keep track of task state and results.
- The **include** argument is a list of modules to import when the worker starts. You need to add our tasks module here so that the worker is able to find our tasks.


```proj/tasks.py```
```python=
from .celery import app


@app.task
def add(x, y):
    return x + y


@app.task
def mul(x, y):
    return x * y


@app.task
def xsum(numbers):
    return sum(numbers)
```

