# 4: Strings
###### tags: `python learn`
## basic string use
```python=
fruit = 'banana'
letter = fruit[1]
print(letter)

letter = fruit[0]
print(letter)

len(fruit)

for char in fruit:
    print(char)
    
s = 'Monty Python'
print(s[0:5])
print(s[6:12])
```

## string are immutable

```python=
>>> greeting = 'Hello, world!'
>>> greeting[0] = 'J'
TypeError: 'str' object does not support item assignment
```
The reason for the error is that strings are immutable, which means you can’t change
an existing string. The best you can do is create a new string that is a variation on the
original:
```python=
>>> greeting = 'Hello, world!'
>>> new_greeting = 'J' + greeting[1:]
>>> print(new_greeting)
Jello, world!

```

## Looping and counting
```python=
word = 'banana'
count = 0
for letter in word:
    if letter == 'a':
        count = count + 1
print(count)
```
## The in operator
```python=
>>> 'a' in 'banana'
True
>>> 'seed' in 'banana'
False
```
## String methods
Python has a function called dir which lists the methods available for an object. The type function shows the type of an object and the **dir** function shows the available methods.
```python=
stuff = 'Hello world'
type(stuff)
dir(stuff)
```

While the dir function lists the methods, and you can use **help** to get some simple documentation on a method.

### upper(), find(), strip(), startswith(), lower()
```python=
upper()
str.find(str, beg=0, end=len(string))
# strip remove whilte space (spaces, tabs, or newlines)
>>> line = '  Here we go  '
>>> line.strip()
'Here we go'
>>> line = 'Have a nice day'
>>> line.startswith('Have')
True
>>> line.startswith('h')
False
>>> line = 'Have a nice day'
>>> line.startswith('h')
False
>>> line.lower()
'have a nice day'
>>> line.lower().startswith('h')
True
```
In the last example, the method **lower** is called and then we use **startswith** to see if the resulting lowercase string starts with the letter "h".

## Parsing strings
Often, we want to look into a string and find a substring. For example if we were presented a series of lines formatted as follows:
From stephen.marquard@uct.ac.za Sat Jan 5 09:14:16 2008
```python=
data = 'From stephen.marquard@uct.ac.za Sat Jan 5 09:14:16 2008'
atpos = data.find('@')
print(atpos)
sppos = data.find(' ', atpos)
print(sppos)
host = data[atpos+1:sppos]
print(host)
```

## Format operator
The format operator, % allows us to construct strings, replacing parts of the strings with the data stored in variables. When applied to integers, % is the modulus operator. But when the first operand is a string, % is the format operator.

The first operand is the format string, which contains one or more format sequences that specify how the second operand is formatted.

For example, the format sequence "%d" means that the second operand should be formatted as an integer (d stands for "decimal"):
```python=
>>> camels = 42
>>> '%d' % camels
'42'
```

A format sequence can appear anywhere in the string, so you can embed a value in a sentence:
```python=
>>> camels = 42
>>> 'I have spotted %d camels.' % camels
'I have spotted 42 camels.'
```
If there is more than one format sequence in the string, the second argument has to be a tuple. Each format sequence is matched with an element of the tuple, in order.

The following example uses "%d" to format an integer, "%g" to format a floating-point number (don't ask why),and "%s" to format a string:
```python=
>>> 'In %d years I have spotted %g %s.' % (3, 0.1, 'camels')
'In 3 years I have spotted 0.1 camels.'
```
The number of elements in the tuple must match the number of format sequences in the string. The types of the elements also must match the format sequences:
```python=
>>> '%d %d %d' % (1, 2)
TypeError: not enough arguments for format string
>>> '%d' % 'dollars'
TypeError: %d format: a number is required, not str
```
