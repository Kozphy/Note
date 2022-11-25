# Calling the task
###### tags: `python module`

To call our task you can use the **delay()** method.

This is a handy shortcut to the **apply_async()** method that gives greater control of the task execution (see **Calling Tasks**):
```python=
from tasks import add
add.delay(4,4)
```

The task has now been processed by the worker you started earlier. You can verify this by looking at the worker’s console output.

Calling a task returns an [**AsyncResult**](https://docs.celeryq.dev/en/stable/reference/celery.result.html#celery.result.AsyncResult) instance. This can be used to check the state of the task, wait for the task to finish, or get its return value.

Results are not enabled by default. **In order to do remote procedure calls or keep track of task results** in a database, **you will need to configure Celery to use a result backend**.