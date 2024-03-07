# Numpy 合併操作
###### tags: `python learn`


# 合併操作
將數個多維陣列，合併成一個
```python=
# 合併第一個維度
np.vstack((陣列一, 陣列二),...)

# 合併第二個維度
np.hstack((陣列一，陣列二),...)
```

## 範例
```python=
# 1 x 2
arr1 = np.array([
    [3,4]
])

# 1 x 2
arr2 = np.array([
    [5,6]
])

# [[3,4],[5,6]]
# 2 x 2
result1 = np.vstack((arr1,arr2))

# [[3,4,5,6]]
# 1 x 4
result2 = np.hstack((arr1,arr2))

```