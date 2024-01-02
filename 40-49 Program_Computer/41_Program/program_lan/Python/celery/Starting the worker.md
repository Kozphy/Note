# Starting the worker
###### tags: `python module`

The celery program can be used to start the worker (you need to run the worker in the directory above proj):
```cmd=
$ celery -A [module_name] worker -l INFO
```


When the worker starts you should see a banner and some messages:
![](https://i.imgur.com/bWArnYa.png)

- Concurrency is the number of prefork worker process used to process your tasks concurrently. The default concurrency number is the number of CPU’s on that machine (including cores). 

- Events is an option that causes Celery to send monitoring messages (events) for actions occurring in the worker.
- Queues is the list of queues that the worker will consume tasks from.

## In the background
In production you’ll want to run the worker in the background, described in detail in the daemonization tutorial.

The daemonization scripts uses the **celery multi** command to start one or more workers in the background:

```cmd=
$ celery multi start w1 -A proj -l INFO
celery multi v4.0.0 (latentcall)
> Starting nodes...
    > w1.halcyon.local: OK
```

You can restart it too:
```cmd=
$ celery  multi restart w1 -A proj -l INFO
celery multi v4.0.0 (latentcall)
> Stopping nodes...
    > w1.halcyon.local: TERM -> 64024
> Waiting for 1 node.....
    > w1.halcyon.local: OK
> Restarting node w1.halcyon.local: OK
celery multi v4.0.0 (latentcall)
> Stopping nodes...
    > w1.halcyon.local: TERM -> 64052
```
or stop it:
```cmd=
$ celery multi stop w1 -A [module_name] -l INFO
```

The **stop** command is asynchronous so it won’t wait for the worker to shutdown. You’ll probably want to use the stopwait command instead, which ensures that all currently executing tasks are completed before exiting:
```cmd=
$ celery multi stopwait w1 -A [module_name] -l INFO
```

By default it’ll create pid and log files in the current directory. To protect against multiple workers launching on top of each other you’re encouraged to put these in a dedicated directory:
```python=
$ mkdir -p /var/run/celery
$ mkdir -p /var/log/celery
$ celery multi start w1 -A proj -l INFO --pidfile=/var/run/celery/%n.pid \
                                        --logfile=/var/log/celery/%n%I.log
```

With the multi command you can start multiple workers, and there’s a powerful command-line syntax to specify arguments for different workers too.
```cmd=
$ celery multi start 10 -A proj -l INFO -Q:1-3 images,video -Q:4,5 data \
    -Q default -L:4,5 debug
```
