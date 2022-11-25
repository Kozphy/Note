# pandas data structure
###### tags: `python learn`


## Series
Series is a one-dimensional labeled array capable of holding any data type (integers, strings, floating point numbers, Python objects, etc.).

The axis labels are collectively referred to as the **index**.

### create Series
```python=
s = pd.Series(data, index=index)
```

data can be many different things:
- a python list
- an ndarray
- a scalar value (like 5)
#### From ndarray
If `data` is an ndarray, **index** must be the same length as **data**. If no index is passed, one will be created having values `[0, ..., len(data) - 1]`.
```python=
s = pd.Series(np.random.randn(5), index=["a", "b", "c", "d", "e"])
```

#### From dict
Series can be instantiated from dicts:
```python=
d = {"b": 1, "a": 0, "c": 2}
pd.Series(d)

```

If an index is passed, the values in data corresponding to the labels in the index will be pulled out.
```python=
d = {"a": 0.0, "b": 1.0, "c": 2.0}
pd.Series(d)

pd.Series(d, index=["b", "c", "d", "a"])

```

### From scalar value
If `data` is a scalar value, an index must be provided. The value will be repeated to match the length of **index**.
```python=
pd.Series(5.0, index=["a", "b", "c", "d", "e"])
```

### Series is ndarray-like
`Series` acts very similarly to a `ndarray`, and is a valid argument to most NumPy functions. However, operations such as slicing will also slice the index.

### Series is dict-like
A Series is like a fixed-size dict in that you can get and set values by index label

## Name attribute
Series can also have a name attribute:
```python=
s = pd.Series(np.random.randn(5), name="something")
s.name
```
You can rename a Series with the `pandas.Series.rename()` method.
```python=
s2 = s.rename("different")
s2.name
```
Note that `s` and `s2` refer to different objects.

## DataFrame
DataFrame is a 2-dimensional labeled data structure with columns of potentially different types. You can think of it like a spreadsheet or SQL table, or a dict of Series objects. It is generally the most commonly used pandas object. Like Series, DataFrame accepts many different kinds of input:
- Dict of 1D ndarrays, lists, dicts, or Series
- 2-D numpy.ndarray
- Structured or record ndarray
- A Series
- Another DataFrame

Along with the data, you can optionally pass **index** (row labels) and **columns** (column labels) arguments. If you pass an index and / or columns, you are guaranteeing the index and / or columns of the resulting DataFrame.

### From dict of Series or dicts
The resulting **index** will be the **union** of the indexes of the various Series. If there are any nested dicts, these will first be converted to Series. If no columns are passed, the columns will be the ordered list of dict keys.
```python=
d = {
    "one": pd.Series([1.0, 2.0, 3.0], index=["a", "b", "c"]),
    "two": pd.Series([1.0, 2.0, 3.0, 4.0], index=["a", "b", "c", "d"]),
}
df = pd.DataFrame(d)
pd.DataFrame(d, index=["d", "b", "a"])
pd.DataFrame(d, index=["d", "b", "a"], columns=["two", "three"])
```

### From dict of ndarrays / lists
