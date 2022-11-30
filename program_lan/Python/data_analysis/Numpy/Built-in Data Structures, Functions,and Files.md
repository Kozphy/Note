# Chp3 Built-in Data Structures, Functions,and Files
###### tags: `data analysis`

## Data Structures and Sequences
### Tuple
`A tuple is a fixed-length, immutable sequence` of Python objects. The easiest way to create one is with a comma-separated sequence of values:
```python=
In [1]: tup = 4, 5, 6
In [2]: tup
Out[2]: (4, 5, 6)
In [3]: nested_tup = (4, 5, 6), (7, 8)
In [4]: nested_tup
Out[4]: ((4, 5, 6), (7, 8))
In [5]: tuple([4, 0, 2])
Out[5]: (4, 0, 2)
In [6]: tup = tuple('string')
In [7]: tup
Out[7]: ('s', 't', 'r', 'i', 'n', 'g')
In [8]: tup[0]
Out[8]: 's'
```
If an `object inside a tuple is mutable`, such as a list, you can modify it in-place:
```python=
In [9]: tup = tuple(['foo', [1, 2], True])
In [11]: tup[1].append(3)
In [12]: tup
Out[12]: ('foo', [1, 2, 3], True)
```

You can concatenate tuples using the + operator to produce longer tuples:
```python=
In [13]: (4, None, 'foo') + (6, 0) + ('bar',)
Out[13]: (4, None, 'foo', 6, 0, 'bar')
```

`Multiplying` a tuple by an integer, as with lists, has the effect of concatenating together that many copies of the tuple:
```python=
In [14]: ('foo', 'bar') * 4
Out[14]: ('foo', 'bar', 'foo', 'bar', 'foo', 'bar', 'foo', 'bar')
```
> Note that the objects themselves are not copied, only the references to them.

### Unpacking tuples
```python=
In [15]: tup = (4, 5, 6)
In [16]: a, b, c = tup
In [17]: b
Out[17]: 5
In [18]: tup = 4, 5, (6, 7)
In [19]: a, b, (c, d) = tup
In [20]: d
Out[20]: 7
```
In Python, the swap can be done like this:
```python=
In [21]: a, b = 1, 2
In [22]: a
Out[22]: 1
In [23]: b
Out[23]: 2
In [24]: b, a = a, b
In [25]: a
Out[25]: 2
In [26]: b
Out[26]: 1
```

A common use of variable unpacking is iterating over sequences of tuples or lists
```python=
In [27]: seq = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
In [28]: for a, b, c in seq:
 ....: print('a={0}, b={1}, c={2}'.format(a, b, c))
a=1, b=2, c=3
a=4, b=5, c=6
a=7, b=8, c=9
```

You may want to `“pluck”` a few elements from the beginning of a tuple. 

This uses the special syntax `*rest`, which is also used in function signatures to capture an arbitrarily long list of positional arguments:
```python=
In [29]: values = 1, 2, 3, 4, 5
In [30]: a, b, *rest = values
In [31]: a, b
Out[31]: (1, 2)
In [32]: rest
Out[32]: [3, 4, 5]
```

you can use the `underscore (_)` to ignore unwanted variables:
```python=
In [33]: a, b, *_ = values
```

Since the size and contents of a tuple cannot be modified, you can use `count` method, which **counts the number of occurrences of a value**:
```python=
In [34]: a = (1, 2, 2, 2, 3, 4, 2)
In [35]: a.count(2)
Out[35]: 4
```

### List
In contrast with tuples, lists are variable-length and their contents `can be modified in-place`. You can define them using `square brackets []` or using the `list type function`

```python=
In [42]: gen = range(10)
In [43]: gen
Out[43]: range(0, 10)
In [44]: list(gen)
Out[44]: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
```

#### Adding and removing elements
- append(`value`)
- insert(`index`, `value`)
- pop(`index`)
- remove(`value`)

#### Concatenating and combining lists
Similar to tuples, adding two lists together with `+` concatenates them:
```python=
In [57]: [4, None, 'foo'] + [7, 8, (2, 3)]
Out[57]: [4, None, 'foo', 7, 8, (2, 3)]
```

If you have a list already defined, you can append multiple elements to it using the `extend` method:
```python=
In [58]: x = [4, None, 'foo']
In [59]: x.extend([7, 8, (2, 3)])
In [60]: x
Out[60]: [4, None, 'foo', 7, 8, (2, 3)]
```
> Note that list concatenation by **addition** is a **comparatively expensive operation** since a new list must be created and the objects copied over. 

Using `extend` to append elements to an existing list, especially if you are building up a large list, is usually `preferable`. 

Thus,
```python=
everything = []
for chunk in list_of_lists:
    everything.extend(chunk)
```

is faster than the concatenative alternative:
```python=
everything = []
for chunk in list_of_lists:
    everything = everything + chunk
```

#### Sorting
You can `sort a list in-place` (without creating a new object) by calling its sort function
```python=
In [61]: a = [7, 2, 5, 1, 3]
In [62]: a.sort()
In [63]: a
Out[63]: [1, 2, 3, 5, 7]
```

The **sort** secondary parameter is **key** a funtion that produces a value to use to sort the objects. For ex, we could **sort a collection of strings by their lengths**:
```python=
In [64]: b = ['saw', 'small', 'He', 'foxes', 'six']
In [65]: b.sort(key=len)
In [66]: b
Out[66]: ['He', 'saw', 'six', 'small', 'foxes']
```

#### Binary search and maintaining a sorted list
The built-in **bisect** module implements **binary search** and **insertion into a sorted list**.

- **bisect.bisect** `finds` the `location` where an element `should be inserted to keep it sorted`.
- **bisect.insort** `actually inserts` the element into that location:
```python=
In [67]: import bisect
In [68]: c = [1, 2, 2, 2, 3, 4, 7]
In [69]: bisect.bisect(c, 2)
Out[69]: 4
In [70]: bisect.bisect(c, 5)
Out[70]: 6
In [71]: bisect.insort(c, 6)
In [72]: c
Out[72]: [1, 2, 2, 2, 3, 4, 6, 7]
```
> The bisect module functions do not check whether the list is sorted. Thus, using them with an unsorted list will succeed without error but may lead to **incorrect results**.

#### Slicing
A **step** can also be used `after second colon`.
```python=
In [73]: seq = [7, 2, 3, 7, 5, 6, 0, 1]
In [81]: seq[::2]
Out[82]: [7, 3, 5, 0]
```
A clever use of this is to pass `-1`, which reverse a list or tuple:
```python=
In [82]: seq[::-1]
Out[83]: [1, 0, 6, 5, 7, 3, 2, 7]
```

## Built-in Sequence Functions
### enumerate
Enumerate returns a `sequence of (i, value) tuples`:
```python=
for i, value in enumerate(collection):
 # do something with value
```

You can `map` the `values` of a sequence to their `key` (unique) in the sequence:
```python=
In [83]: some_list = ['foo', 'bar', 'baz']
In [84]: mapping = {}
In [85]: for i, v in enumerate(some_list):
 ....: mapping[v] = i
In [86]: mapping
Out[86]: {'bar': 1, 'baz': 2, 'foo': 0}
```

### sorted
The `sorted` function returns a `new sorted list` from the elements of any sequence:
```python=
In [87]: sorted([7, 1, 2, 6, 0, 3, 2])
Out[87]: [0, 1, 2, 2, 3, 6, 7]
In [88]: sorted('horse race')
Out[88]: [' ', 'a', 'c', 'e', 'e', 'h', 'o', 'r', 'r', 's']
```

## zip
zip `“pairs” up` the elements of a number of lists, tuples, or other sequences to create a list of tuples:
```python=
In [89]: seq1 = ['foo', 'bar', 'baz']
In [90]: seq2 = ['one', 'two', 'three']
In [91]: zipped = zip(seq1, seq2)
In [92]: list(zipped)
Out[92]: [('foo', 'one'), ('bar', 'two'), ('baz', 'three')]
```

zip can take an arbitrary number of sequences, and `the number of elements it produces is determined by the shortest sequence`:
```python=
In [93]: seq3 = [False, True]
In [94]: list(zip(seq1, seq2, seq3))
Out[94]: [('foo', 'one', False), ('bar', 'two', True)]
```

A very common use of **zip** is `simultaneously iteraing` over multiple sequences, possibly also `combined` with `enumerate`:
```python=
In [95]: for i, (a, b) in enumerate(zip(seq1, seq2)):
 ....: print('{0}: {1}, {2}'.format(i, a, b))
 ....:
0: foo, one
1: bar, two
2: baz, three
```

Given a “zipped” sequence, zip can be applied to `“unzip”` the sequence by **asterisk**. Another way to think about this is converting a **list of rows into a list of columns**. 
```python=
In [96]: pitchers = [('Nolan', 'Ryan'), ('Roger', 'Clemens'),
 ....: ('Schilling', 'Curt')]
In [97]: first_names, last_names = zip(*pitchers)
In [98]: first_names
Out[98]: ('Nolan', 'Roger', 'Schilling')
In [99]: last_names
Out[99]: ('Ryan', 'Clemens', 'Curt')
```

## reversed
`reversed` iterates over the elements of a sequence **in reverse order**:
```python=
In [100]: list(reversed(range(10)))
Out[100]: [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
```
Keep in mind that **reversed** is a `generator`, so it does not create the reversed sequence until `materialized` (e.g., with list or a for loop)

# dict
You can delete values either using the **del** keyword or the **pop** method.
```python=
di = {'a' : 'some value', 'b' : [1, 2, 3, 4]}
In [108]: d1[5] = 'some value'
In [109]: d1
Out[109]:
{'a': 'some value',
'b': [1, 2, 3, 4],
7: 'an integer',
5: 'some value'}

In [110]: d1['dummy'] = 'another value'
In [111]: d1
Out[111]:
{'a': 'some value',
'b': [1, 2, 3, 4],
7: 'an integer',
5: 'some value',
'dummy': 'another value'}

In [112]: del d1[5]
In [113]: d1
Out[113]:
{'a': 'some value',
'b': [1, 2, 3, 4],
7: 'an integer',
'dummy': 'another value'}

In [114]: ret = d1.pop('dummy')
In [115]: ret
Out[115]: 'another value'
In [116]: d1
Out[116]: {'a': 'some value', 'b': [1, 2, 3, 4], 7: 'an integer'}
```

The **keys** and **values** method give you iterators of the dict’s keys and values, respectively. 
```python=
In [117]: list(d1.keys())
Out[117]: ['a', 'b', 7]
In [118]: list(d1.values())
Out[118]: ['some value', [1, 2, 3, 4], 'an integer']
```

You can `merge one dict into another` using the **update** method:
```python=
In [119]: d1.update({'b' : 'foo', 'c' : 12})
In [120]: d1
Out[120]: {'a': 'some value', 'b': 'foo', 7: 'an integer', 'c': 12}
```

## Creating dicts from sequences
You can `zip` two sequences that you want to pair up element-wise in a dict. 
```python=
key_list = [1,23,45]
value_list = [421,321,42]
mapping = {}
for key, value in zip(key_list, value_list):
    mapping[key] = value
```
Since a dict is `essentially a collection of 2-tuples`, the dict function accepts a list of 2-tuples:
```python=
In [121]: mapping = dict(zip(range(5), reversed(range(5))))
In [122]: mapping
Out[122]: {0: 4, 1: 3, 2: 2, 3: 1, 4: 0}
```
> **range** return a **immutable sequence type**.

## Default values
Using if-else-condition create default value of dict.
```python=
if key in some_dict:
    value = some_dict[key]
else:
    value = default_value
```

Thus, the dict methods `get` and `pop` can take a `default value` to **be returned**, so that the above if-else block can be written simply as:
```python=
value = some_dict.get(key, default_value)
```

### get
**get** by default will return **None** if the key is not present, while `pop will raise an exception`. 

With setting values, a common case is for the `values` in a dict `to be other collections, like lists`. 
```python=
In [123]: words = ['apple', 'bat', 'bar', 'atom', 'book']
In [124]: by_letter = {}
In [125]: for word in words:
 .....: letter = word[0]
 .....: if letter not in by_letter:
 .....:     by_letter[letter] = [word]
 .....: else:
 .....:     by_letter[letter].append(word)
 .....:
In [126]: by_letter
Out[126]: {'a': ['apple', 'atom'], 'b': ['bat', 'bar', 'book']}
```
### setdefault
The **setdefault** dict method is for precisely this purpose. The `preceding for loop can be rewritten as`:
```python=
for word in words:
    letter = word[0]
    by_letter.setdefault(letter, []).append(word)
```

### defaultdict
The built-in **collections** module has  `defaultdict` which can set **default type of dict value**.
```python=
from collections import defaultdict
by_letter = defaultdict(list)
for word in words:
    by_letter[word[0]].append(word)
```

## Valid dict key types
The **keys of dict** is **generally immutable**, like `scalar types` (int, float, string) or `tuples`.

You can use `hash` function to check whether an object is `hashable` which means you can use it as a key in a dict.

```python=
In [127]: hash('string')
Out[127]: 5023931463650008331
In [128]: hash((1, 2, (2, 3)))
Out[128]: 1097636502276347782
In [129]: hash((1, 2, [2, 3])) # fails because lists are mutable
---------------------------------------------------------------------------
TypeError Traceback (most recent call last)
<ipython-input-129-800cd14ba8be> in <module>()
----> 1 hash((1, 2, [2, 3])) # fails because lists are mutable
TypeError: unhashable type: 'list'
```

**To use a list as a key, one option is to convert it to a tuple**:
```python=
In [130]: d = {}
In [131]: d[tuple([1, 2, 3])] = 5
In [132]: d
Out[132]: {(1, 2, 3): 5}
```

## set
A **set** is an `unordered collection of unique elements`. 

You can think of them like dicts, but `keys only, no values`.

A set can be **created in two ways**: via the set `function` or via a `set literal with curly braces`
```python=
In [133]: set([2, 2, 2, 1, 3, 3])
Out[133]: {1, 2, 3}
In [134]: {2, 2, 2, 1, 3, 3}
Out[134]: {1, 2, 3}
```

Sets support mathematical set operations like **union, intersection, difference, and symmetric difference**. Consider these two example sets:
```python=
In [135]: a = {1, 2, 3, 4, 5}
In [136]: b = {3, 4, 5, 6, 7, 8}
```

### union

You can use `union` to get all element of two set in no overlap.

This can be computed with either the `union method` or the `| binary operator`:
```python=
In [137]: a.union(b)
Out[137]: {1, 2, 3, 4, 5, 6, 7, 8}
In [138]: a | b
Out[138]: {1, 2, 3, 4, 5, 6, 7, 8}
```

### intersection
The **intersection** contains the elements `occurring in both sets`. 

The `&` operator or the intersection method can be used:
```python=
In [139]: a.intersection(b)
Out[139]: {3, 4, 5}
In [140]: a & b
Out[140]: {3, 4, 5}
```

### Table 3-1
See Table 3-1 for a list of commonly used set methods.
![](https://i.imgur.com/lhCCwMq.png)

For very large sets using `logical set operations` is more efficient which could let you **replace** set elements **in-place** `on left hand side of operations`.

```python=
In [141]: c = a.copy()
In [142]: c |= b
In [143]: c
Out[143]: {1, 2, 3, 4, 5, 6, 7, 8}
In [144]: d = a.copy()
In [145]: d &= b
In [146]: d
Out[146]: {3, 4, 5}
```

Like dicts, **set elements generally must be immutable**. To have list-like elements, you must `convert it to a tuple`:
```python=
In [147]: my_data = [1, 2, 3, 4]
In [148]: my_set = {tuple(my_data)}
In [149]: my_set
Out[149]: {(1, 2, 3, 4)}
```
Sets are equal if and only if their contents are equal:
```python=
In [153]: {1, 2, 3} == {3, 2, 1}
Out[153]: True
```

## List, Set and Dict Comprehensions
### List comprehensions (square bracket)
The filter condition can be omitted, leaving only the expression. 

```
[expr for val in collection if condition]
```

This is equivalent to the following **for** loop:
```python=
result = []
for val in collection:
    if condition:
        result.append(expr)
```

For example, given a list of strings, we could filter out strings with length 2 or less and also convert them to uppercase like this:
```python=
In [82]: strings = ['a', 'as', 'bat', 'car', 'done', 'python']
In [85]: [x.upper() for x in strings if len(x) <= 2]
Out[85]: ['A', 'AS']
```

### dict comprehension (square bracket)
A dict comprehension looks like this:
```python=
dict_comp = {key-expr : value-expr for value in collection if condition}
```

### set comprehension (curly braces)
A set comprehension looks like the equivalent list comprehension except `with curly braces` instead of square brackets:
```python=
set_comp = {expr for value in collection if condition}
```

Suppose we wanted a `set containing just the lengths of the strings` contained in the collection 
```python=
In [156]: unique_lengths = {len(x) for x in strings}
In [157]: unique_lengths
Out[157]: {1, 2, 3, 4, 6}
```

We could also express this more functionally using the `map` function, introduced shortly:
```python=
In [158]: set(map(len, strings))
Out[158]: {1, 2, 3, 4, 6}
```
As a simple dict comprehension example, we could create a lookup map of these strings to their locations in the list:

```python=
In [94]: loc_mapping = {val: index for index, val in enumerate(strings)}

In [95]: loc_mapping
Out[95]: {'a': 0, 'as': 1, 'bat': 2, 'car': 3, 'done': 4, 'python': 5}
```

## Nested list comprehensions
Suppose we have a list of lists containing some English and Spanish names:
```python=
In [161]: all_data = [['John', 'Emily', 'Michael', 'Mary', 'Steven'],['Maria', 'Juan', 'Javier', 'Natalia', 'Pilar']]
```

Now, suppose we wanted to get a single list containing all names `with two or more e’s` in them. We could certainly do this with a simple for loop:
```python=
names_of_interest = []
for names in all_data:
     enough_es = [name for name in names if name.count('e') >= 2]
     names_of_interest.extend(enough_es)
```

You can actually wrap this whole operation up in a single nested list comprehension, which will look like:
```python=
In [162]: result = [name for names in all_data for name in names
 .....: if name.count('e') >= 2]
In [163]: result
Out[163]: ['Steven']
```

Here is another example where we `“flatten”` a list of tuples of integers into a simple list of integers:
```python=
In [164]: some_tuples = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
In [165]: flattened = [x for tup in some_tuples for x in tup]
In [166]: flattened
Out[166]: [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

```python=
In [167]: [[x for x in tup] for tup in some_tuples]
Out[167]: [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
```

# 3.2 Functions
## keyword argument and positional arguments
Each function can have `positional arguments` and `keyword arguments`.

`Keyword arguments` are most commonly used to specify **default values** or **optional arguments**.

The main restriction on function arguments is that the `keyword arguments must follow the positional arguments` (if any).

```python=
def my_function(x, y, z=1.5):
    if z > 1:
        return z * (x + y)
    else:
        return z / (x + y)
```

```python=
my_function(5, 6, z=0.7)
my_function(3.14, 7, 3.5)
my_function(10, 20)
```

## Namespaces, scope, and local functions, global variable
Functions can access variables in two different scopes: **global** and **local**.

An alternative and more descriptive name describing a variable scope in Python is a `namespace`. 

Any variables that are assigned `within a function` by default are assigned to the `local namespace`. 

The `local namespace is created when the function is called` and immediately populated by the function’s arguments. 

After the function is finished, the local namespace is destroyed.

```python=
def func():
    a = []
    for i in range(5):
        a.append(i)
```

When `func()` is called, the empty list a is created, five elements are appended, and then a is destroyed when the function exits. 
```python=
a = []
def func():
 for i in range(5):
 a.append(i)
```

### global variable
You can use **global** variable to assign outside of the function's scope.

```python=
a = None

def bind_a_variable():
    global a
    a = []
bind_a_variable()
print(a)
```

## Returning  Multiple Values

What’s happening here is that the function is `actually just returning one object`, **namely a tuple**, which is then being unpacked into the result variables.

```python=
def f():
    a = 5
    b = 6
    c = 7
    return a, b, c
a, b, c = f()
```


In the precceding example, we could have done this instead:
```python=
return_value = f()
```

In this case, **return_value** would be a 3-tuple with the three returned variables.

## Functions are objects
Lots of things need to happen to `make this list of strings uniform and ready for analysis`: stripping whitespace, removing punctuation symbols, and standardizing on proper capitalization. 

```python=
In [171]: states = [' Alabama ', 'Georgia!', 'Georgia', 'georgia', 'FlOrIda',
 .....: 'south carolina##', 'West virginia?']
```

One way to do this is to use built-in string methods along with the `re` standard library module for regular expressions:
```python=
import re

def clean_strings(strings):
    result = []
        for value in strings:
            value = value.strip()
            value = re.sub('[!#?]', '', value)
            value = value.title()
            result.append(value)
            return result
```

An alternative approach that you may find useful is to make a list of the operations you want to apply to a particular set of strings:

```python=
def remove_punctuation(value):
    return re.sub('[!#?]', '', value)

clean_ops = [str.strip, remove_punctuation, str.title]

def clean_strings(strings, ops):
    result = []
    for value in strings:
        for function in ops:
            value = function(value)
        result.append(value)
    return result
```

## Anonymous (Lambda) Functions
Python has support for so-called anonymous or lambda functions, which are a way of writing functions consisting of a single statement, the result of which is the return
value. They are defined with the lambda keyword, which has no meaning other than “we are declaring an anonymous function”:
```python=
def short_function(x):
    return x * 2

equiv_anon = lambda x: x * 2
```

## Currying: partial Argument Application
*Currying* is computer science jargon (named after the mathematician Haskell Curry) that means deriving new functions from existing ones by partial argument applica‐
tion. For example, suppose we had a trivial function that adds two numbers together:
```python=
def add_numbers(x, y):
    return x + y
```

Using this function, we could derive a new function of one variable, **add_five**, that adds 5 to its argument:
```python=
add_five = lambda y: add_numbers(5, y)
```

The second argument to add_numbers is said to be curried. as all we've really done is define a new function that calls an existing function.
The built-in functools module can simplify this process using the **partial** function:
```python=
from functools import partial
add_five = partial(add_numbers, 5)
```

## Generators
When you write for **key** in **some_dict**, the Python interpreter first attempts to create an iterator out of some_dict:
```python=
In [182]: dict_iterator = iter(some_dict)
In [183]: dict_iterator
Out[183]: <dict_keyiterator at 0x7fbbd5a9f908>
```

An iterator is any object that will yield objects to the Python interpreter when used in a context like **for** loop. Most methods expecting a list or list-like object will also accept any iterable object. This includes built-in methods such as **min, max** and **sum**, and **type** constructors like **list** and **tuple**.

A *generator* is a concise way to construct a new iterable object. Whereas normal functions execute and return a single result at a time, generators return a sequence of multiple results lazily, pausing after each one until the next one is requested. To create a generator, use the **yield** keyword instead of **return** in a function:
```python=
def squares(n=10):
    print('Generating squares from 1 to {0}'.format(n**2))
    for i in range(1, n + 1):
        yield i ** 2
```

When you actually call the generator, no code is immediately executed:
```python=
In [186]: gen = squares()
In [187]: gen
Out[187]: <generator object squares at 0x7fbbd5ab4570>
```
It is not until you request elements from the generator that it begins executing its code:
```python=
In [188]: for x in gen:
 .....: print(x, end=' ')
Generating squares from 1 to 100
1 4 9 16 25 36 49 64 81 100
```

## Generator expressions
Another even more concise way to make a generator is by using a generator expression. This is a generator analogue to list, dict, and set comprehensions; to create one, enclose what would otherwise be a list comprehension within parentheses instead of brackets:
```python=
In [189]: gen = (x ** 2 for x in range(100))
In [190]: gen
Out[190]: <generator object <genexpr> at 0x7fbbd5ab29e8>
```

This is completely equivalent to the following more verbose generator:
```python
def _make_gen():
     for x in range(100):
     yield x ** 2
gen = _make_gen()
```

Generator expressions can be used instead of list comprehensions as function arguments in many cases:
```python=
In [191]: sum(x ** 2 for x in range(100))
Out[191]: 328350
In [192]: dict((i, i **2) for i in range(5))
Out[192]: {0: 0, 1: 1, 2: 4, 3: 9, 4: 16}
```

## itertools module
The standard library **itertools** module has a collection of generators for many common data algorithms. For ex, **groupby** takes any sequence and a function, grouping consecutive elements in the sequence by return value of the function. Here's an example:
```python=
import itertools
first_letter = lambda x: x[0]
names = ['Alan', 'Adam', 'Wes', 'Will', 'Albert', 'Steven']
for letter, names in itertools.groupby(names, first_letter):
    print(letter, list(names)) # names is a generator
```

### Table 3-2
![](https://i.imgur.com/1r47ptA.png)

## Errors and Exceptin Handling
Here, the file handle f will always get closed. Similarly, you can have code that executes only if the try: block succeeds using else
```python=
f = open(path, 'w')
try:
 write_to_file(f)
except:
 print('Failed')
else:
 print('Succeeded')
finally:
 f.close()
```

## Exceptions in IPython
If an exception is raised while you are %run-ing a script or executing any statement, IPython will by default print a full call stack trace (traceback) with a few lines of con‐
text around the position at each point in the stack:
```python=
In [10]: %run examples/ipython_bug.py
---------------------------------------------------------------------------
AssertionError Traceback (most recent call last)
/home/wesm/code/pydata-book/examples/ipython_bug.py in <module>()
 13 throws_an_exception()
 14
---> 15 calling_things()
/home/wesm/code/pydata-book/examples/ipython_bug.py in calling_things()
 11 def calling_things():
 12 works_fine()
---> 13 throws_an_exception()
 14
 15 calling_things()
/home/wesm/code/pydata-book/examples/ipython_bug.py in throws_an_exception()
 7 a = 5
 8 b = 6
----> 9 assert(a + b == 10)
 10
 11 def calling_things():
AssertionError:
```

You can control the amount of context shown using the %xmode magic command, from Plain (same as the standard Python interpreter) to Verbose (which inlines function argument values and more). 

You can step into the stack (using the **%debug** or **%pdb** magics) after an error has occurred for interactive post-mortem
debugging.

## Files and the Operating System
To open a file for reading or writing, use the built-in open function with either a relative or absolute file path:
```python=
In [207]: path = 'examples/segismundo.txt'
In [208]: f = open(path)
```

By default, the file is opened in read-only mode 'r'. We can then treat the file handle f like a list and iterate over the lines like so:
```python=
for line in f:
    pass
```

The lines come out of the file with the end-of-line (EOL) markers intact, so you’ll often see code to get an EOL-free list of lines in a file like:
```python=
In [209]: lines = [x.rstrip() for x in open(path)]
In [210]: lines
Out[210]:
['Sueña el rico en su riqueza,',
'que más cuidados le ofrece;',
'',
'sueña el pobre que padece',
'su miseria y su pobreza;',
'',
'sueña el que a medrar empieza,',
'sueña el que afana y pretende,',
'sueña el que agravia y ofende,',
'',
'y en el mundo, en conclusión,',
'todos sueñan lo que son,',
'aunque ninguno lo entiende.',
'']
```

When you use **open** to create file objects, it is important to explicitly close the file when you are finished with it. Closing the file releases its resources back to the operating system:
```python=
In [211]: f.close()
```
One of the ways to make it easier to clean up open files is to use the **with** statement:
```python=
In[212]: with open(path) as f:
    ....:    lines = [x.rstrip() for x in f]
```

For readable files, some of the most commonly used methods are read, seek, and tell. read returns a certain number of characters from the file. What constitutes a “character” is determined by the file’s encoding (e.g., UTF-8) or simply raw bytes if the file is opened in binary mode:
```python=
In [213]: f = open(path)
In [214]: f.read(10)
Out[214]: 'Sueña el r'
In [215]: f2 = open(path, 'rb') # Binary mode
In [216]: f2.read(10)
Out[216]: b'Sue\xc3\xb1a el '
```

The read method advances the file handle’s position by the number of bytes read. tell gives you the current position:
```python=
In [217]: f.tell()
Out[217]: 11
In [218]: f2.tell()
Out[218]: 10
```

Even though we read 10 characters from the file, the position is 11 because it took that many bytes to decode 10 characters using the default encoding. You can check the default encoding in the sys module:
```python=
In [219]: import sys
In [220]: sys.getdefaultencoding()
Out[220]: 'utf-8'
```

**seek** changes the file position to the indicated byte in the file:
```python=
In [221]: f.seek(3)
Out[221]: 3
In [222]: f.read(1)
Out[222]: 'ñ'
```

### Table 3-3
![](https://i.imgur.com/td6P7Cr.png)

To write text to a file, you can use the file’s write or writelines methods. For example, we could create a version of *prof_mod.py* with no blank lines like so:
```python=
In [225]: with open('tmp.txt', 'w') as handle:
 .....: handle.writelines(x for x in open(path) if len(x) > 1)
In [226]: with open('tmp.txt') as f:
 .....: lines = f.readlines()
In [227]: lines
Out[227]:
['Sueña el rico en su riqueza,\n',
'que más cuidados le ofrece;\n',
'sueña el pobre que padece\n',
'su miseria y su pobreza;\n',
'sueña el que a medrar empieza,\n',
'sueña el que afana y pretende,\n',
'sueña el que agravia y ofende,\n',
'y en el mundo, en conclusión,\n',
'todos sueñan lo que son,\n',
'aunque ninguno lo entiende.\n']
```

### Table 3-4
![](https://i.imgur.com/gFIwh6b.png)
![](https://i.imgur.com/3E5q3ZR.png)

## Bytes and Unicode with Files
The default behavior for Python files (whether readable or writable) is text mode, which means that you intend to work with Python strings (i.e., Unicode). This contrasts with binary mode, which you can obtain by appending b onto the file mode.
```python=
In [230]: with open(path) as f:
 .....: chars = f.read(10)
In [231]: chars
Out[231]: 'Sueña el r'
```

UTF-8 is a variable-length Unicode encoding, so when I requested some number of characters from the file, Python reads enough bytes (which could be as few as 10 or as
many as 40 bytes) from the file to decode that many characters. If I open the file in 'rb' mode instead, read requests exact numbers of bytes:
```python=
In [232]: with open(path, 'rb') as f:
 .....: data = f.read(10)
In [233]: data
Out[233]: b'Sue\xc3\xb1a el '
```

Depending on the text encoding, you may be able to decode the bytes to a **str** object yourself, buy only if each of the encoded Unicode characters is fully formed:
```python=
In [234]: data.decode('utf8')
Out[234]: 'Sueña el '
In [235]: data[:4].decode('utf8')
---------------------------------------------------------------------------
UnicodeDecodeError Traceback (most recent call last)
<ipython-input-235-300e0af10bb7> in <module>()
----> 1 data[:4].decode('utf8')
UnicodeDecodeError: 'utf-8' codec can't decode byte 0xc3 in position 3: unexpecte
d end of data
```

Text mode, combined with the encoding option of open, provides a convenient way to convert from one Unicode encoding to another:
```python=
In [236]: sink_path = 'sink.txt'
In [237]: with open(path) as source:
 .....: with open(sink_path, 'xt', encoding='iso-8859-1') as sink:
 .....: sink.write(source.read())
In [238]: with open(sink_path, encoding='iso-8859-1') as f:
 .....: print(f.read(10))
Sueña el r
```

Beware using seek when opening files in any mode other than binary. If the file position falls in the middle of the bytes defining a Unicode character, then subsequent
reads will result in an error:
```python=
In [240]: f = open(path)
In [241]: f.read(5)
Out[241]: 'Sueña'
In [242]: f.seek(4)
Out[242]: 4
In [243]: f.read(1)
---------------------------------------------------------------------------
UnicodeDecodeError Traceback (most recent call last)
<ipython-input-243-7841103e33f5> in <module>()
----> 1 f.read(1)
/miniconda/envs/book-env/lib/python3.6/codecs.py in decode(self, input, final)
 319 # decode input (taking the buffer into account)
 320 data = self.buffer + input
--> 321 (result, consumed) = self._buffer_decode(data, self.errors, final
)
 322 # keep undecoded input until the next call
 323 self.buffer = data[consumed:]
UnicodeDecodeError: 'utf-8' codec can't decode byte 0xb1 in position 0: invalid s
tart byte
In [244]: f.close()
```

