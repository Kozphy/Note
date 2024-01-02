# Canvas: Designing Work-flows
###### tags: `python module`

## pass signature of task invocation
### what is signature
Sometimes you may want to pass the signature of a task invocation to another process or as an argument to another function, for which Celery uses something called **signatures**.

A signature wraps the arguments and execution options of a single task invocation in such a way that it can be passed to functions or even serialized and sent across the wire.
### create signature
You can create a signature for the add task using the arguments (2, 2), and a countdown of 10 seconds like this:
```python=
add.signature((2,2), countdown=10)
tasks.add(2,2)
```

There's also  a shortcut using start arguments
```python=
add.s(2,2)
```

## call with signature instance
### call with complete signature
Signature instances also support the calling API, meaning they have **delay** and **apply_async** methods.

The add task takes two arguments, so a signature specifying two arguments would make a complete signature:
```python=
sl = add.s(2,2)
res = s1.delay()
res.get()
```

### call with incomplete signatures
```python=
# incomplete partial: add(?, 2)
s2 = add.s(2)
```

s2 is now a partial signature that needs another argument to be complete, and this can be resolved when calling the signature:
```python=
# resolves the partial: add(8, 2)
res = s2.delay(8)
res.get()
```

### call signatures with keyword arguments
Keyword arguments can also be added later; these are then merged with any existing keyword arguments, but with new arguments taking precedence:
```python=
s3 = add.s(2,2, debug=True)
s3.delay(debug=False) # debug is now False
```

### signatures support the calling api
- sig.apply_async(args=(), kwargs={}, **options)

Calls the signature with optional partial arguments and partial keyword arguments. Also supports partial execution options.

- sig.delay(*args, **kwargs)

Star argument version of apply_async. Any arguments will be prepended to the arguments in the signature, and keyword arguments is merged with any existing keys

## how to use signature with canvas primitives
### The Primitives
- group
- map
- chain
- starmap
- chord
- chunks

These primitives are signature objects themselves, so they can be combined in any number of ways to compose complex work-flows.

### Groups
A group calls a list of tasks in parallel, and it returns a special result instance that lets you inspect the results as a group, and retrieve the return values in order.
```python=
>>> from celery import group
>>> from proj.tasks import add

>>> group(add.s(i, i) for i in range(10))().get()
[0, 2, 4, 6, 8, 10, 12, 14, 16, 18]
```

- Partial group
```python=
>>> g = group(add.s(i) for i in range(10))
>>> g(10).get()
[10, 11, 12, 13, 14, 15, 16, 17, 18, 19]
```

### Chains
Tasks can be linked together so that after one task returns the other is called:
```python=
>>> from celery import chain
>>> from proj.tasks import add, mul

# (4 + 4) * 8
>>> chain(add.s(4, 4) | mul.s(8))().get()
64
```

- Partial chain
```python=
>>> # (? + 4) * 8
>>> g = chain(add.s(4) | mul.s(8))
>>> g(4).get()
64
```

Chains can also be written like this:
```python=
>>> (add.s(4, 4) | mul.s(8))().get()
64
```

### Chords
A chord is a group with a callback:
```python=
>>> from celery import chord
>>> from proj.tasks import add, xsum

>>> chord((add.s(i, i) for i in range(10)), xsum.s())().get()
90
```

A group chained to another task will be automatically converted to a chord:
```python=
>>> (group(add.s(i, i) for i in range(10)) | xsum.s())().get()
90
```

Since these primitives are all of the signature type they can be combined almost however you want, for example:
```python=
>>> upload_document.s(file) | group(apply_filter.s() for filter in filters)
```

### Routing
Celery supports all of the routing facilities provided by AMQP, but it also supports simple routing where messages are sent to named queues.

The [**task_routes**](https://docs.celeryq.dev/en/stable/userguide/configuration.html#std-setting-task_routes) setting enables you to route tasks by name and keep everything centralized in one location:
```python=
app.conf.update(
    task_routes = {
        'proj.tasks.add': {'queue': 'hipri'},
    },
)
```
You can also specify the queue at runtime with the queue argument to **apply_async**:
```python=
>>> from proj.tasks import add
>>> add.apply_async((2, 2), queue='hipri')
```

You can then make a worker consume from this queue by specifying the **celery worker -Q** option:
```cmd=
$ celery -A proj worker -Q hipri
```

You may specify multiple queues by using a comma-separated list. 
```cmd=
$ celery -A proj worker -Q hipri,celery
```
The order of the queues doesn’t matter as the worker will give equal weight to the queues.

## Remote Control
If you’re using RabbitMQ (AMQP), Redis, or Qpid as the broker then you can control and inspect the worker at runtime.

For example you can see what tasks the worker is currently working on:
```cmd=
$ celery -A [module_name] inspect active
```

This is implemented by using broadcast messaging, so all remote control commands are received by every worker in the cluster.

You can also specify one or more workers to act on the request using the **--destination** option. This is a comma-separated list of worker host names:
```cmd=
$ celery -A proj inspect active --destination=celery@example.com
```

If a destination isn’t provided then every worker will act and reply to the request.

The **celery inspect** command contains commands that don’t change anything in the worker; it only returns information and statistics about what’s going on inside the worker.

Then there's the **celery control** cmd, which contains commands that actually change things in the worker at runtime:
```cmd=
$ celery -A proj control --help
```

The **celery status** command also uses remote control commands and shows a list of online workers in the cluster:
```cmd=
$ celery -A proj status
```
