# basic
###### tags: `python learn`

## 一維陣列
```python=
import numpy as np
## 建立陣列
ndarr = np.array([3, 4, -2])
print(ndarr)
print(ndarr.size)
## 三個空間，未指定資料
np.empty(3)
## 建立一微陣列，3 個空間都是 0
np.zeros(3)
## 建立資料ㄧ維陣陣列，3 個空間，裡面都是 1
np.ones(3)
## 建立連續資料的一維陣列，10 個空間，連續資料
np.arange(10)
```
## 二維陣列
```python=
np.array([
    [1,2],
    [3,2],
    [5,0]

])
np.empty([3,2])
np.zeros([3,2])
np.ones([3,2])
```

## 三維陣列
```python=
np.array([
    [
        [5,2,4],[1,2,8]
    ],[
        [3,8,2],[4,1,3]
    ]
])

np.empty(2,2,3)
np.zeros[2,2,3]
```

## 四維陣列
超過三個維度的概念，需要完全以邏輯推演
```python=
np.array([
    [
        [
            [3,2],
            [5,4]
        ]
    ]
])

```