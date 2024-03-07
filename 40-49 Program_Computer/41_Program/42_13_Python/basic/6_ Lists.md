# 6: Lists
###### tags: `python learn`

## A list is a sequence
Like a string, a list is a sequence of values. In a string, the values are characters; in a list, they can be any type. The values in list are called elements or sometimes items.

There are several ways to create a new list; the simplest is to enclose the elements in square brackets ([ and ]):

The elements of a list don't have to be the same type. The following list contains a string, a float, an integer, and another list:
```python=
['spam', 2.0, 5, [10, 20]]
```

A list within another list is nested.

A list that contains no elements is called an empty list; you can create one with empty brackets, [].
```python=
>>> cheeses = ['Cheddar', 'Edam', 'Gouda']
>>> numbers = [17, 123]
>>> empty = []
>>> print(cheeses, numbers, empty)
['Cheddar', 'Edam', 'Gouda'] [17, 123] []
```

## Lists are mutable
lists are mutable because you can change the order of items in a list or reassign an item in a list. When the bracket operator appears on the left side of an assignment, it identifies the element of the list that will be assigned.

List indices work the same way as string indices:
- Any integer expression can be used as an index
- If you try to read or write an element that does not exist, you get an **IndexError**.
- If an index has a negative value, it counts backward from the end of the list.

The **in** operator also works on lists.
```python=
cheeses = ['Cheddar', 'Edam', 'Gouda']
>>> 'Edam' in cheeses
True
>>> 'Brie' in cheeses
False
```

## Traversing a list
The most common way to traverse the elements of a list is with a for loop. The syntax is the same as for strings:
```python=
for cheese in cheeses:
    print(cheese)
```

This works well if you only need to read the elements of the list. But if you want to write or update the elements, you need the indices. A common way to do that is to combine the functions **range** and **len**:
```python=
for i in range(len(numbers)):
    numbers[i] = numbers[i] * 2
```

This loop traverses the list and updates each element. **len** returns the number of elements in the list. **range** returns a list of indices from 0 to n-1, where n is the length of the list. Each time through the loop, **i** gets the index of the next element. The assignment statement in the body uses **i** to read the old value of the element and to assign the new value.

A **for** loop over an empty list never executes the body:
```python=
for x in empty:
    print('This never happens.')
```

## List operations
The **+** operator concatenates lists:
```python=
>>> a = [1,2,3]
>>> b = [4,5,6]
c = a + b
print(c)
[1,2,3,4,5,6]
```
Similarly, the operator repeats a list a given number of times
```python=
>>> [0] * 4
[0, 0, 0, 0]
>>> [1, 2, 3] * 3
[1, 2, 3, 1, 2, 3, 1, 2, 3]
```
## List slices
The slice operator also works on lists:
```python=
>>> t = ['a', 'b', 'c', 'd', 'e', 'f']
>>> t[1:3]
['b', 'c']
>>> t[:4]
['a', 'b', 'c', 'd']
>>> t[3:]
['d', 'e', 'f']
```

If you omit the first index, the slice starts at the beginning. If you omit the second, the
slice goes to the end. So if you omit both, the slice is a copy of the whole list.
```python=
>>> t[:]
['a', 'b', 'c', 'd', 'e', 'f']
```

A slice operator on the left side of an assignment can update multiple elements:
```python
>>> t = ['a', 'b', 'c', 'd', 'e', 'f']
>>> t[1:3] = ['x', 'y']
>>> print(t)
['a', 'x', 'y', 'd', 'e', 'f']
```

## List methods
### append
Python provides methods that operate on lists. For example, `append` adds a new element to the end of a list:
```python=
>>> t = ['a', 'b', 'c']
>>> t.append('d')
>>> print(t)
['a', 'b', 'c', 'd']
```
### extend
`extend` takes a list as an argument and appends all of the elements:
```python=
>>> t1 = ['a', 'b', 'c']
>>> t2 = ['d', 'e']
>>> t1.extend(t2)
>>> print(t1)
['a', 'b', 'c', 'd', 'e']

```
### sort
`sort` arranges the elements of the list from low to high:
```python=
>>> t = ['d', 'c', 'e', 'b', 'a']
>>> t.sort()
>>> print(t)
['a', 'b', 'c', 'd', 'e']
```

Most list methods are void; they modify the list and return None. If you accidentally write
`t = t.sort()`, you will be disappointed with the result

## Deleting elements
### pop
There are several ways to delete elements from a list. If you know the index of the element you want, you can use `pop`:
```python=
>>> t = ['a', 'b', 'c']
>>> x = t.pop(1)
>>> print(t)
['a', 'c']
>>> print(x)
b
```

`pop` modifies the list and returns the element that was removed. If you don’t provide an index, it deletes and returns the last element.

If you don’t need the removed value, you can use the `del` operator:
```python=
>>> t = ['a', 'b', 'c']
>>> del t[1]
>>> print(t)
['a', 'c']
```
### remove
If you know the element you want to remove (but not the index), you can use `remove`:
```python=
>>> t = ['a', 'b', 'c']
>>> t.remove('b')
>>> print(t)
['a', 'c']
```
The return value from remove is `None`.
### del
To remove more than one element, you can use `del` with a slice index:
```python=
>>> t = ['a', 'b', 'c', 'd', 'e', 'f']
>>> del t[1:5]
>>> print(t)
['a', 'f']
```

## Lists and functions
### max, min, sum
There are a number of built-in functions that can be used on lists that allow you to quickly look through a list without writing your own loops
```python=
>>> nums = [3, 41, 12, 9, 74, 15]
>>> print(len(nums))
6
>>> print(max(nums))
74
>>> print(min(nums))
3
>>> print(sum(nums))
154
>>> print(sum(nums)/len(nums))
25
```

The `sum()` function only works when the list elements are numbers. The other functions
`(max(), len(), etc.)` work with lists of strings and other types that can be comparable.

In this program, we have `count` and `total` variables to keep the number and running total of the user’s numbers as we repeatedly prompt the user for a number.
We could simply remember each number as the user entered it and use built-in functions to compute the sum and count at the end.
```python=
numlist = list()
while (True):
    inp = input('Enter a number: ')
    if inp == 'done':
        break
    value = float(inp)
    numlist.append(value)

average = sum(numlist) / len(numlist)
print('Average:', average)
```

## Lists and strings
### list()
A string is a sequence of characters and a list is a sequence of values, but a list of characters is not the same as a string. To convert from a string to a list of characters, you can use `list`:
```python=
>>> s = 'spam'
>>> t = list(s)
>>> print(t)
['s', 'p', 'a', 'm']
```

### split()
The `list` function breaks a string into individual letters. If you want to break a string into
words, you can use the `split` method:
```python=
s = 'pining for the fjords'
t = s.split()
print(t)
print(t[2])
```

Once you have used `split` to break the string into a list of words, you can use the index operator (square bracket) to look at a particular word in the list.

You can call `split` with an optional argument called a delimiter that specifies which characters to use as word boundaries. The following example uses a hyphen as a delimiter:
```python=
>>> s = 'spam-spam-spam'
>>> delimiter = '-'
>>> s.split(delimiter)
['spam', 'spam', 'spam']
```

### join()
`join` is the inverse of `split`. It takes a list of strings and concatenates the elements.
`join` is a string method, so you have to invoke it on the delimiter and pass the list as a parameter:
```python=
>>> t = ['pining', 'for', 'the', 'fjords']
>>> delimiter = ' '
>>> delimiter.join(t)
'pining for the fjords'
```

## Parsing line
The `split` method is very effective when faced with this kind of problem. We can write a small program that looks for lines where the line starts with “From”, split those lines, and then print out the third word in the line:
```python=
fhand = open('mbox-short.txt')
for line in fhand:
    line = line.rstrip()
    if not line.startswith('From '):
        continue
    words = line.split()
    print(words[2])
```

## Object and values
```python=
a = 'banana'
b = 'banana'
```
we know that `a` and `b` both refer to a string, but we don’t know whether they refer to the same string. There are two possible states:

In one case, `a` and `b` refer to two different objects that have the same value. In the second case, they refer to the same object.

To check whether two variables refer to the same object, you can use the `is` operator.

```python=
>>> a = 'banana'
>>> b = 'banana'
>>> a is b
True
```
In this example, Python only created one string object, and both a and b refer to it.

But when you create two lists, you get two objects:
```python=
>>> a = [1, 2, 3]
>>> b = [1, 2, 3]
>>> a is b
False
```

In this case we would say that the two lists are equivalent, because they have the same elements, but not identical, because they are not the same object.

Until now, we have been using “object” and “value” interchangeably, but it is more precise to say that an object has a value. If you execute `a = [1,2,3]`, a refers to a list object whose value is a particular sequence of elements. If another list has the same elements, we would say it has the same value.

## Aliasing
If a refers to an object and you assign b = a, then both variables refer to the same object:
```python
>>> a = [1, 2, 3]
>>> b = a
>>> b is a
True
```
The association of a variable with an object is called a reference. In this example, there are two references to the same object.

An object with more than one reference has more than one name, so we say that the object is aliased.

If the aliased object is mutable, changes made with one alias affect the other:
```python=
>>> b[0] = 17
>>> print(a)
[17, 2, 3]
```
Although this behavior can be useful, it is error-prone. In general, it is safer to avoid aliasing when you are working with mutable objects.

For immutable objects like strings, aliasing is not as much of a problem. In this example:
```python=
a = 'banana'
b = 'banana'
```
it almost never makes a difference whether a and b refer to the same string or not.

## List arguments
When you pass a list to a function, the function gets a reference to the list. If the function modifies a list parameter, the caller sees the change. For ex, **delete_head** removes the first element from  a lists:
```python=
def delete_head(t):
    del t[0]
```

The parameter `t` and the variable `letters` are aliases for the same object.

It is important to distinguish between operations that modify lists and operations that create new lists. For ex, the **append** method modifies a list, but the **+** operator creates a new list:
```python=
>>> t1 = [1, 2]
>>> t2 = t1.append(3)
>>> print(t1)
[1, 2, 3]
>>> print(t2)
None

>>> t3 = t1 + [3]
>>> print(t3)
[1, 2, 3]
>>> t2 is t3
False
```


This difference is important when you write functions that are supposed to modify lists. For example, this function does not delete the head of a list:
```python=
def bad_delete_head(t):
    t = t[1:] # WRONG!
```


The slice operator creates a new list and the assignment makes t refer to it, but none of that has any effect on the list that was passed as an argument.

An alternative is to write a function that creates and returns a new list. For example, tail returns all but the first element of a list:
```python=
def tail(t):
    return t[1:]
```
This function leaves the original list unmodified. Here’s how it is used:
```python=
def tail(t):
    return t[1:]


letters = ['a', 'b', 'c']
rest = tail(letters)
print(rest)
print(letters)
```

## Debugging
Careless use of lists (and other mutable objects) can lead to long hours of debugging.
Here are some common pitfalls and ways to avoid them:
1. Don’t forget that most list methods modify the argument and return None. This is the opposite of the string methods, which return a new string and leave the original alone.
2. Pick an idiom and stick with it
3. Make copies to avoid aliasing
    - If you want to use a method like **sort** that modifies the argument, but you need to keep the original list as well, you can make a copy.
```python=
orig = t[:]
t.sort()

