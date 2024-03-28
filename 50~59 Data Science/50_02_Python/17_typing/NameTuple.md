# NameTuple

## [Source](https://docs.python.org/3/library/typing.html)

## collections.namedtuple()

```python
class Employee(NamedTuple):
    name: str
    id: int
```

which is equivalant to

```python
Employee = collections.namedtuple('Employee', ['name', 'id'])
```

To give a field a default value, you can assign to it in the class body:

```python
class Employee(NamedTuple):
    name: str
    id: int = 3

employee = Employee("Guido")
assert employee.id == 3
```

The resulting class has an extra attribute `__annotations__` giving a dict that maps the field names to the field types.

(The field names are in the `_fields` attribute and the default values are in the `_field_defaults` attribute, both of which are part of the namedtuple() API.)

`NamedTuple` subclasses can also have docstrings and methods:

```python
class Employee(NamedTuple):
    """
    Represents on employee.
    """
    name: str
    id: int = 3

    def __repr__(self) -> str:
        return f'<Employee {self.name}, id={self.id}>'
```

`NamedTuple` subclasses can be **generic**:

```python
class Group(NamedTuple, Generic[T]):
    key: T
    group: list[T]

Employee = NamedTuple('Employee', [('name', str), ('id', int)])
```
