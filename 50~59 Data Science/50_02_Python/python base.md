#python 

## scalar objects
- int - represent integers, ex. 5
- float - represent real numbers, ex 3.27
- bool - represent Boolean values **True** and **False**
- NoneType - **special** and has one value, None
- can use type() to see the type of an object. 

## scope example
![](https://i.imgur.com/05wvVQh.png)

## keyword arguments and default value
```python=
def printName(firstName, lastName, reverse = False):
    if reverse:
        print(lastName + ", " + firstName)
    else:
        print(firstName, lastName)

printName(lastName = "eric", firstName = "koi")

```

## function specifications
![](https://i.imgur.com/mZfpmz3.png)
- a **contract** between the implementer of a function and the clients who will use it
    - Assumption: conditions that must be met by clients of the function; typically constraints on values of parameters
    - Guarantees: conditions that must be met by function, providing it has been called in manner consistent with assumptions.



