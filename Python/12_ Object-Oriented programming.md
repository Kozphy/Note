# 12: Object-Oriented programming
###### tags: `python learn`

## Managing Larget programs
In a way, object oriented programming is a way to arrange your code so that you can zoom into 500 lines of the code, and understand it while ignoring the other 999,500 lines of code for the moment.

## Our First Python Object
At its simplest, an object is some code plus data structures that is smaller than a whole program. Defining a function allows us to store a bit of code and give it a name and then
later invoke that code using the name of the function.

An object can contain a number of functions (which we call “methods”) as well as data that is used by those functions. We call data items that are part of the object “attributes”.

We use the `class` keyword to define the data and code that will make up each of the objects. The class keyword includes the name of the class and begins an indented block of code where we include the attributes (data) and methods (code).
```python=
class PartyAnimal:
    x = 0

    def party(self):
        self.x = self.x + 1
        print("So far", self.x)


an = PartyAnimal()
an.party()
an.party()
an.party()
PartyAnimal.party(an)
```

## Classes as types
```python=
class PartyAnimal:
    x = 0

    def party(self):
        self.x = self.x + 1
        print("So far", self.x)


an = PartyAnimal()
print("Type", type(an))
print("Dir", dir(an))
print("Type", type(an.x))
print("Type", type(an.party))
```

You can see that using the `class` keyword, we have created a new type. From the dir output, you can see both the `x` integer attribute and the `party` method are available in
the object.

## Object lifecycle
If we want our object to be aware of these moments of construction and destruction, we add specially named methods to our object:
```python=
class PartyAniaml:
    x = 0

    def __init__(self):
        print("I am constructed")

    def party(self):
        self.x = self.x + 1
        print('So far', self.x)

    def __del__(self):
        print('I am destructed', self.x)


an = PartyAniaml()
an.party()
an.party()
an = 42
print('an contains', an)
```
As Python is constructing our object, it calls our `__init__` method to give us a chance to set up some default or initial values for the object. When Python encounters the line:
```python=
an = 42
```
It actually ‘throws our object away’ so it can reuse the an variable to store the value 42. Just at the moment when our an object is being ‘destroyed’ our destructor code
`__del__` is called. We cannot stop our variable from being destroyed, but we can do any necessary cleanup right before our object no longer exists.

## Many Instances
```python=
class PartyAnimal:
    x = 0
    name = ''

    def __init__(self, nam):
        self.name = nam
        print(self.name, 'constructed')

    def party(self):
        self.x = self.x + 1
        print(self.name, 'party count', self.x)


s = PartyAnimal('Sally')
s.party()
j = PartyAnimal('Jim')
j.party()
s.party()
```
The output of the program shows that each of the objects (s and j) contain their own independent copies of x and nam:
```
Sally constructed
Sally party count 1
Jim constructed
Jim party count 1
Sally party count 2
```

## Inheritance
Another powerful feature of object oriented programming is the ability to create a new class by extending an existing class. When extending a class, we call the original class the ‘parent class’ and the new class as the ‘child class’.

```python=
from party import PartyAnimal


class CricketFan(PartyAnimal):
    points = 0

    def six(self):
        self.points = self.points + 6
        self.party()
        print(self.name, "points", self.points)


s = PartyAnimal("Sally")
s.party()
j = CricketFan("Jim")
j.party()
j.six()
print(dir(j))
```

When we are defining the `CricketFan` object, we indicate that we are extending the `PartyAnimal` class. This means that all of the variables (x) and methods (party) from
the `PartyAnimal` class are inherited by the `CricketFan` class.

You can see that within the `six` method in the `CricketFan` class, we can call the party method from the `PartyAnimal` class. The variables and methods from the parent class are merged into the child class.

