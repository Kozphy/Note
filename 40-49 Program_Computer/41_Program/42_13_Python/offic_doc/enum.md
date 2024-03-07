# Enum

## Source

[offic_doc](https://docs.python.org/3/library/enum.html)

## intro

An Enum is a set of symbolic names bound to unique values.

They are similar to `global variables`, but they offer a more useful `repr()`, grouping, `type-safety`, and a few other features.

Can be created by **class syntax or functional syntax**.

```python
from enum import Enum

# class syntax
class Color(Enum):
    RED = 1
    GREEN = 2
    BLUE = 3

# functional syntax
Color = Enum('Color', ['RED', 'GREEN', 'BLUE'])
```

## automatic value

```python
from enum import Enum, auto
class Color(Enum):
    RED = auto()
    BLUE = auto()
    GREEN = auto()
```

## iteration

```python
[color.name for color in Color]
[color.value for color in Color]
[(color.name, color.value), for color in Color]
```

```python
for name, color in Color.__members__.items():
    name, color
...
('RED', <Color.RED: 1>)
('GREEN', <Color.GREEN: 2>)
('BLUE', <Color.BLUE: 3>)
```
