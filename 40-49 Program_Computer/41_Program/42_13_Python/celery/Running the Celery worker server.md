# Running the Celery worker server
###### tags: `python module`

You can now run the worker by executing our program with the worker argument:
```cmd
$ celery -A [module_name] worker --loglevel=INFO
```

In production you’ll want to run the worker in the background as a daemon.  To do this you need to use the tools provided by your platform, or something like **supervisord** (see [Daemonization](https://docs.celeryq.dev/en/stable/userguide/daemonizing.html#daemonizing) for more information).

