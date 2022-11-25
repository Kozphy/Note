# Parameter Types
###### tags: `click python module`

Click supports two types of parameters for scripts: options and arguments.

## Differences
The following features are only available for options:
- automatic prompting for missing input
- act as flags (boolean or otherwise)
- option values can be pulled from environment variables, arguments can not
- options are fully documented in the help page, arguments are not (this is intentional as arguments might be too specific to be automatically documented)

## Parameter types
Parameters can be of different types. Types can be implemented with different behavior and some are supported out of the box:

- `str` / click.STRING:
    - The default parameter type which indicates unicode strings.
- `int` / click.INT
    - A parameter that only accepts integers.
- `float` / click.FLOAT
    - A parameter that only accepts floating point values.
- `bool` / click.BOOL
    - A parameter that accepts boolean values. This is automatically used for boolean flags. The string values “1”, “true”, “t”, “yes”, “y”, and “on” convert to True. “0”, “false”, “f”, “no”, “n”, and “off” convert to False.
- click.UUID
    - A parameter that accepts UUID values. This is not automatically guessed but represented as uuid.UUID.

- class click.File(mode='r', encoding=None, errors='strict', lazy=None, atomic=False)
Declares a parameter to be a file for reading or writing. 