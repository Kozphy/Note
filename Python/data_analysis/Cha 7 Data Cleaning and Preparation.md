# Cha 7 Data Cleaning and Preparation
###### tags: `data analysis`

In this chapter I discuss tools for missing data, duplicate data, string manipulation, and some other analytical data transformations. In the next chapter, I focus on combining and rearranging datasets in various ways.

## Handling Missing data
For numeric data, pandas uses the floating-point value **NaN** (Not a Number) to represent missing data. We call this a sentinel value that can be easily detected:
```python=
In [10]: string_data = pd.Series(['aardvark', 'artichoke', np.nan, 'avocado'])

In [11]: string_data
Out[11]:
0 aardvark
1 artichoke
2 NaN
3 avocado
dtype: object

In [12]: string_data.isnull()
Out[12]:
0 False
1 False
2 True
3 False
dtype: bool
```

### Table 7-1
![](https://i.imgur.com/0hSKcnF.png)

## filtering Out Missing Dataq
While you always have the option to do it by hand using **pandas.isnull** and **boolean indexing**, the **dropna** can be helpful.

On a Series, it returns the Series with only the non-null data and index values:
```python=
In [15]: from numpy import nan as NA
In [16]: data = pd.Series([1, NA, 3.5, NA, 7])
In [17]: data.dropna()

Out[17]:
0 1.0
2 3.5
4 7.0
dtype: float64
```

This is equivalent to:
```python=
In [18]: data[data.notnull()]
Out[18]:
0 1.0
2 3.5
4 7.0
dtype: float64
```

With DataFrame object **pd.dropna** by default drops any row containing a missing value:
```python=
In [19]: data = pd.DataFrame([[1., 6.5, 3.], [1., NA, NA],
 ....: [NA, NA, NA], [NA, 6.5, 3.]])

In [20]: cleaned = data.dropna()

In [21]: data
Out[21]:
    0   1   2
0 1.0 6.5 3.0
1 1.0 NaN NaN
2 NaN NaN NaN
3 NaN 6.5 3.0

In [22]: cleaned
Out[22]:
    0   1   2
0 1.0 6.5 3.0
```

Passing how='all' will only drop rows that are all NA:
```python=
In [23]: data.dropna(how='all')
Out[23]:
    0   1   2
0 1.0 6.5 3.0
1 1.0 NaN NaN
3 NaN 6.5 3.0
```

To drop columns in the same way, pass axis=1:
```python=
In [24]: data[4] = NA
In [25]: data
Out[25]:
    0   1   2   4
0 1.0 6.5 3.0 NaN
1 1.0 NaN NaN NaN
2 NaN NaN NaN NaN
3 NaN 6.5 3.0 NaN

In [26]: data.dropna(axis=1, how='all')
Out[26]:
    0   1   2
0 1.0 6.5 3.0
1 1.0 NaN NaN
2 NaN NaN NaN
3 NaN 6.5 3.0
```

A related way to filter out DataFrame rows tends to concern time series data. Suppose you want to keep only rows containing a certain number of observations. You can indicate this with the thresh argument:
```python=
In [27]: df = pd.DataFrame(np.random.randn(7, 3))
In [28]: df.iloc[:4, 1] = NA
In [29]: df.iloc[:2, 2] = NA
In [30]: df
Out[30]:
          0         1         2
0 -0.204708       NaN       NaN
1 -0.555730       NaN       NaN
2  0.092908       NaN  0.769023
3  1.246435       NaN -1.296221
4  0.274992  0.228913  1.352917
5  0.886429 -2.001637 -0.371843
6  1.669025 -0.438570 -0.539741
In [31]: df.dropna()
Out[31]:
         0         1         2
4 0.274992  0.228913  1.352917
5 0.886429 -2.001637 -0.371843
6 1.669025 -0.438570 -0.539741

In [32]: df.dropna(thresh=2)
Out[32]:
         0         1         2
2 0.092908       NaN  0.769023
3 1.246435       NaN -1.296221
4 0.274992  0.228913  1.352917
5 0.886429 -2.001637 -0.371843
6 1.669025 -0.438570 -0.539741
```

## Filling In Missing Data
Rather than filtering out missing data (and potentially discarding other data along with it), you may want to fill in the “holes” in any number of ways. For most purposes, the **fillna** method is the workhorse function to use. Calling fillna with a constant replaces missing values with that value:
```python=
In[33]: df.fillna(0)
Out[33]:
          0         1         2
0 -0.204708  0.000000  0.000000
1 -0.555730  0.000000  0.000000
2  0.092908  0.000000  0.769023
3  1.246435  0.000000 -1.296221
4  0.274992  0.228913  1.352917
5  0.886429 -2.001637 -0.371843
6  1.669025 -0.438570 -0.539741
```

Calling **fillna** with a dict, you can use a different fill value for each column:
```python=
In [34]: df.fillna({1: 0.5, 2: 0})
Out[34]:
          0         1         2
0 -0.204708  0.500000  0.000000
1 -0.555730  0.500000  0.000000
2  0.092908  0.500000  0.769023
3  1.246435  0.500000 -1.296221
4  0.274992  0.228913  1.352917
5  0.886429 -2.001637 -0.371843
6  1.669025 -0.438570 -0.539741
```

**fillna** returns a new object, but you can modify the existing object in-place:
```python=
In [35]: _ = df.fillna(0, inplace=True)

In [36]: df
Out[36]:
 0 1 2
0 -0.204708 0.000000 0.000000
1 -0.555730 0.000000 0.000000
2 0.092908 0.000000 0.769023
3 1.246435 0.000000 -1.296221
4 0.274992 0.228913 1.352917
5 0.886429 -2.001637 -0.371843
6 1.669025 -0.438570 -0.539741
```

The same interpolation methods available for reindexing can be used with **fillna**:
```python=
In [37]: df = pd.DataFrame(np.random.randn(6, 3))

In [38]: df.iloc[2:, 1] = NA

In [39]: df.iloc[4:, 2] = NA

In [40]: df

Out[40]:
          0        1         2
0  0.476985 3.248944 -1.021228
1 -0.577087 0.124121  0.302614
2  0.523772      NaN  1.343810
3 -0.713544      NaN -2.370232
4 -1.860761      NaN       NaN
5 -1.265934      NaN       NaN

In [41]: df.fillna(method='ffill')
Out[41]:
         0         1         2
0  0.476985 3.248944 -1.021228
1 -0.577087 0.124121  0.302614
2  0.523772 0.124121  1.343810
3 -0.713544 0.124121 -2.370232
4 -1.860761 0.124121 -2.370232
5 -1.265934 0.124121 -2.370232

In [42]: df.fillna(method='ffill', limit=2)
Out[42]:
          0        1         2
0  0.476985 3.248944 -1.021228
1 -0.577087 0.124121  0.302614
2  0.523772 0.124121  1.343810
3 -0.713544 0.124121 -2.370232
4 -1.860761      NaN -2.370232
5 -1.265934      NaN -2.370232
```

With **fillna** you can do lots of other things with a little creativity. For example, you might pass the mean or median value of a Series:
```python=
In [43]: data = pd.Series([1., NA, 3.5, NA, 7])

In [44]: data.fillna(data.mean())
Out[44]:
0 1.000000
1 3.833333
2 3.500000
3 3.833333
4 7.000000
dtype: float64
```

![](https://i.imgur.com/7uA0IeL.png)

## Data Transformation

### Removing Duplicates
```python=
In [45]: data = pd.DataFrame({'k1': ['one', 'two'] * 3 + ['two'],
 ....: 'k2': [1, 1, 2, 3, 3, 4, 4]})
In [46]: data
Out[46]:
   k1 k2
0 one  1
1 two  1
2 one  2
3 two  3
4 one  3
5 two  4
6 two  4
```

The DataFrame method **duplicated** returns a boolean Series indicating whether each row is a duplicate (has been observed in a previous row) or not:
```python=
In [47]: data.duplicated()
Out[47]:
0 False
1 False
2 False
3 False
4 False
5 False
6 True
dtype: bool
```

Relatedly, **drop_duplicates** returns a DataFrame where the duplicated array is False:
```python=
In [48]: data.drop_duplicates()
Out[48]:
   k1 k2
0 one  1
1 two  1
2 one  2
3 two  3
4 one  3
5 two  4
```

Both of these methods by default consider all of the columns; alternatively, you can specify any subset of them to detect duplicates. Suppose we had an additional column of values and wanted to filter duplicates only based on the 'k1' column:
```python=
In [49]: data['v1'] = range(7)
In [50]: data.drop_duplicates(['k1'])
Out[50]:
   k1 k2 v1
0 one  1  0
1 two  1  1
```

**duplicated** and **drop_duplicates** by default keep the first observed value combina‐ tion. Passing keep='last' will return the last one:
```python=
In [51]: data.drop_duplicates(['k1', 'k2'], keep='last')
Out[51]:
   k1 k2 v1
0 one  1  0
1 two  1  1
2 one  2  2
3 two  3  3
4 one  3  4
6 two  4  6
```

## Transforming Data Using a Function or Mapping
For many datasets, you may wish to perform some transformation based on the values in an array, Series, or column in a DataFrame. Consider the following hypothetical data collected about various kinds of meat:
```python=
In [52]: data = pd.DataFrame({'food': ['bacon', 'pulled pork', 'bacon',
 ....: 'Pastrami', 'corned beef', 'Bacon',
 ....: 'pastrami', 'honey ham', 'nova lox'],
 ....: 'ounces': [4, 3, 12, 6, 7.5, 8, 3, 5, 6]})

In [53]: data
Out[53]:
   food      ounces
0 bacon         4.0
1 pulled pork   3.0
2 bacon        12.0
3 Pastrami      6.0
4 corned beef   7.5
5 Bacon         8.0
6 pastrami      3.0
7 honey ham     5.0
8 nova lox      6.0
```

### map method
The **map** method on a Series accepts a function or dict-like object containing a mapping, but here we have a small problem in that some of the meats are capitalized and others are not. Thus, we need to convert each value to lowercase using the str.lower Series method:
```python=
In [55]: lowercased = data['food'].str.lower()

In [56]: lowercased

Out[56]:
0 bacon
1 pulled pork
2 bacon
3 pastrami
4 corned beef
5 bacon
6 pastrami
7 honey ham
8 nova lox
Name: food, dtype: object

In [57]: data['animal'] = lowercased.map(meat_to_animal)

In [58]: data

Out[58]:
         food     ounces animal
0       bacon        4.0    pig
1 pulled pork        3.0    pig
2       bacon       12.0    pig
3    Pastrami        6.0    cow
4 corned beef        7.5    cow
5       Bacon        8.0    pig
6    pastrami        3.0    cow
7   honey ham        5.0    pig
8    nova lox        6.0 salmon
```

We could also have passed a function that does all the work:
```python=
In [59]: data['food'].map(lambda x:meat_to_animal[x.lower()])

Out[59]:
0 pig
1 pig
2 pig
3 cow
4 cow
5 pig
6 cow
7 pig
8 salmon
Name: food, dtype: object
```
Using **map** is a convenient way to perform element-wise transformations and other data cleaning–related operations.


## Replacing Values
As you’ve already seen, **map** can be used to modify a subset of values in an object but replace provides a simpler and more flexible way to do so.
```python=
In [60]: data = pd.Series([1., -999., 2., -999., -1000., 3.])

In [61]: data

Out[61]:
0     1.0
1  -999.0
2     2.0
3  -999.0
4 -1000.0
5     3.0
dtype: float64
```

The **-999** values might be sentinel values for missing data. To replace these with NA values that pandas understands, we can use replace, producing a new Series (unless you pass inplace=True):
```python=
data.replace(-999.,np.nan)
```

If you want to replace multiple values at once, you instead pass a list and then the substitute value:
```python=
In [63]: data.replace([-999, -1000], np.nan)

Out[63]:
0 1.0
1 NaN
2 2.0
3 NaN
4 NaN
5 3.0
dtype: float64
```

To use a different replacement for each value, pass a list of substitutes:
```python=
In [64]: data.replace([-999, -1000], [np.nan, 0])
Out[64]:
0 1.0
1 NaN
2 2.0
3 NaN
4 0.0
5 3.0
dtype: float64
```

The argument passed can also be a dict:
```python=
In [65]: data.replace({-999: np.nan, -1000: 0})
Out[65]:
0 1.0
1 NaN
2 2.0
3 NaN
4 0.0
5 3.0
dtype: float64
```

## Renaming Axis Indexes
```python=
In [66]: data = pd.DataFrame(np.arange(12).reshape((3, 4)),
 ....: index=['Ohio', 'Colorado', 'New York'],
 ....: columns=['one', 'two', 'three', 'four'])
```

Like a Series, the axis indexes have a **map** method:
```python=
In [67]: transform = lambda x: x[:4].upper()
In [68]: data.index.map(transform)
Out[68]: Index(['OHIO', 'COLO', 'NEW '], dtype='object')
```


You can assign to **index**, modifying the DataFrame in-place:
```python=
In [69]: data.index = data.index.map(transform)
In [70]: data

Out[70]:
     one two three four
OHIO   0   1     2    3
COLO   4   5     6    7
NEW    8   9    10   11
```
### rename
If you want to create a transformed version of a dataset **without modifying the original**, a useful method is **rename**:
```python=
In [71]: data.rename(index=str.title, columns=str.upper)
Out[71]:
     ONE TWO THREE FOUR
Ohio   0   1     2    3
Colo   4   5     6    7
New    8   9    10   11
```

Notably, rename can be used in conjunction with a dict-like object providing new values for a subset of the axis labels:
```python=
In [72]: data.rename(index={'OHIO': 'INDIANA'},
 ....: columns={'three': 'peekaboo'})
Out[72]:
         one two peekaboo four
INDIANA    0   1        2    3
COLO       4   5        6    7
NEW        8   9       10   11
```

**rename** saves you from the chore of copying the DataFrame manually and assigning to its index and columns attributes. Should you wish to modify a dataset in-place,
pass **inplace=True**:
```python=
data.rename(index={'OHIO'::'INDIANA'}, inplace=True)
```

## Discretization and Binning
Continuous data is often discretized or otherwise separated into “bins” for analysis. Suppose you have data about a group of people in a study, and you want to group them into discrete age buckets:
```python=
In [75]: ages = [20, 22, 25, 27, 21, 23, 37, 31, 61, 45, 41, 32]
```

Let’s divide these into bins of 18 to 25, 26 to 35, 36 to 60, and finally 61 and older. To do so, you have to use **cut**, a function in pandas:
```python=
In [76]: bins = [18, 25, 35, 60, 100]

In [77]: cats = pd.cut(ages, bins)

In [78]: cats

Out[78]:
[(18, 25], (18, 25], (18, 25], (25, 35], (18, 25], ..., (25, 35], (60, 100], (35,
60], (35, 60], (25, 35]]
Length: 12
Categories (4, interval[int64]): [(18, 25] < (25, 35] < (35, 60] < (60, 100]]
```

The **object** pandas returns is a special **Categorical** object. The output you see describes the bins computed by **pandas.cut**. You can treat it like an array of strings
indicating the bin name; internally it contains a categories array specifying the distinct category names along with a labeling for the **ages** data in the **codes** attribute:
```python=
In [79]: cats.codes
Out[79]: array([0, 0, 0, 1, 0, 0, 2, 1, 3, 2, 2, 1], dtype=int8)
In [80]: cats.categories
Out[80]:
IntervalIndex([(18, 25], (25, 35], (35, 60], (60, 100]]
 closed='right',
 dtype='interval[int64]')
In [81]: pd.value_counts(cats)
Out[81]:
(18, 25] 5
(35, 60] 3
(25, 35] 3
(60, 100] 1
dtype: int64
```

Consistent with mathematical notation for intervals, a parenthesis means that the side is *open*, while the square bracket means it is *closed* (inclusive).
You can change which side is closed by passing **right=False**:
```python=
In [82]: pd.cut(ages, [18, 26, 36, 61, 100], right=False)
Out[82]:
[[18, 26), [18, 26), [18, 26), [26, 36), [18, 26), ..., [26, 36), [61, 100), [36,
61), [36, 61), [26, 36)]
Length: 12
Categories (4, interval[int64]): [[18, 26) < [26, 36) < [36, 61) < [61, 100)]
```

You can also pass your own bin names by passing a list or array to the **labels** option:
```python=
In [83]: group_names = ['Youth', 'YoungAdult', 'MiddleAged', 'Senior']
In [84]: pd.cut(ages, bins, labels=group_names)
Out[84]:
[Youth, Youth, Youth, YoungAdult, Youth, ..., YoungAdult, Senior, MiddleAged, Mid
dleAged, YoungAdult]
Length: 12
Categories (4, object): [Youth < YoungAdult < MiddleAged < Senior]
```

If you pass an integer number of bins to **cut** instead of explicit bin edges, it will compute equal-length bins based on the minimum and maximum values in the data. Consider the case of some uniformly distributed data chopped into fourths:
```python=
In [85]: data = np.random.rand(20)
In [86]: pd.cut(data, 4, precision=2)
Out[86]:
[(0.34, 0.55], (0.34, 0.55], (0.76, 0.97], (0.76, 0.97], (0.34, 0.55], ..., (0.34
, 0.55], (0.34, 0.55], (0.55, 0.76], (0.34, 0.55], (0.12, 0.34]]
Length: 20
Categories (4, interval[float64]): [(0.12, 0.34] < (0.34, 0.55] < (0.55, 0.76] <
(0.76, 0.97]]
```

The **precision=2** option limits the decimal precision to two digits.

A closely related function, **qcut**, bins the data based on sample quantiles. Depending on the distribution of the data, using **cut** will not usually result in each bin having the same number of data points. Since **qcut** uses sample quantiles instead, by definition you will obtain roughly equal-size bins:
```python=
In [87]: data = np.random.randn(1000) # Normally distributed
In [88]: cats = pd.qcut(data, 4) # Cut into quartiles
In [89]: cats
Out[89]:
[(-0.0265, 0.62], (0.62, 3.928], (-0.68, -0.0265], (0.62, 3.928], (-0.0265, 0.62]
, ..., (-0.68, -0.0265], (-0.68, -0.0265], (-2.95, -0.68], (0.62, 3.928], (-0.68,
-0.0265]]
Length: 1000
Categories (4, interval[float64]): [(-2.95, -0.68] < (-0.68, -0.0265] < (-0.0265,
0.62] <
 (0.62, 3.928]]
  
In [90]: pd.value_counts(cats)
Out[90]:
(0.62, 3.928] 250
(-0.0265, 0.62] 250
(-0.68, -0.0265] 250
(-2.95, -0.68] 250
dtype: int64
```

Similar to **cut** you can pass your own quantiles (numbers between 0 and 1, inclusive):
```python=
In [91]: pd.qcut(data, [0, 0.1, 0.5, 0.9, 1.])
Out[91]:
[(-0.0265, 1.286], (-0.0265, 1.286], (-1.187, -0.0265], (-0.0265, 1.286], (-0.026
5, 1.286], ..., (-1.187, -0.0265], (-1.187, -0.0265], (-2.95, -1.187], (-0.0265,
1.286], (-1.187, -0.0265]]
Length: 1000
Categories (4, interval[float64]): [(-2.95, -1.187] < (-1.187, -0.0265] < (-0.026
5, 1.286] < (1.286, 3.928]]
```

## Detecting and Filtering Outliers
Filtering or transforming outliers is largely a matter of applying array operations.
Consider a DataFrame with some normally distributed data:
```python=
In [92]: data = pd.DataFrame(np.random.randn(1000, 4))
In [93]: data.describe()
Out[93]:
                0           1           2           3
count 1000.000000 1000.000000 1000.000000 1000.000000
mean     0.049091    0.026112   -0.002544   -0.051827
std      0.996947    1.007458    0.995232    0.998311
min     -3.645860   -3.184377   -3.745356   -3.428254
25%     -0.599807   -0.612162   -0.687373   -0.747478
50%      0.047101   -0.013609   -0.022158   -0.088274
75%      0.756646    0.695298    0.699046    0.623331
max      2.653656    3.525865    2.735527    3.366626
```

Suppose you wanted to find values in one of the columns exceeding 3 in absolute value:
```python=
In [94]: col = data[2]
In [95]: col[np.abs(col) > 3]
Out[95]:
41 -3.399312
136 -3.745356
Name: 2, dtype: float64
```

To select all rows having a value exceeding 3 or –3, you can use the any method on a boolean DataFrame:
```python=
data[(np.abs(data) > 3).any(1)]
```

The statement **np.sign(data)** produces 1 and –1 values based on whether the values in **data** are positive or negative:
```python=
np.sign(data).head()
```

## Permutation and Random Sampling
Permuting (randomly reordering) a Series or the rows in a DataFrame is easy to do using the numpy.random.permutation function. Calling permutation with the length of the axis you want to permute produces an array of integers indicating the new ordering:
```python=
sampler = np.random.permutation(5)
In [102]: sampler
Out[102]: array([3, 1, 4, 2, 0])
```

That array can then be used in **iloc-based** indexing or the equivalent **take** function:
```python=
df  = DataFrame(np.arange(5 * 4).reshape(5,4))

In [103]: df
Out[103]:
   0  1  2  3
0  0  1  2  3
1  4  5  6  7
2  8  9 10 11
3 12 13 14 15
4 16 17 18 19

In [104]: df.take(sampler)
Out[104]:
   0  1  2  3
3 12 13 14 15
1  4  5  6  7
4 16 17 18 19
2  8  9 10 11
0  0  1  2  3
```

To select a random subset without replacement, you can use the **sample** method on Series and DataFrame:
```python=
In [105]: df.sample(n=3)
Out[105]:
   0  1  2  3
3 12 13 14 15
4 16 17 18 19
2  8  9 10 11
```

