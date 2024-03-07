# Appendix A
###### tags: `data analysis`

## A.3 Broadcasting
*Broadcasting* describes how arithmetic works between arrays of different shapes.

The simplest example of broadcasting occurs when combining a scalar value with an array:
```python=
In [79]: arr = np.arange(5)
In [80]: arr
Out[80]: array([0, 1, 2, 3, 4])

In [81]: arr * 4
Out[81]: array([ 0, 4, 8, 12, 16])
```
Here we say that the scalar value 4 has been *broadcast* to all of the other elements in the multiplication operation.

For example, we can demean each column of an array by subtracting the column means. In this case, it is very simple:
```python=
In [82]: arr = np.random.randn(4, 3)
In [83]: arr.mean(0)
Out[83]: array([-0.3928, -0.3824, -0.8768])

In [84]: demeaned = arr - arr.mean(0)
In [85]: demeaned
Out[85]:
array([[ 0.3937, 1.7263, 0.1633],
 [-0.4384, -1.9878, -0.9839],
 [-0.468 , 0.9426, -0.3891],
 [ 0.5126, -0.6811, 1.2097]])

In [86]: demeaned.mean(0)
Out[86]: array([-0., 0., -0.])
```
See Figure **A-4** for an illustration of this operation.

This brings us to:
> ## The Broadcasting Rule
> Two arrays are compatible for broadcasting if for each trailing dimension (i.e., starting from the end) the axis lengths match or if either of the lengths is 1. Broadcasting is then performed over the missing or length 1 dimensions.

![](https://i.imgur.com/j9iUhaR.png)

According to the rules, to subtract over axis 1 (i.e., subtract the row mean from each row), the smaller array must have shape (4, 1):
```python=
In [87]: arr
Out[87]:
array([[ 0.0009, 1.3438, -0.7135],
 [-0.8312, -2.3702, -1.8608],
 [-0.8608, 0.5601, -1.2659],
 [ 0.1198, -1.0635, 0.3329]])

In [88]: row_means = arr.mean(1)
In [89]: row_means.shape
Out[89]: (4,)

In [90]: row_means.reshape((4, 1))
Out[90]:
array([[ 0.2104],
 [-1.6874],
 [-0.5222],
 [-0.2036]])

In [91]: demeaned = arr - row_means.reshape((4, 1))
In [92]: demeaned.mean(1)
Out[92]: array([ 0., -0., 0., 0.])
```

![](https://i.imgur.com/0VmUL8h.png)

See **Figure A-6** for another illustration, this time adding a two-dimensional array to a three-dimensional one across axis 0.
![](https://i.imgur.com/yLYwMu8.png)

## Broadcasting Over Other Axes
It’s quite common to want to perform an arithmetic operation with a lower dimensional array across axes other than axis 0 According to the broadcasting rule, the “broadcast dimensions” must be 1 in the smaller array. In the example of row demeaning shown here, this meant reshaping the row means to be shape **(4, 1)** instead of **(4,)**:
```python=
In [94]: arr - arr.mean(1).reshape((4, 1))
Out[94]:
array([[-0.2095, 1.1334, -0.9239],
 [ 0.8562, -0.6828, -0.1734],
 [-0.3386, 1.0823, -0.7438],
 [ 0.3234, -0.8599, 0.5365]])
```

A common problem, therefore, is needing to add a new axis with length 1 specifically for broadcasting purposes. Using **reshape** is one option, but inserting an axis requires constructing a tuple indicating the new shape.

Thus, NumPy arrays offer a special syntax for inserting new axes by indexing. We use the special **np.newaxis** attribute along with “full” slices to insert the new axis:
```python=
In [95]: arr = np.zeros((4, 4))
In [96]: arr_3d = arr[:, np.newaxis, :]
In [97]: arr_3d.shape
Out[97]: (4, 1, 4)

In [98]: arr_1d = np.random.normal(size=3)
In [99]: arr_1d[:, np.newaxis]
Out[99]:
array([[-2.3594],
 [-0.1995],
 [-1.542 ]])

In [100]: arr_1d[np.newaxis, :]
Out[100]: array([[-2.3594, -0.1995, -1.542 ]])
```

![](https://i.imgur.com/uCZI3au.png)
