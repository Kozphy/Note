# Function composition
###### tags: `Learn You a Haskell for Great Good!`

## definition
In mathematics, function composition is defined like this:![](https://i.imgur.com/FJ7IA0V.png)
meaning that composing two functions produces a new function that, when called with a parameter, say, x is the equivalent of calling g with the parameter x and then calling the f with that result.

In Haskell, function composition is pretty much the same thing. We do function composition with the `.` function, which is defined like so:
```haskell=
(.) :: (b -> c) -> (a -> b) -> a -> c  
f . g = \x -> f (g x)

ghci> (*3) . (+3) $ 3
18
```
Mind the type declaration. `f` must take as its parameter a value that has the same type as `g`'s return value. So the resulting function takes a parameter of the same type that `g` takes and returns a value of the same type that `f` returns.

## turn list of numbers all into negative numbers
Function composition is right-associative, so we can compose many functions at a time. The expression f (g (z x)) is equivalent to (f . g . z) x.
```haskell=
ghci> map (\x -> negate (abs x)) [5,-3,-6,7,-3,2,-19,24]  
[-5,-3,-6,-7,-3,-2,-19,-24]  

ghci> map (negate . abs) [5,-3,-6,7,-3,2,-19,24]  
[-5,-3,-6,-7,-3,-2,-19,-24]  

ghci> map (\xs -> negate (sum (tail xs))) [[1..5],[3..6],[1..7]]
[-14,-15,-27]

ghci> map (negate . sum . tail) [[1..5],[3..6],[1..7]]
[-14,-15,-27]
```

## if we want to use them in function composition, we usually have to partially apply them just so much that each function takes just one parameter.
`sum (replicate 5 (max 6.7 8.9))` can be rewritten as `(sum . replicate 5 . max 6.7) 8.9` or as `sum . replicate 5 . max 6.7 $ 8.9`.

## If you want to rewrite an expression with a lot of parentheses by using function composition
you can start by putting the last parameter of the innermost function after a `$` and then just composing all the other function calls, writing them without their last parameter and putting dots between them.
```haskell=
ghci> replicate 100 (product (map (*3) (zipWith max [1,2,3,4,5] [4,5,6,7,8]))

ghci> replicate 100 . product . map (*3) . zipWith max [1,2,3,4,5] $ [4,5,6,7,8]
```

## Another common use of function composition is defining functions in the so-called point free style (also called the pointless style). 
Take for example this function that we wrote earlier:
```haskell=
sum' :: (Num a) => [a] -> a     
sum' xs = foldl (+) 0 xs 
```
The `xs` is exposed on both right sides. Because of currying, we can omit the `xs` on both sides, because calling `foldl (+) 0` creates a function that takes a list. Writing the function as `sum' = foldl (+) 0` is called writing it in point free style. How would we write this in point free style?

```haskell=
fn x = ceiling (negate (tan (cos (max 50 x)))) 
```

We can't just get rid of the `x` on both right sides. The `x` in the function body has parentheses after it. `cos (max 50)` wouldn't make sense. You can't get the cosine of a function. What we can do is express fn as a composition of functions.
```haskell=
fn = ceiling . negate . tan . cos . max 50
```

Many times, a point free style is more readable and concise, because it makes you think about functions and what kind of functions composing them results in instead of thinking about data and how it's shuffled around. 

However, many times, writing a function in point free style can be less readable if a function is too complex.

The prefered style is to use let bindings to give labels to intermediary results or split the problem into sub-problems and then put it together so that the function makes sense to someone reading it instead of just making a huge composition chain.

## In the section about maps and filters, we solved a problem of finding the sum of all odd squares that are smaller than 10,000.
```haskell=
oddSquareSum :: Integer  
oddSquareSum = sum (takeWhile (<10000) (filter odd (map (^2) [1..])))  
```

Being such a fan of function composition, I would have probably written that like this:
```haskell=
oddSquareSum :: Integer  
oddSquareSum = sum . takeWhile (<10000) . filter odd . map (^2) $ [1..]  
```

However, if there was a chance of someone else reading that code, I would have written it like this:
```haskell=
oddSquareSum'' :: Integer
oddSquareSum'' =
    let oddSquares = filter odd $ map (^2) [1..]
        belowLimit = takeWhile (<10000) oddSquares
    in sum belowLimit
```