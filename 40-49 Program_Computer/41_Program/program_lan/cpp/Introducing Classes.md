# Introducing Classes
###### tags: `c++ learn`

## The Sales_tiem Class
To use a class, we need not care about how it is
implemented. Instead, what we need to know is what operations objects of that type can perform.

Every class defines a type. The type name is the same as the name of the class. Hence, our **Sales_item** class defines a type named **Sales_item**. As with the built-in types, we can define a variable of a class type. When we writ
```
Sales_item item;
```

we are saying that **item** is an object of type **Sales_item**. We often contract the phrase “an object of type **Sales_item**” to “a **Sales_item** object” or even more simply to “a **Sales_item**.”

In addition to being able to define variables of type **Sales_item**, we can:
- Call funciton named **isbn** to fetch something from a **Sales_item** object
- Use the input (>>) and output (<<) operators to read and write objects of type **Sales_item**.
- Use the assignment operator (=) to assign one **Sales_item** object to another.
- Use the addition operator (+) to add two **Sales_item** objects. The two objects must refer to the same **ISBN**. The result is a new **Sales_item** objects whose **ISBN** is that of its operands and whose number sold and revenue are the sum of the corresponding values in its operands.
- Use the compound assignment operator (+=) to add one **Sales_item** object into another.

> Key Conecpt: Class Define Behavior
> The important thing to keep in mind when you read these programs is that the author of the **Sales_item** class defines all the actions that can be performed by objects of this class. That is, the **Sales_item** class defines what happens when a **Sales_item** object is created and what happens when the assignment, addition, or the input and output operators are applied to **Sales_items**.

> In general, the class author determines all the operations that can be used on objects of the class type. For now, the only operations we know we can perform on **Sales_item** objects are the ones listed in this section.

## Reading and Writing Sales_items
```c++=
#include <iostream>
#include "./C++_primer/1/Sales_item.h"

int main() {
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;
    return 0;
}
```

## A First Look at Member Functions
Our program that adds two **Sales_items** should check whether the objects have the same **ISBN**. We'll do so as follows:
```c++==
#include <iostream>
#include "./C++_primer/1/Sales_item.h"

int main() {
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn()) {
        std::cout << item1 + item2 << std::endl;
        return 0;
    } else {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;
    }
}
```
The if conditon calls a **member function** named **isbn**.

A member function is a function that is defined as part of a class. Member functions are sometimes referred to as **methods**.
```c++=
item1.isbn() == item2.isbn()
```

## The bookstore Program