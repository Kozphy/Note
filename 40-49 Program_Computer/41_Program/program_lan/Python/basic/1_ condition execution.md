# 1: condition execution
###### tags: `python learn`

## Condition execution
If the logical condition is true, then the indented statement gets executed. If the logical
condition is false, the indented statement is skipped.

if statements have the same structure as function definitions or for loops. The statement consists of a header line that ends with the colon character (:) followed by an indented block. Statements like this are called compound statements because they stretch across more than one line.

There is no limit on the number of statements that can appear in the body, but there must be at least one. **Occasionally, it is useful to have a body with no statements (usually as a place holder for code you haven’t written yet). In that case, you can use the pass statement, which does nothing**.
```python=
if x < 0 :
    pass     #need to handle negative values!
```

## Catching exceptions using try and except
```python=
inp = input('Enter Fahrenheit Temperature:')
try:
fahr = float(inp)
cel = (fahr - 32.0) * 5.0 / 9.0
print(cel)
except:
print('Please enter a number')

```

Python starts by executing the sequence of statements in the **try** block. If all goes well,
it skips the **except** block and proceeds. If an exception occurs in the **try** block, Python
jumps out of the **try** block and executes the sequence of statements in the except block


Handling an exception with a **try** statement is called catching an exception. In this example, the **except** clause prints an error message. In general, catching an exception gives
you a chance to fix the problem, or try again, or at least end the program gracefully.

