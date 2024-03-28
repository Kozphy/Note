# Numpy 維度、形狀操作
###### tags: `python learn`

## 維度與形狀
維度: 資料的層次
形狀: 同時表達資料的層次，和每個層次的資料數量

```python=
# (8,)
[1,2,3,4,5,6,7,8] 

# (2,4)
[
    [1,2,3,4],
    [5,6,7,8]
]

# (2,2,2)
[
    [[1,2],[3,4]],
    [[5,6],[7,8]
]
```

## 取得資料形狀
```python=
data = np.array([3,4,1])
data.shape # (3,)
data = np.array([
    [2,4],
    [1,5]
])

# (2,2)
data.shape
```

## 資料轉置
```python=
data = np.array([
    [2,4,1],
    [1,5,0]
])
# (2,3)
data.shape

# (3,2) 反過來
data.T.shape
```

## 扁平化資料
把多維度的資料打平成一維陣列
```python=
data = np.array([
    [[1,2],[3,4]],
    [[5,6],[7,8]]
])

# [1,2,3,4,5,6,7,8]
data.ravel()
```

## 重塑資料的形狀
資料總數量必須要一樣
```python=
# 2 x 2 x 2 = 8
data = np.array([
    [[1,2],[3,4]],
    [[5,6],[7,8]]
])
# 4x2=8
data.reshape(4,2)

# 3x3=9 錯誤
data.reshape(3,3)

data=np.zeros(18).reshape(2,3,3)
```