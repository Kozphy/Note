# haskell function
###### tags: `Learn You a Haskell for Great Good!`

## function
- create baby.hs
-  Once inside GHCI, do `:l baby`. Now that our script is loaded, we can play with the function that we defined.
-  Because `+` works on integers as well as on floating-point numbers (anything that can be considered a number, really), our function also works on any number.
-  Functions in Haskell don't have to be in any particular order, so it doesn't matter if you define doubleMe first and then doubleUs or if you do it the other way around.
-  The difference between Haskell's if statement and **if statements in imperative languages is that the else part is mandatory in Haskell**. In imperative languages you can just skip a couple of steps if the condition isn't satisfied but in Haskell every expression and function must return something
-  Another thing about the **if statement in Haskell is that it is an _expression_. An expression is basically a piece of code that returns a value.** 5 is an expression because it returns 5, 4 + 8 is an expression, x + y is an expression because it returns the sum of x and y. Because the else is mandatory, an if statement will always return something and that's why it's an expression.
-  Note the `'` at the end of the function name. That apostrophe doesn't have any special meaning in Haskell's syntax. It's a valid character to use in a function name. **We usually use ' to either denote a strict version of a function (one that isn't lazy) or a slightly modified version of a function or a variable**.
```haskell
doubleMe x = x + x
dboubleUs x y = doubleMe x + doubleMe y
doubleSmallNumber x = if x > 100
						then x
						else x*2
doubleSmallNumber' x = (if x > 100 then x else x*2) + 1
conanO'Brien = "It's a-me, Conan O'Brien!"
```

### There are two noteworthy things here
-  The first is that in the function name we didn't capitalize Conan's name. That's because functions can't begin with uppercase letters
-   The second thing is that this function doesn't take any parameters. When a function doesn't take any parameters, we usually say it's a _definition_ (or a _name_). Because we can't change what names (and functions) mean once we've defined them, conanO'Brien and the string "It's a-me, Conan O'Brien!" can be used interchangeably.
