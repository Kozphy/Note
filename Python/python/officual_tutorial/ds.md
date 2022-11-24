# Data Structures

## [Source](https://docs.python.org/3/tutorial/datastructures.html#list-comprehensions)

## More on Lists

- list.append()
- list.extend()
- list.insert()
- list.remove()
- list.pop()
- list.clear()
- list.index()
- list.count()
- list.sort()
- list.reverse()
- list.copy()

## List Comprehensions

```python
>>> [(x, y) for x in [1,2,3] for y in [3,1,4] if x != y]
[(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]
```

equivalent to:

```python
combs = []
for x in [1,2,3]:
    for y in [3,1,4]:
        if x != y:
            combs.append((x, y))

>>> combs
[(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]
```
