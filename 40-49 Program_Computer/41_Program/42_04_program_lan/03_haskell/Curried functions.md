# Curried functions
###### tags: `Learn You a Haskell for Great Good!`

All the functions that accepted several parameters so far have been **curried functions.**

## curried functions concept
Doing `max 4 5` first creates a function that takes a parameter and returns either `4` or that parameter, depending on which is bigger. Then, `5` is applied to that function and that function produces our desired result. That sounds like a mouthful but it's actually a really cool concept. The following two calls are equivalent:
```haskell=
ghci> max 4 5  
5  
ghci> (max 4) 5  
5  
```

Putting a space between two things is simply **function application**. The space is sort of like an operator and it has the highest precedence. Let's examine the type of `max`. It's `max :: (Ord a) => a -> a -> a`. That can also be written as `max :: (Ord a) => a -> (a -> a)`. That could be read as: `max` takes an a and returns (that's the `->`) a function that takes an `a` and returns an `a`. That's why the return type and the parameters of functions are all simply separated with arrows.

Simply speaking, if we call a function with too few parameters, we get back a **partially applied** function, **meaning a function that takes as many parameters as we left out. Using partial application (calling functions with too few parameters, if you will) is a neat way to create functions on the fly so we can pass them to another function or to seed them with some data**.

Take a look at this offensively simple function:
```haskell=
multThree :: (Num a) => a -> a -> a -> a  
multThree x y z = x * y * z  
```

What really happens when we do `multThree 3 5 9` or `((multThree 3) 5) 9`? First, `3` is applied to `multThree`, because they're separated by a space. That creates a function that takes one parameter and returns a function. So then `5` is applied to that, which creates a function that will take a parameter and multiply it by 15. `9` is applied to that function and the result is 135 or something.

Remember that this function's type could also be written as `multThree :: (Num a) => a -> (a -> (a -> a))`. The thing before the `->` is the parameter that a function takes and the thing after it is what it returns. So our function takes an `a` and returns a function of type `(Num a) => a -> (a -> a)`. Similarly, this function takes an `a` and returns `a` function of type `(Num a) => a -> a`. And this function, finally, just takes an a and returns an a. Take a look at this:
```haskell=
ghci> let multTwoWithNine = multThree 9  
ghci> multTwoWithNine 2 3  
54  
ghci> let multWithEighteen = multTwoWithNine 2  
ghci> multWithEighteen 10  
180
```

**By calling functions with too few parameters, so to speak, we're creating new functions on the fly**. What if we wanted to create a function that takes a number and compares it to `100`? We could do something like this:
```haskell=
compareWithHundred :: (Num a, Ord a) => a -> Ordering  
compareWithHundred x = compare 100 x  
```

If we call it with `99`, it returns a `GT`. Simple stuff. Notice that the `x` is on the right hand side on both sides of the equation. Now let's think about what `compare 100` returns. It returns a function that takes a number and compares it with `100`. Wow! Isn't that the function we wanted? We can rewrite this as:
```haskell=
compareWithHundred :: (Num a, Ord a) => a -> Ordering
compareWithHundred = compare 100
```

The type declaration stays the same, because `compare 100` returns a function. Compare has a type of `(Ord a) => a -> (a -> Ordering)` and calling it with `100` returns a `(Num a, Ord a) => a -> Ordering`. The additional class constraint sneaks up there because `100` is also part of the `Num` typeclass.

### infix functions to become partially applied
**Infix functions can also be partially applied by using sections. To section an infix function, simply surround it with parentheses and only supply a parameter on one side**.

That creates a function that takes one parameter and then applies it to the side that's missing an operand. An insultingly trivial function:
```haskell=
divideByTen :: (Floating a) => a -> a  
divideByTen = (/10)  

ghci> (/10) 200
20.0
ghci> (20/10)
2.0
ghci> (20/) 10
2.0

```

Calling, say, `divideByTen 200` is equivalent to doing `200 / 10`, as is doing `(/10) 200`. A function that checks if a character supplied to it is an uppercase letter:
```haskell=
isUpperAlphanum :: Char -> Bool  
isUpperAlphanum = (`elem` ['A'..'Z'])  
ghci> "A" `elem` ["A"]
True
ghci> (`elem` ["A"]) "A"
True
ghci> ("A" `elem`) ["A", "B"]
True

```

