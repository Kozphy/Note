# Calling Tasks
###### tags: `python module`

### task.add
You can call a task using the **delay()** method:
```python=
from proj.tasks import add

add.delay(2, 2)
```
### task.apply_async
This method is actually a star-argument shortcut to another method called **apply_async()**:
```python=
add.apply_async((2, 2))
```
The latter enables you to specify execution options like the time to run (countdown), the queue it should be sent to, and so on:
```python=
add.apply_async((2, 2), queue='lopri', countdown=10)
```

In the above example the task will be sent to a queue named `lopri` and the task will execute, at the earliest, 10 seconds after the message was sent.

### task()
Applying the task directly will execute the task in the current process, so that no message is sent:
```python=
add(2, 2)
4
```

A more detailed overview of the Calling API can be found in the [**Calling User Guide**](https://docs.celeryq.dev/en/stable/userguide/calling.html#guide-calling).

---
### AsyncResult
**The delay and apply_async methods return an AsyncResult instance**, which can be used to keep track of the tasks execution state. **But for this you need to enable a result backend so that the state can be stored somewhere**.


If you have a result backend configured you can retrieve the return value of a task:
```python=
res = add.delay(2,2)
res.get(timeout=1)
```

### AsyncResult id
Every task invocation will be given a unique identifier (an UUID) – this is the task id.

You can find the task’s **id** by looking at the id attribute:
```python=
res.id
d6b3aea2-fb9b-4ebc-8da4-848818db9114
```

### AsyncResult exception
You can also inspect the exception and traceback if the task raised an exception, in fact result.get() will propagate any errors by default:
```python=
>>> res = add.delay(2, '2')
>>> res.get(timeout=1)
```
```
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
  File "celery/result.py", line 221, in get
    return self.backend.wait_for_pending(
  File "celery/backends/asynchronous.py", line 195, in wait_for_pending
    return result.maybe_throw(callback=callback, propagate=propagate)
  File "celery/result.py", line 333, in maybe_throw
    self.throw(value, self._to_remote_traceback(tb))
  File "celery/result.py", line 326, in throw
    self.on_ready.throw(*args, **kwargs)
  File "vine/promises.py", line 244, in throw
    reraise(type(exc), exc, tb)
  File "vine/five.py", line 195, in reraise
    raise value
TypeError: unsupported operand type(s) for +: 'int' and 'str'
```
### AsyncResult.get
If you don’t wish for the errors to propagate, you can disable that by passing propagate:
```python=
>>> res.get(propagate=False)
TypeError("unsupported operand type(s) for +: 'int' and 'str'")
```
### AsyncResult.failed and successful
In this case it’ll return the exception instance raised instead – so to check whether the task succeeded or failed, you’ll have to use the corresponding methods on the result instance:
```python=
>>> res.failed()
True

>>> res.successful()
False
```

### AsyncResult.state
Every task invocation will be given a unique identifier (an UUID) – this is the task id.
```python=
res.state
```

### task state
A task can only be in a single state, but it can progress through several states. The stages of a typical task can be:
```
PENDING -> STARTED -> SUCCESS
```

The started state is a special state that’s only recorded if the **task_track_started** setting is enabled, or if the @task(track_started=True) option is set for the task.


### task pending state
The pending state is actually not a recorded state, but rather the default state for any task id that’s unknown: this you can see from this example:
```python=
>>> from proj.celery import app

>>> res = app.AsyncResult('this-id-does-not-exist')
>>> res.state
'PENDING'
```

### task in retry stage
If the task is retried the stages can become even more complex. To demonstrate, for a task that’s retried two times the stages would be:
```
PENDING -> STARTED -> RETRY -> STARTED -> RETRY -> STARTED -> SUCCESS
```