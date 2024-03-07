# Numpy 切割操作
###### tags: `python learn`

## 切割操作
```python=
# 根據第一個維度切割
np.vsplit(陣列,切割數量)
# 根據第二個維度切割
np.hsplit(陣列,切割數量)
```

## 範例
```python=
# 2 x 4
arr=np.array([
    [1,2,3,4],
    [5,6,7,8]
])

# [[1,2,3,4]]
# 1 x 4
# [[5,6,7,8]]
# 1 x 4
result1 = np.vsplit(arr,2)

# [[1,2],[5,6]]
# 2 x 2
# [[3,4],[7,8]]
# 2 x 2
result2 = np.hsplit(arr,2)

```