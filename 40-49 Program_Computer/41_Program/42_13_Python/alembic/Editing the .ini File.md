# Editing the .ini File
###### tags: `database learn`
### .ini file
Alembic placed a file `alembic.ini` into the current directory. This is a file that the `alembic` script looks for when invoked. This file can exist in a different directory, with the location to it specified by either the `--config` option for the `alembic` runner or the `ALEMBIC_CONFIG` environment variable (the former takes precedence).

```
# A generic, single database configuration.

[alembic]
# path to migration scripts
script_location = alembic

# template used to generate migration file names; The default value is %%(rev)s_%%(slug)s
# Uncomment the line below if you want the files to be prepended with date and time
# file_template = %%(year)d_%%(month).2d_%%(day).2d_%%(hour).2d%%(minute).2d-%%(rev)s_%%(slug)s

# sys.path path, will be prepended to sys.path if present.
# defaults to the current working directory.
# (new in 1.5.5)
prepend_sys_path = .

# timezone to use when rendering the date within the migration file
# as well as the filename.
# If specified, requires the python-dateutil library that can be
# installed by adding `alembic[tz]` to the pip requirements
# string value is passed to dateutil.tz.gettz()
# leave blank for localtime
# timezone =

# max length of characters to apply to the
# "slug" field
# truncate_slug_length = 40

# set to 'true' to run the environment during
# the 'revision' command, regardless of autogenerate
# revision_environment = false

# set to 'true' to allow .pyc and .pyo files without
# a source .py file to be detected as revisions in the
# versions/ directory
# sourceless = false

# version location specification; This defaults
# to ${script_location}/versions.  When using multiple version
# directories, initial revisions must be specified with --version-path.
# The path separator used here should be the separator specified by "version_path_separator" below.
# version_locations = %(here)s/bar:%(here)s/bat:${script_location}/versions

# version path separator; As mentioned above, this is the character used to split
# version_locations. The default within new alembic.ini files is "os", which uses os.pathsep.
# If this key is omitted entirely, it falls back to the legacy behavior of splitting on spaces and/or commas.
# Valid values for version_path_separator are:
#
# version_path_separator = :
# version_path_separator = ;
# version_path_separator = space
version_path_separator = os  # Use os.pathsep. Default configuration used for new projects.

# the output encoding used when revision files
# are written from script.py.mako
# output_encoding = utf-8

sqlalchemy.url = driver://user:pass@localhost/dbname

# [post_write_hooks]
# This section defines scripts or Python functions that are run
# on newly generated revision scripts.  See the documentation for further
# detail and examples

# format using "black" - use the console_scripts runner,
# against the "black" entrypoint
# hooks = black
# black.type = console_scripts
# black.entrypoint = black
# black.options = -l 79 REVISION_SCRIPT_FILENAME

# Logging configuration
[loggers]
keys = root,sqlalchemy,alembic

[handlers]
keys = console

[formatters]
keys = generic

[logger_root]
level = WARN
handlers = console
qualname =

[logger_sqlalchemy]
level = WARN
handlers =
qualname = sqlalchemy.engine

[logger_alembic]
level = INFO
handlers =
qualname = alembic

[handler_console]
class = StreamHandler
args = (sys.stderr,)
level = NOTSET
formatter = generic

[formatter_generic]
format = %(levelname)-5.5s [%(name)s] %(message)s
datefmt = %H:%M:%S
```

The file is read using Python’s **ConfigParser.SafeConfigParser** object. The `%(here)s` variable is provided as a substitution variable, which can be used to produce absolute pathnames to directories and files.

The file contains the following features:
### [alembic]
- `[alembic]` - this is the section read by Alembic to determine configuration. Alembic’s core implementation does not directly read any other areas of the file, not including additional directives that may be consumed from the end-user-customizable `env.py` file.
> Note:
> The default env.py file included with Alembic’s environment templates will also read from the logging sections `[logging], [handlers]` etc. **If the configuration file in use does not contain logging directives, please remove the `fileConfig()` directive within the generated `env.py` file** to prevent it from attempting to configure logging.

- `script_location` - this is the location of the Alembic environment. **It is normally specified as a filesystem location, either relative or absolute**. If the location is a relative path, it’s interpreted as relative to the current directory.

The generation of the `.ini` file by the command alembic init alembic automatically placed the directory name alembic here. The special variable %(here)s can also be used, as in `%(here)s/alembic`.

- `file_tamplate` -  this is the naming scheme used to generate new migration files. Uncomment the presented value **if you would like the migration files to be prepended with date and time**, so that they are listed in chronological order. The default value is %%(rev)s_%%(slug)s. Tokens available include:
    - `%%(rev)s` - revision id
    - `%%(slug)s` - a truncated string derived from the revision message
    - `%%(year)d, %%(month).2d`, `%%(day).2d`, `%%(hour).2d`, `%%(second).2d` - components of the create date, by default `datetime.datetime.now()` unless the timezone configuration option is also used.
    - `timezone` -  an optional timezone name (e.g. `UTC`, `EST5EDT`, etc.) that will be applied to the timestamp which renders inside the migration file’s comment as well as within the filename. This option requires installing the `python-dateutil` library. If timezone is specified, the create date object is no longer derived from `datetime.datetime.now()` and is instead generated as:
```python=
datetime.datetime.utcnow().replace(
      tzinfo=dateutil.tz.tzutc()
).astimezone(
    dateutil.tz.gettz(<timezone>)
)
```

- `sqlalchemy.url` - A URL to connect to the database via SQLAlchemy. This configuration value is only used if the `env.py` file calls upon them; in the “generic” template, the call to `config.get_main_option("sqlalchemy.url")` in the `run_migrations_offline()` function and the call to `engine_from_config(prefix="sqlalchemy.")` in the `run_migrations_online()` function are where this key is referenced. **If the SQLAlchemy URL should come from some other source, such as from environment variables or a global registry, or if the migration environment makes use of multiple database URLs, the developer is encouraged to alter the env.py file to use whatever methods** are appropriate in order to acquire the database URL or URLs.


- `revision_environment` -  this is a flag which when set to the value ‘true’, will **indicate that the migration environment script env.py should be run unconditionally** when generating new revision files, as well as when running the alembic history command.

- `sourceless` -  when set to ‘true’, revision files that only exist as `.pyc or` `.pyo` files in the versions directory will be used as versions, allowing “sourceless” versioning folders. When left at the default of ‘false’, only `.py` files are consumed as version files.

- `version_locations` - an optional list of revision file locations, to **allow revisions to exist in multiple directories simultaneously**.

- `version_path_seperator`  - a separator of `version_locations` paths. It should be defined if multiple `version_locations` is used.

- output_encoding - the encoding to use when Alembic writes the `script.py.mako` file into a new migration file. Default to `utf-8`

- `[loggers], [handlers], [formatters], [logger_*], [handler_*], [formatter_*]`- these sections are all part of Python’s standard logging configuration, the mechanics of which are documented at [Configuration File Format](https://docs.python.org/3/library/logging.config.html#configuration-file-format).