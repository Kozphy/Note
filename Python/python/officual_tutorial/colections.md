# collections

## [Source](https://docs.python.org/3/library/collections.html)

## defaultdict

Return a new **dictionary-like object**.

The first argument provides the initial value for the `default_factory` attribute; it defaults to `None`. All remaining arguments are treated the same as if they were passed to the **dict constructor, including keyword arguments**.

### defaultdict Examples

Using list as the default_factory, it is easy to **group a sequence of key-value pairs into a dictionary of lists**:

```python
>>> s = [('yellow', 1), ('blue', 2), ('yellow', 3), ('blue', 4), ('red', 1)]
>>> d = defaultdict(list)
>>> for k, v in s:
        d[k].append(v)

>>> sorted(d.items())
[('blue', [2, 4]), ('red', [1]), ('yellow', [1, 3])]
```

When each key is encountered for the first time, it is not already in the mapping; so an entry is automatically created using the `default_factory` function which returns an empty `list`. The **list.append()** operation then attaches the value to the new list.

The `defaultdict` is faster than `dict.setdefault()` showing as following:

```python
>>> d = {}
>>> for k, v in s:
        d.setdefault(k, []).append(v)
>>> sorted(d.items())
[('blue', [2, 4]), ('red', [1]), ('yellow', [1, 3])]
```

Setting `default_factory` to `int`:

```python
>>> s = "mississippi"
>>> d = defaultdict(int)
>>> for k in s:
        d[k] += 1
>>> sorted(d.items())
[('i', 4), ('m', 1), ('p', 2), ('s', 4)]
```

## Counter object

A Counter is a **dict subclass for counting hashable objects**.

It is a collection where **elements are stored as dictionary keys and their counts are stored as dictionary values**.

Counts are **allowed to be any integer value including zero or negative counts**.

- elements()
- most_common()
- subtract()
- total()
- fromkeys()
- update()
