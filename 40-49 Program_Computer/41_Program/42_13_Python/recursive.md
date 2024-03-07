# recursive
###### tags: `introduction to computer science and programming using python`

## what is recursion
- a way to design solutions to problems by divide-and-conquer or decrease-and-conquer
- a programming technique where a function calls itself
- in programming, goal is to NOT have infinite recursion
    - must have 1 or more base cases that are easy to solve
    - must solve the same problem on some other input with the goal of simplifying the larger probelm input

### multiplication iterative solution
```python=
def mult_iter(a,b):
    result = 0
    while b > 0:
        result += a
        b -= 1
    return result
```

### multiplication recursive solution
recursive step
- think how to reduce problem to a simpler/smaller version of same probelm

base case
- keep reducing problem until reach a simple case that can be solved directly
- when b = 1, a*b = a

```python=
def mult(a,b):
    if b == 1:
        return a
    else:
        return a + mult(a, b - 1)
```

### factorial recursive
```python=
def factorial(n):
    if n == 1:
        return n
    else:
        return n * factorial(n-1)
```
### some observations
- each recursive call to a function creates its own scope/environment
- bindings of variables in a scope is not changed by recursive call
- flow of control passes back to previous scope once function call returns value

## iteration vs recursion
```python=
def factorial_iter(n):
    prod = 1
    for i in range(1, n + 1):
        prod *= i
    return prod
```

```python=
def factorial(n):
    if n == 1:
        return 1
    else: 
        return n*factorial(n-1)
```

- recursion may be simpler, more intuitive
- recursion may be efficient from programmer POV
- recursion may not be efficient from computer POV

## towl_of_hanoi

## Recursive problem solving
Let f(n) be a recursive function
1. Show f(1) works (base case)
2. Assume f(n - 1) works
3. Show f(n) works using f(n - 1)