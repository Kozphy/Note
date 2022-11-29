# Python Language Basics, IPython, and Jupyter Notebooks
###### tags: `data analysis`

## Runing IPython Basics in cmd
```
ipython
```

## Run Jupyter in cmd
On many platforms, Jupyter will automatically open up in your default web browser (unless you start it with --no-browser)
```
jupyter notebook
```

### Tab Completion
One of the major improvements over the standard Python shell is tab completion, found in many IDEs or other interactive computing analysis environments. While entering expressions in the shell, **pressing the Tab key** will search the namespace for any variables (objects, functions, etc.) matching the characters you have typed so far.
```python=
an_apple=27
an_example=42
an<Tab>

b = [1,2,3]
b.<Tab>

import datetime
datetime.<Tab>
```
Tab completion works in many contexts outside of searching the interactive namespace and completing object or module attributes. When typing anything that looks like a file path (even in a Python string), pressing the Tab key will complete anything on your computer’s filesystem matching what you’ve typed:
```python
datasets/movielens/<Tab>

path = 'datasets/movielens/<Tab>
```

## Introspection
Using a question mark (?) before or after a variable will display some general information about the object:
```python=
b = [1,2,3]
b?

print?
```
This is referred to as object introspection. If the object is a function or instance method, the docstring, if defined, will also be shown.

```python=
def add_numbers(a, b):
    """
    Add two numbers together
    
    Returns
    -----
    the_sum : type of arguments
    """
    return a + b
```
Then using ? shows us the docstring:
```python=
In [11]: add_numbers?
Signature: add_numbers(a, b)
Docstring:
Add two numbers together
Returns
-------
the_sum : type of arguments
File: <ipython-input-9-6a548a216e27>
Type: function

```
Using ?? will also show the function’s source code if possible:
```python=
In [12]: add_numbers??
Signature: add_numbers(a, b)
Source:
def add_numbers(a, b):
 """
 Add two numbers together
 Returns
 -------
 the_sum : type of arguments
 """
 return a + b
File: <ipython-input-9-6a548a216e27>
Type: function

```
? has a final usage, which is for searching the IPython namespace in a manner similar to the standard Unix or Windows command line. A number of characters combined
with the wildcard (*) will show all names matching the wildcard expression. For example, we could get a list of all functions in the top-level NumPy namespace containing load:
```python
np.*load*?
```

## The %run command
You can run any file as a Python program inside the environment of your IPython session using the %run command.
Suppose you had the following simple script stored in ipython_script_test.py
```python=
def f(x, y, z):
    return (x+y) / z
a = 5
b = 6
c = 7.5
result = f(a, b, c)
```
You can execute this by passing the filename to %run:
```
%run ipython_script_test.py
```
> Should you wish to give a script access to variables already defined in the interactive IPython namespace, use %run -i instead of plain %run.

In the Jupyter notebook, you may also use the related %load magic function, which imports a script into a code cell:
```python=
%load ipython_script_test.py
```

## Executing code from the clipboard
It is also possible to run code from the clipboard in the IPython shell.
Suppose you had the following code in some other application:
```python=
x = 5
y = 7
if x > 5:
    x += 1
    y = 8
```

The most foolproof methods are the %paste and %cpaste magic functions. %paste takes whatever text is in the clipboard and executes it as a single block in the shell:
```python=
%paste
x = 5
y = 7
if x > 5:
 x += 1
 y = 8
## -- End pasted text --
```

%cpaste is similar, except that it gives you a special prompt for pasting code into:
```python=
%cpaste
Pasting code; enter '--' alone on the line to stop or use Ctrl-D.
:x = 5
:y = 7
:if x > 5:
: x += 1
:
26 | Chapter 2: Python Language Basics, IPython, and Jupyter Notebooks
: y = 8
:--
```
With the %cpaste block, you have the freedom to paste as much code as you like before executing it. You might decide to use %cpaste in order to look at the pasted code before executing it. If you accidentally paste the wrong code, you can break out of the %cpaste prompt by pressing Ctrl-C.

## Table 2-1
![](https://i.imgur.com/cxedbEJ.png)

## About Magic commands
IPython’s special commands (which are not built into Python itself) are known as “magic” commands. These are designed to facilitate common tasks and enable you to
easily control the behavior of the IPython system. A magic command is any command prefixed by the percent symbol %.

For example, you can check the execution
time of any Python statement, such as a matrix multiplication, using the %timeit
magic function (which will be discussed in more detail later):
```python=
In [20]: a = np.random.randn(100, 100)
In [20]: %timeit np.dot(a, a)
10000 loops, best of 3: 20.9 µs per loop
```

Magic commands can be viewed as command-line programs to be run within the IPython system. Many of them have additional “command-line” options, which can all be viewed (as you might expect) using ?:
```python=
In [21]: %debug?
```

Magic functions can be used by default without the percent sign, as long as no variable is defined with the same name as the magic function in question. This feature is called automagic and can be enabled or disabled with **%automagic**.

Some magic functions behave like Python functions and their output can be assigned to a variable:
```python=
In [22]: %pwd
Out[22]: '/home/wesm/code/pydata-book
In [23]: foo = %pwd
In [24]: foo
Out[24]: '/home/wesm/code/pydata-book'
```
**Table 2-2** highlights some of the most critical ones for being productive in interactive computing and Python development in IPython
### Table 2-2
![](https://i.imgur.com/GwhYwYt.png)

## Matplotlib intergration
One reason for IPython’s popularity in analytical computing is that it integrates well with data visualization and other user interface libraries like matplotlib.

The **%matplotlib** magic function configures its integration with the IPython shell or Jupyter notebook.

In the IPython shell, running %matplotlib sets up the integration so you can create multiple plot windows without interfering with the console session:
![](https://i.imgur.com/uzqgr5Y.png)


## Variables and argument passing
When assigning a variable (or name) in Python, you are creating a reference to the object on the righthand side of the equals sign.

In some languages, this assignment would cause the data [1, 2, 3] to be copied. In Python, a and b actually now refer to the same object, the original list [1, 2, 3].
```python=
In [8]: a = [1,2,3]
In [9]: b = a
In [10]: a.append(4)
In [11]: b
Out [11]: [1,2,3,4]
```
![](https://i.imgur.com/CPP2x1j.png)

When you pass objects as arguments to a function, new local variables are created referencing the original objects without any copying. If you bind a new object to a variable inside a function, that change will not be reflected in the parent scope. It is therefore possible to alter the internals of a mutable argument.

![](https://i.imgur.com/pErfMzu.png)

## Dynamic references, strong type
![](https://i.imgur.com/f76PpHO.png)

Knowing the type of an object is important, and it’s useful to be able to write functions that can handle many different kinds of input. Youcan check that an object is an
instance of a particular type using the **isinstance** function:
```python=
In [21]: a = 5
In [22]: isinstance(a,int)
Out [22]: True
```
**isinstance** can accept a tuple of types if you want to check that an object’s type is among those present in the tuple:
```python=
In [23]: a = 5; b = 4.5
In [24]: isinstance(a, (int, float))
Out[24]: True

In [25]: isinstance(b, (int, float))
Out[25]: True
```

## Attributes and methods
Objects in Python typically have both attributes (other Python objects stored “inside” the object) and methods (functions associated with an object that can have access to the object’s internal data). Both of them are accessed via the syntax **obj.attribute_name**:
```python=
In [1]: a = 'foo'
In [2]: a.<Press Tab>
```
Attributes and methods can also be accessed by name via the getattr function:
```python=
In [27]: getattr(a, 'split')
Out [27]: <function str.split>
```
In other languages, accessing objects by name is often referred to as “reflection.

## Duck typing
Often you may not care about the type of an object but rather only whether it has certain methods or behavior. This is sometimes called “duck typing”.
For example, you can verify that an object is iterable if it implemented the iterator protocol. For many objects, this means it has a __iter__ “magic method,” though an alternative and better way to check is to try using the iter function:
```python=
def isiterable(obj):
    try:
        iter(obj)
        return True
    except TypeError: # not iterable
        return False
isiterable('a string')
isiterable([1,2,3])
isiterable(5)
```
A place where I use this functionality all the time is to write functions that can accept multiple kinds of input. A common case is writing a function that can accept any
kind of sequence (list, tuple, ndarray) or even an iterator. You can first check if the object is a list (or a NumPy array) and, if it is not, convert it to be one:
```python=
if not isinstance(x, list) and isiterable(x):
    x = list(x)
```
## Binary operators and comparisons
To check if two references refer to the same object, use the is keyword. is not is also perfectly valid if you want to check that two objects are not the same:
```python=
In [35]: a = [1, 2, 3]
In [36]: b = a
In [37]: c = list(a)
In [38]: a is b
Out[38]: True
In [39]: a is not c
Out[39]: True
```
Since **list** always creates a new Python list (i.e., a copy), we can be sure that c is distinct from a. Comparing with **is** is not the same as the == operator, because this case we have:
```python=
In [40]: a == c
Out[40]: True
```

A very common use of **is** and **is not** is to check if a variable is **None**, since there is only one instance of None:
```python=
In [41]: a = None
In [42]: a is None
Out[42]: True
```
### Table 2-3
![](https://i.imgur.com/gmQmv3w.png)
![](https://i.imgur.com/zALr6yG.png)

## Mutable and immutable objects
Most objects in Python, such as lists, dicts, Numpy arrays, and most user-defined types (classes), are mutable. This means that the object or values that they contain can be modified:
![](https://i.imgur.com/5cEIJrC.png)
Remember that just because you can mutate an object does not mean that you always should. Such actions are known as side effects. For example, when writing a function,
any side effects should be explicitly communicated to the user in the function’s documentation or comments. If possible, I recommend trying to avoid side effects and
favor immutability, even though there may be mutable objects involved.

## Scalar Types
Python along with its standard library has a small set of built-in types for handling numerical data, strings, boolean (True or False) values, and dates and time. These
“single value” types are sometimes called scalar types and we refer to them in this book as scalars.
### Table 2-4
![](https://i.imgur.com/ChMC76f.png)

## Bytes and Unicode
In modern Python (i.e., Python 3.0 and up), Unicode has become the first-class string type to enable more consistent handling of ASCII and non-ASCII text. In older versions of Python, strings were all bytes without any explicit Unicode encoding.
We can convert this Unicode string to its UTF-8 bytes representation using the encode method
```python=
val = 'espanol'
In [78]: val_utf8 = val.encode('utf-8')
In [79]: val_utf8
Out[79]: b'espa\xc3\xb1ol'
In [80]: type(val_utf8)
Out[80]: bytes
```
Assuming you know the Unicode encoding of a bytes object, you can go back using the decode method
```python=
In [81]: val_utf8.decode('utf-8')
Out[81]: 'español'
```
While it’s become preferred to use UTF-8 for any encoding, for historical reasons you may encounter data in any number of different encodings:
```python=
In [82]: val.encode('latin1')
Out[82]: b'espa\xf1ol'
In [83]: val.encode('utf-16')
Out[83]: b'\xff\xfee\x00s\x00p\x00a\x00\xf1\x00o\x00l\x00'
In [84]: val.encode('utf-16le')
Out[84]: b'e\x00s\x00p\x00a\x00\xf1\x00o\x00l\x00'
```

It is most common to encounter bytes objects in the context of working with files, where implicitly decoding all data to Unicode strings may not be desired.
Though you may seldom need to do so, you can define your own byte literals by prefixing a string with b:
```python=
In [85]: bytes_val = b'this is bytes'
In [86]: bytes_val
Out[86]: b'this is bytes'
In [87]: decoded = bytes_val.decode('utf8')
In [88]: decoded # this is str (Unicode) now
Out[88]: 'this is bytes'
```

## None
None is the Python null value type. If a function does not explicitly return a value, it implicitly returns **None**:

While a technical point, it’s worth bearing in mind that None is not only a reserved keyword but also a unique instance of NoneType:
```python=
In [101]: type(None)
Out[101]: NoneType
```

## Dates and times
The built-in Python **datetime** module providees **datetime, date**, and **time** types. The **datetime** type, as you may imagine, combines the information stored in **date** and **time** and is the most commonly used:
```python=
In [102]: from datetime import datetime, date, time
In [103]: dt = datetime(2011, 10, 29, 20, 30, 21)
In [104]: dt.day
Out[104]: 29
In [105]: dt.minute
Out[105]: 30
```

Given a **datetime** instance, you can extract the equivalent **date** and **time** objects by calling methods on the **datetime** of the same name:
```python=
In [106]: dt.date()
Out[106]: datetime.date(2011, 10, 29)
In [107]: dt.time()
Out[107]: datetime.time(20, 30, 21)
```

The **strftime** method formats a **datetime** as a string:
```python=
In [108]: dt.strftime('%m/%d/%Y %H:%M')
Out[108]: '10/29/2011 20:30'
```

Strings can be converted(parsed) into **datetime** objects with the **strptime** function:
```python=
In [109]: datetime.strptime('20091031', '%Y%m%d')
Out[109]: datetime.datetime(2009, 10, 31, 0, 0)
```

When you are aggregating or otherwise grouping time series data, it will occasionally be useful to replace time fields of a series of datetimes—for example, replacing the minute and second fields with zero:
```python=
In [110]: dt.replace(minute=0, second=0)
Out[110]: datetime.datetime(2011, 10, 29, 20, 0)
```
Since datetime.datetime is an immutable type, methods like these always produce new objects.

The difference of two datetime objects produces a datetime.timedelta type:
```python=
In [111]: dt2 = datetime(2011, 11, 15, 22, 30)
In [112]: delta = dt2 - dt
In [113]: delta
Out[113]: datetime.timedelta(17, 7179)
In [114]: type(delta)
Out[114]: datetime.timedelta
```

The output timedelta(17, 7179) indicates that the timedelta encodes an offset of 17 days and 7,179 seconds.
Adding a timedelta to a datetime produces a new shifted datetime:
```python=
In [115]: dt
Out[115]: datetime.datetime(2011, 10, 29, 20, 30, 21)
In [116]: dt + delta
Out[116]: datetime.datetime(2011, 11, 15, 22, 30)
```
### Table 2-5
![](https://i.imgur.com/47Mih8N.png)
![](https://i.imgur.com/8TtDxr9.png)

## Control Flow
### break
The **break** keyword only terminates the innermost **for** loop; any outer **for** loops will continue to run:
```python=
In [121]: for i in range(4):
 .....: for j in range(4):
 .....: if j > i:
 .....: break
 .....: print((i, j))
 .....:
(0, 0)
(1, 0)
(1, 1)
(2, 0)
(2, 1)
(2, 2)
(3, 0)
(3, 1)
(3, 2)
(3, 3)
```

### range
The **range** function returns an iterator that yields a sequence of evenly spaced integers:
```python=
In [122]: range(10)
Out[122]: range(0, 10)
In [123]: list(range(10))
Out[123]: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
```

Both a start, end, and step (which may be negative) can be given
```python=
In [124]: list(range(0, 20, 2))
Out[124]: [0, 2, 4, 6, 8, 10, 12, 14, 16, 18]
In [125]: list(range(5, 0, -1))
Out[125]: [5, 4, 3, 2, 1]
```
As you can see, range produces integers up to but not including the endpoint. A common use of range is for iterating through sequences by index:
```python=
seq = [1, 2, 3, 4]
for i in range(len(seq)):
    val = seq[i]
```

### Ternary expressions
A **ternary expression** in Python allows you to combine an **if-else** block that produces a value into a single line or expression. The syntax for this Python is:
```
value = ture-expr if condition else false-expr
```
This is a more concrete example:
```python=
In [126]: x = 5
In [127]: 'Non-negative' if x >= 0 else 'Negative'
Out[127]: 'Non-negative'
```

