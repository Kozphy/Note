# logging module
###### tags: `python module`

## logging level
- DEBUG: Detailed information, typically of interest only when diagnosing problems.

- INFO: Confirmation that things are working as expected.

- WARNING: An indication that something unexpected happened, or indicative of some problem in the near future (e.g. ‘disk space low’). The software is still working as expected.

- ERROR: Due to a more serious problem, the software has not been able to perform some function.

- CRITICAL: A serious error, indicating that the program itself may be unable to continue running.

By default, the logging level will only show **WARNING, ERROR, CRITICAL** level and print the info in command prompt, so we need to set **logging.basicConfig**.

## setting logging.basicConifg
When setting following, programme will create **test.log** file and record the debug level.

**basicConfig** is setting the root logger.
```python=
logging.basicConfig(filename='test.log', level = logging.DEBUG, format='%(asctime)%s:%(levelname)s:%(message)s')

```

while using format, You can refer to the documentation for [LogRecord attributes](https://docs.python.org/3/library/logging.html#logrecord-attributes)

## Displaying the date/time in messages
```python=
import logging
logging.basicConfig(format='%(asctime)s %(message)s')
logging.warning('is when this event was logged.')
2010-12-12 11:41:42,612 is when this event was logged.
```
The default format for date/time display (shown above) is like ISO8601 or RFC 3339. If you need more control over the formatting of the date/time, provide a datefmt argument to basicConfig, as in this example:
```python=
import logging
logging.basicConfig(format='%(asctime)s %(message)s', datefmt='%m/%d/%Y %I:%M:%S %p')
logging.warning('is when this event was logged.')
12/12/2010 11:46:36 AM is when this event was logged.
```

## Advanced Logging
The logging library takes a modular approach and offers several categories of components: loggers, handlers, filters, and formatters.

- Loggers expose the interface that application code directly uses.
- Handlers send the log records (created by loggers) to the appropriate destination.
- Filters provide a finer grained facility for determining which log records to output.
- Formatters specify the layout of log records in the final output.

A good convention to use when naming loggers is to use a module-level logger, in each module which uses logging, named as follows:
```python=
logger = logging.getLogger(__name__)
```

This means that logger names track the package/module hierarchy, and it’s intuitively obvious where events are logged just from the logger name.

By default, no destination is set for any logging messages.  If no destination is set; and if one is not set, they will set a destination of the console (**sys.stderr**) and a default format for the displayed message before delegating to the root logger to do the actual message output.

The most widely used methods on logger objects fall into two categories: **configuration** and **message sending**.

These are the most common configuration methods:
- [Logger.setLevel()](https://docs.python.org/3/library/logging.html#logging.Logger.setLevel) specifies the lowest-severity log message a logger will handle, where debug is the lowest built-in severity level and critical is the highest built-in severity. For example, if the severity level is INFO, the logger will handle only INFO, WARNING, ERROR, and CRITICAL messages and will ignore DEBUG messages.

- [Logger.addHandler()](https://docs.python.org/3/library/logging.html#logging.Logger.addHandler) and [Logger.removeHandler()](https://docs.python.org/3/library/logging.html#logging.Logger.removeHandler) add and remove handler objects from the logger object. Handlers are covered in more detail in [Handlers](https://docs.python.org/3/howto/logging.html#handler-basic).

- [Logger.addFilter()](https://docs.python.org/3/library/logging.html#logging.Logger.addFilter) and [Logger.removeFilter()](https://docs.python.org/3/library/logging.html#logging.Logger.removeFilter) add and remove filter objects from the logger object. Filters are covered in more detail in [Filter Objects](https://docs.python.org/3/library/logging.html#filter).


