# 3: Iteration
###### tags: `python learn`

## 5.1 Updating vaiables
```python=
x = x + 1
```
If you try to update a variable that doesn't exist, you get an error, because Python evaluates the right side before it assigns a value to x:
```python=
>>> x = x + 1
NameError: name 'x' is not defined
```

Before you can update a variable, you have to initialize it, usually with a simple assignment:
```python=
>>> x = 0
>>> x = x + 1
```
## 5.2 The while statement
```python=
n = 5
while n > 0 :
    print(n)
    n = n -1
print('Blastoff!')
```
## 5.4 infinite loops and break
```python=
while True:
    line = input('> ')
    if line == 'done':
        break
    print(line)
print('Done!')
```
The loop condition is True, which is always true, so the loop runs repeatedly until it hits
the break statement.

This way of writing while loops is common because you can check the condition anywhere in the loop (not just at the top) and you can express the stop condition affirmatively
(“stop when this happens”) rather than negatively (“keep going until that happens.”).

## 5.6 Definite loops using for
```python=
friends = ['Joseph', 'Glenn', 'Sally']
for friend in friends:
    print('Happy New Year:', friend)
print('Done!')
```
