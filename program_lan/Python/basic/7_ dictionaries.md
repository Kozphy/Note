# 7: dictionaries
###### tags: `python learn`

A dictionary is like a list, but more general. In a list, the index positions have to be integers; in a dictionary, the indices can be (almost) any type.


You can think of a dictionary as a mapping between a set of indices (which are called keys) and a set of values. Each key maps to a value. The association of a key and a value is called a key-value pair or sometimes an item.

The function `dict` creates a new dictionary with no items.
```python=
>>> eng2sp = dict()
>>> print(eng2sp)
```

The curly brackets, {}, represent an empty dictionary. To add items to the dictionary, you can use square brackets:
```python=
>>> eng2sp['one'] = 'uno'
```

This line creates an item that maps from the key 'one' to the value “uno”. If we print the dictionary again, we see a key-value pair with a colon between the key and value:
```python=
>>> print(eng2sp)
{'one': 'uno'}
```

This output format is also an input format. For example, you can create a new dictionary with three items. But if you print `eng2sp`, you might be surprised:
```python=
>>> eng2sp = {'one': 'uno', 'two': 'dos', 'three': 'tres'}
>>> print(eng2sp)
{'one': 'uno', 'three': 'tres', 'two': 'dos'}
```

The order of the key-value pairs is not the same. In fact, if you type the same example on your computer, you might get a different result. In general, the order of items in a dictionary is unpredictable.

The **in** operator works on dictionaries; it tells you whether something appears as a key in the dictionary (appearing as a value is not good enough).
```python=
>>> 'one' in eng2sp
True
>>> 'uno' in eng2sp
False
```

To see whether something appears as a value in dictionary, you can use the method **values**, which returns as a list, and then use the **in** operator:
```python=
>>> vals = list(eng2sp.values())
>>> 'uno' in vals
True
```

The **in** operator uses different algorithms for lists and dictionaries. For lists, it uses a linear search algorithm. As the list gets longer, the search time gets longer in direct proportion to the length of the list. 

For dictionaries, Python uses an algorithm called a hash table that has a remarkable property: the in operator takes about the same amount of time no matter how many items there are in a dictionary.

## Dictionary as a set of counters
Suppose you are given a string and you want to count how many times each letter appears.
```python=
word = 'brontosaurus'
d = dict()

for chr in word:
    if chr not in d:
        d[chr] = 1
    else:
        d[chr] += 1
print(d)
```
We are effectively computing a histogram, which is statistical term for a set of counters.

```python=
{'a': 1, 'b': 1, 'o': 2, 'n': 1, 's': 2, 'r': 2, 'u': 2, 't': 1}
```

Dictionaries have a method called **get** that takes a key and a default value. If the key appears in the dictionary, **get** returns the corresponding value; otherwise it returns the default value.
```python=
>>> counts = { 'chuck' : 1 , 'annie' : 42, 'jan': 100}
>>> print(counts.get('jan', 0))
100
>>> print(counts.get('tim', 0))
0
```

We can use **get** to write our histogram loop more concisely. Because the **get** method automatically handles the case where a key is not in a dictionary, we can reduce four lines down to one and eliminate the **if** statement.
```python=
word = 'brontosaurus'
d = dict()
for c in word:
    d[c] = d.get(c, 0) + 1
print(d)
```

## Dictionaries and files
One of the common uses of a dictionary is to count the occurrence of words in a file with some written text.

For the first set of examples, we will use a shortened and simplified version of the text with no punctuation. Later we will work with the text of the scene with punctuation included.

```python=
fname = input("Enter the file name: ")
try:
    fhand = open(fname)
except:
    print('File cannot be opened:', fname)
    exit()
counts = dict()
for line in fhand:
    words = line.split()
    for word in words:
        counts[word] = counts.get(word, 0) + 1

print(counts)
```

## Looping and dictionaries
If you use a dictionary as the sequence in a `for` statement, it traverses the keys of the dictionary. This loop prints each key and the corresponding value:
```python=
counts = {'chunk': 1, 'annie': 42, 'jan': 100}
for key in counts:
    print(key, counts[key])
```

```python=
counts = {'chunk': 1, 'annie': 42, 'jan': 100}
for key in counts:
    if counts[key] > 10:
        print(key, counts[key])
```

If you want to print the keys in alphabetical order, you first make a list of the keys in the dictionary using the `keys` method available in dictionary objects, and then sort that list and loop through the sorted list, looking up each key and printing out key-value pairs in sorted order as follows:
```python=
counts = {'chunk': 1, 'annie': 42, 'jan': 100}
lst = list(counts.keys())
lst.sort()
print(lst)
for key in lst:
    print(key, counts[key])
```

## Advanced text parsing
Since the Python `split` function looks for spaces and treats words as tokens separated by spaces, we would treat the words “soft!” and “soft” as different words and create
a separate dictionary entry for each word.

Also since the file has capitalization, we would treat “who” and “Who” as different words with different counts.

We can solve both these problems by using the string methods `lower`, `punctuation`, and `translate`. The `translate` is the most subtle of the methods. Here is the documentation for `translate`:
```python=
line.translate(str.maketrans(fromstr, tostr, deletestr))
```

Replace the characters in `fromstr` with the character in the same position in `tostr` and delete all characters that are in `deletestr`. The `fromstr` and `tostr` can be empty strings and the `deletestr` parameter can be omitted.

We will not specify the `table` but we will use the `deletechars` parameter to delete all of the punctuation. We will even let Python tell us the list of characters that it considers
“punctuation”
```python=
>>> import string
>>> string.punctuation
'!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~'
```

```python=
import string
fname = input('Enter the file name: ')
try:
    fhand = open(fname)
except:
    print('File cannot be opened:', fname)
    exit()
counts = dict()
for line in fhand:
    line = line.translate(str.maketrans('', '', string.punctuation))
    line = line.lower()
    line = line.split()
    print(line)
    for word in line:
        counts[word] = counts.get(word, 0) + 1
print(counts)
```
The **sort** function works the same way. It sorts primarily by first element, but in the case of a tie, it sorts by second element, and so on

This feature lends itself to a pattern called DSU for
**Decorate** a sequence by building a list of tuples with one or more sort keys preceding the elements from the sequence,
**Sort** the list of tuples using the Python built-in sort, and
**Undecorate** by extracting the sorted elements of the sequence.

[DSU]

For example, suppose you have a list of words and you want to sort them from longest to shortest:
```python=
txt = 'but soft what light in yonder window breaks'
words = txt.split()
t = list()
for word in words:
t.append((len(word), word))

t.sort(reverse=True)

res = list()
for length, word in t:
res.append(word)
print(res)
```

## Tuple assignment
One of the unique syntactic features of the Python language is the ability to have a tuple on the left side of an assignment statement. This allows you to assign more than one variable at a time when the left side is a sequence.
```python=
m = ['have', 'fun']
x, y = m
(x, y) = m
```

A particularly clever application of tuple assignment allows us to swap the values of two variables in a single statement
```python=
a, b = b, a
```
Both sides of this statement are tuples, but the left side is a tuple of variables; the right side is a tuple of expressions.

Each value on the right side is assigned to its respective variable on the left side. All the expressions on the right side are evaluated before any of the assignments.

More generally, the right side can be any kind of sequence (string, list, or tuple). For example, to split an email address into a user name and a domain, you could write:
```python=
>>> addr = 'monty@python.org'
>>> uname, domain = addr.split('@')
print(uname, domain)
```

## Dictionaries and tuples
Dictionaries have a method called `items` that returns a list of tuples, where each tuple is a key-value pair:
```python=
>>> d = {'a':10, 'b':1, 'c':22}
>>> t = list(d.items())
>>> print(t)
[('b', 1), ('a', 10), ('c', 22)]
```

As you should expect from a dictionary, the items are in no particular order.

However, since the list of tuples is a list, and tuples are comparable, we can now sort the list of tuples. Converting a dictionary to a list of tuples is a way for us to output the contents of a dictionary sorted by key:
```python=
>>> d = {'a':10, 'b':1, 'c':22}
>>> t = list(d.items())
>>> t
[('b', 1), ('a', 10), ('c', 22)]
>>> t.sort()
>>> t
[('a', 10), ('b', 1), ('c', 22)]
```

## Multiple assignment with dictionaries
Combining `items`, tuple assignment, and `for`, you can see a nice code pattern for traversing the keys and values of a dictionary in a single loop
```python=
for key, val in list(d.items()):
    print(val, key)
```

If we combine these two techniques, we can print out the contents of a dictionary sorted by the value stored in each key-value pair
```python=
d = {'a': 10, 'b': 1, 'c': 22}
l = list()
for key, val in d.items():
    l.append((val, key))
print(l)
l.sort(reverse=True)
print(l)
```

## The most common words
```python=
import string
fhand = open('romeo2.txt')
counts = dict()
for line in fhand:
    line = line.translate(str.maketrans('', '', string.punctuation))
    line = line.lower()
    words = line.split()
    for word in words:
        counts[word] = counts.get(word, 0) + 1

l = list()

for key, val in counts.items():
    l.append((val, key))

l.sort(reverse=True)

res = list()
for key, val in l:
    res.append(val)
print(res)
```

## Using tuples as keys in dictionaries
Because tuples are hashable and lists are not, if we want to create a composite key to use in a dictionary we must use a tuple as the key.

We would encounter a composite key if we wanted to create a telephone directory that maps from last-name, first-name pairs to telephone numbers. Assuming that we have defined the variables last, first, and number, we could write a dictionary assignment statement as follows:
```python=
directory[last, first] = number
```
The expression in brackets is a tuple. We could use tuple assignment in a for loop to traverse this dictionary
```python=
for last, first in directory:
    print(first, last, directory[last, first])
```

## Sequences: strings, lists, and tuple - Oh My!
In many contexts, the different kinds of sequences (strings, lists, and tuples) can be used interchangeably. So how and why do you choose one over the others?

o start with the obvious, strings are more limited than other sequences because the elements have to be characters. They are also immutable. If you need the ability to change the characters in a string (as opposed to creating a new string), you might want to use a list of characters instead.

Lists are more common than tuples, mostly because they are mutable. But there are a few cases where you might prefer tuples:
- In some contexts, like a return statement, it is syntactically simpler to create a tuple than a list. In other contexts, you might prefer a list.
- If you want to use a sequence as a dictionary key, you have to use an immutable type like a tuple or string.
- If you are passing a sequence as an argument to a function, using tuples reduces the potential for unexpected behavior due to aliasing.

Because tuples are immutable, they don’t provide methods like sort and reverse, which modify existing lists. However Python provides the built-in functions sorted and
reversed, which take any sequence as a parameter and return a new sequence with the same elements in a different order.
