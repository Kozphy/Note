# annotation
###### tags: `haskell`

## annotation
```haskell
-- 單行註譯
{-
	多行註譯
-}
```

## expression
- 有值的式子
```haskell
1
True
3 :: Float
sort [3,8,1,4]
case Foo of True -> 1
			False -> 2
```

## 宣告
- :: 加入型別
- = 綁定
- Haskell 沒有變數與指定值，只有綁定，綁定不能改變
- Haskell 沒有條件，迴圈，分支，在 Haskell 中都是 expression 的一部分
```haskell
welcomeMsg :: String
welcomMsg = "hello world"
```

## 函數
- 函數分為 **普通函數** 和中綴(中序)函數
- 普通函數呼叫方法是函數 + 參數
- 中綴函數與加減乘除類似，先寫第一參數+函數+第二參數
- 普通函數呼叫優先順序最高
```haskell
print "hello world"
-- 普通函數

2 + 3
-- 中綴函數

(+) 1.5 2.5
-- 中綴函數當作普通函數

Foo == False
-- 中綴函數

Bar /= True
-- 中綴函數，判斷是否不相等

[1] ++ [] ++ [2,3,4]
-- 中綴函數，連接串列

elem 3 [1,2,3]
-- 普通函數

3 `elem` [1,2,3]
-- 把普通函數 轉換成 中綴函數
```
## 結合 infix(不結合), infixl(左結合), infixr(右結合)
- 中綴函數優先順序從 0 到 9，數字越大優先度越高，與結合性一起定義。
- 再執行函數時，先考慮優先順序，再考慮結合性，來決定那一種函數先執行
```haskell
{-
中輟函數的優先性與結合性定義

infixl 6 +

infixl 7 *

infixr 8 ^

infix 4 `elem`
-}

2 + 3 * 4
-- == 2 + (3 * 4)
-- * 比 + 優先性高

2 ^ 3 ^ 4
-- /= (2 ^ 3) ^ 4
-- 優先性相同，因此考慮結合性， ^ 是 右結合，因此 2 ^ (3 ^ 4)

x `elem` xs `elem` ys
-- `elem` 優先性相同，但 `elem` 無法結合，報錯，除非加上括弧
```

## 命名規則
- Haskell 統一使用駝峰式命名法
- 中綴函數不能以 : 開頭

## GHCI
- ghc 互動命令模式
- 因為 ghci 是處於連續運算中，後面綁定可以覆蓋前面的榜定，但一定要再前面加 let
```haskell
let xs = [2,3,4,1]
import Data.List
sort xs
let xs = [2,2,2,3,4]
nub xs
```
- ghci 基本命令
```haskell
:? 查看所有命令幫助
:q 退出 ghci
:l 載入 *.hs 檔案到目前 session
:t 顯示 expression 型別
:i 顯示版定的詳細資訊 (運算子優先順序)
```
