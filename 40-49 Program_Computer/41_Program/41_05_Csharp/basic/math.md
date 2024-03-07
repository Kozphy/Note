# math

## Math.Pow(double 底數,double 幾次方)

## Math.Sqrt(double 指定數字)

## Math.Log()
- Math.Log(double x)以e = 2.718為底
- Math.Log(double 數字,double 底數)以後方數字為底
- Math.Log10(double x)，以10為底
- Math.Log2(double x)，以2為底

## Math.Sin(double x)

## 無條件進位
### Math.Ceiling() 正數
```csharp
double aa = Math.Ceiling(6.4);//輸出7
double aa1= Math.Ceiling(6.5);//輸出7
double aa2 = Math.Ceiling(6.9);//輸出7
```

### Math.Floor() 負數
```csharp
double aa3 = Math.Floor(-6.4);//輸出-7
double aa4 = Math.Floor(-6.5);//輸出-7
double aa5 = Math.Floor(-6.9);//輸出-7
```

## 無條件捨去
- method 1 Math.Floor()
```csharp
double aa = Math.Floor(6.4);//輸出6
double aa1 = Math.Floor(6.5);//輸出6
double aa2 = Math.Floor(6.9);//輸出6
```

- method 2
```csharp
int aa = (int)6.4;//輸出6
int aa1 = (int)6.5;//輸出6
int aa2 = (int)6.9;//輸出6
```

- method 3
```csharp
Console.WriteLine(Math.Truncate(2.1));//輸出2

Console.WriteLine(Math.Truncate(3.8));//輸出3
```

## 四捨五入 (奇進偶捨)
1. 尾數 `1~4` 會捨去，`6~9` 會進位(與四捨五入相同)。如: `4.4` 取整數會變成 `4`，`4.6` 取整數會變成 `5`
2. 如果尾數是 `5`，後方有其他數字，則 `5` 會進位(與四捨五入相同)。如: `4.501` 取整數會變成 `5`
3. 如果尾數是 `5`，後方也沒有其他數字，進位與否則看尾數5的前一位是誰，奇數則進位，偶數則捨去。如: `4.5` 取整數會變成 `4`，`5.5` 取整數會變成 `6`
### `Convert.ToInt32()` (要四捨五入到整數的時候) 採奇進偶捨
```csharp
//正數
int aa3 = Convert.ToInt32(6.4);//輸出6
int aa4 = Convert.ToInt32(6.5);//輸出6<--沒有進位
int aa5 = Convert.ToInt32(6.9);//輸出7
int aa7 = Convert.ToInt32(7.4);//輸出7
int aa8 = Convert.ToInt32(7.5);//輸出8<--有進位
int aa9 = Convert.ToInt32(7.9);//輸出8
//負數
int aa3 = Convert.ToInt32(-6.4);//輸出-6
int aa4 = Convert.ToInt32(-6.5);//輸出-6<--沒有進位
int aa5 = Convert.ToInt32(-6.9);//輸出-7
int aa7 = Convert.ToInt32(-7.4);//輸出-7
int aa8 = Convert.ToInt32(-7.5);//輸出-8<--有進位
int aa9 = Convert.ToInt32(-7.9);//輸出-8
```

### Math.Round(Double,小數點第幾位,取的方法)
- 宣告須為 `double`，取的方法有兩種:
- `MidpointRounding.AwayFromZero` → 等同現實生活的四捨五入(向外捨入零)
- `MidpointRounding.ToEven` → 四捨六入五成雙(預設)

```csharp
//正數
double aa3 = Math.Round(6.4);//輸出6
double aa4 = Math.Round(6.5);//輸出6<--沒有進位
double aa5 = Math.Round(6.9);//輸出7
double aa7 = Math.Round(7.4);//輸出7
double aa8 = Math.Round(7.5);//輸出8<--有進位
double aa9 = Math.Round(7.9);//輸出8
//負數
double aa3 = Math.Round(-6.4);//輸出-6
double aa4 = Math.Round(-6.5);//輸出-6<--沒有進位
double aa5 = Math.Round(-6.9);//輸出-7
double aa7 = Math.Round(-7.4);//輸出-7
double aa8 = Math.Round(-7.5);//輸出-8<--有進位
double aa9 = Math.Round(-7.9);//輸出-8

//四捨五入到指定小數位，並使用MidpointRounding.AwayFromZero方法
double aa3 = Math.Round(-6.45,1, MidpointRounding.AwayFromZero);
//四捨五入到小數第一位，採MidpointRounding.AwayFromZero，輸出-6.5
double aa4 = Math.Round(-6.55,1, MidpointRounding.AwayFromZero);
//四捨五入到小數第一位，採MidpointRounding.AwayFromZero，輸出-6.6
```