# celery application
###### tags: `python module`

## what is celery application
The first thing you need is a Celery instance. We call this the Celery application or just app for short. 

As this instance is used as the **entry-point for everything you want to do in Celery**, like creating tasks and managing workers, it must be possible for other modules to import it.

Let’s create the file tasks.py:
```python=
from celery import Celery

app = Celery('tasks', broker='pyamqp://guest@localhost//')

@app.task
def add(x, y):
    return x + y
```

The first argument to **Celery** is the name of the current module.

The second argument is the broker keyword argument, specifying the URL of the message broker you want to use.

