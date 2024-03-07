# Numpy 多維陣列運算
###### tags: `python learn`

## 逐元運算(elementwise)
```python=
data1 = np.array([3,4,1])
data2 = np.array([-2,5,-8])
data1 + data2
data1 - data2
data1 * data2
data1 / data2
data1 > data2
data1 == data2
data1 <= data2
```

## 矩陣運算(matrix)
```python=
data1 = np.array([
    [2,1]
]) # 1 x 2

data2 = np.array([
    [3,2,0],[3,1,-1]
]) # 2 x 3

## 內積 ! x 3
data1.dot(data2)
## 內積
data1@data2
## 外積 2 x 6
np.outer(data1,data2)
```

## 統計運算(statistics)
```python=
data = np.array([
    [2,1,7],
    [3,-5,8]
])
# 全部加總
data.sum()
# 加總 column
data.sum(axis=0)
# 加總 row
data.sum(axis=1)
# 全部最小值
data.min()
# 逐值累加
data.cumsum()
# 平均數
data.mean()
# 標準差
data.std()
```