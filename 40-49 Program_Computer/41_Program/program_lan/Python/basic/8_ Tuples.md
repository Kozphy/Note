# 8: Tuples
###### tags: `python learn`

##  Tuples are immutable
A tuple is a sequence of values much like a list. The values stored in a tuple can be any type, and they are indexed by integers. The important difference is that tuples are
immutable. Tuples are also comparable and hashable so we can sort lists of them and use tuples as key values in Python dictionaries

```python=
>>> t = 'a', 'b', 'c', 'd', 'e'
>>> t = ('a', 'b', 'c', 'd', 'e')
```

To create a tuple with a single element, you have to include the final comma:
```python=
>>> t1 = ('a',)
>>> type(t1)
<type 'tuple'>
```

Without the comma Python treats ('a') as an expression with a string in parentheses that evaluates to a string:
```python=
>>> t2 = ('a')
>>> type(t2)
<type 'str'>
```

Another way to construct a tuple is the built-in function tuple. With no argument, it creates an empty tuple:
```python=
>>> t = tuple()
>>> print(t)
()
```

Most list operators also work on tuples. The bracket operator indexes an element:
```python=
>>> t = ('a', 'b', 'c', 'd', 'e')
>>> print(t[0])
'a'
>>> print(t[1:3])
('b', 'c')
>>> t[0] = 'A'
TypeError: object doesn't support item assignment
```
You can’t modify the elements of a tuple, but you can replace one tuple with another:
```python=
>>> t = ('A',) + t[1:]
>>> print(t)
('A', 'b', 'c', 'd', 'e')
```

## Comparing tuples
he comparison operators work with tuples and other sequences. Python starts by comparing the first element from each sequence. If they are equal, it goes on to the next element, and so on, until it finds elements that differ. Subsequent elements are not considered (even if they are really big.

```python=
>>> (0, 1, 2) < (0, 3, 4)
True
>>> (0, 1, 2000000) < (0, 3, 4)
True
```

