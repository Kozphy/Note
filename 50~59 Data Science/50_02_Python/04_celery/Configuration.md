# Configuration
###### tags: `python module`

The default configuration should be good enough for most use cases, but there are many options that can be configured to make Celery work exactly as needed. Reading about the options available is a good idea to familiarize yourself with what can be configured. You can read about the options in the [**Configuration and defaults**](https://docs.celeryq.dev/en/stable/userguide/configuration.html#configuration) reference.

The configuration can be set on the app directly or by using a dedicated configuration module. As an example you can configure the default serializer used for serializing task payloads by changing the [**task_serializer**](https://docs.celeryq.dev/en/stable/userguide/configuration.html#std-setting-task_serializer) setting:
```python=
app.conf.task_serializer = 'json'
```

If you’re configuring many settings at once you can use update:
```python=
app.conf.update(
    task_serializer='json',
    accept_content=['json'],  # Ignore other content
    result_serializer='json',
    timezone='Europe/Oslo',
    enable_utc=True,
)
```

For larger projects, a dedicated configuration module is recommended. Hard coding periodic task intervals and task routing options is discouraged. 

It is much better to keep these in a centralized location. This is especially true for libraries, as it enables users to control how their tasks behave.

You can tell your Celery instance to use a configuration module by calling the [**app.config_from_object()**](https://docs.celeryq.dev/en/stable/reference/celery.html#celery.Celery.config_from_object) method:
```python=
app.config_from_object('celeryconfig')
```
This module is often called “celeryconfig”, but you can use any module name.

In the above case, a module named celeryconfig.py must be available to load from the current directory or on the Python path. It could look something like this:
```celeryconfig.py:```
```python=
broker_url = 'pyamqp://'
result_backend = 'rpc://'

task_serializer = 'json'
result_serializer = 'json'
accept_content = ['json']
timezone = 'Europe/Oslo'
enable_utc = True
```

To verify that your configuration file works properly and doesn’t contain any syntax errors, you can try to import it:
```python=
$ python -m celeryconfig
```

For a complete reference of configuration options, see [**Configuration and defaults**](https://docs.celeryq.dev/en/stable/userguide/configuration.html#configuration).

To demonstrate the power of configuration files, this is how you’d route a misbehaving task to a dedicated queue:
```celeryconfig.py```
```python=
task_routes = {
    'tasks.add': 'low-priority',
}
```

Or instead of routing it you could rate limit the task instead, so that only 10 tasks of this type can be processed in a minute (10/m):
```celeryconfig.py```
```python=
task_annotations = {
    'tasks.add': {'rate_limit': '10/m'}
}
```

See [**Routing Tasks**](https://docs.celeryq.dev/en/stable/userguide/routing.html#guide-routing) to read more about task routing, and the [**task_annotations**](https://docs.celeryq.dev/en/stable/userguide/routing.html#guide-routing) setting for more about annotations, or [**Monitoring and Management Guide**](https://docs.celeryq.dev/en/stable/userguide/monitoring.html#guide-monitoring) for more about remote control commands and how to monitor what your workers are doing.

