# Function application with $
###### tags: `Learn You a Haskell for Great Good!`

## $ function, also called function application
it's defined:
```haskell=
($) :: (a -> b) -> a -> b  
f $ x = f x  
```
Normal function application (putting a space between two things) has a really high precedence, the `$` function has the lowest precedence. Function application with a space is left-associative (so `f a b c` is the same as `((f a) b) c))`, function application with `$` is right-associative.

## That's all very well, but how does this help us?
Most of the time, it's a convenience function so that we don't have to write so many parentheses. Consider the expression `sum (map sqrt [1..130])`. Because `$` has such a low precedence, we can rewrite that expression as `sum $ map sqrt [1..130]`, saving ourselves precious keystrokes!

When a `$` is encountered, the expression on its right is applied as the parameter to the function on its left. How about `sqrt 3 + 4 + 9`?
```haskell=
Prelude> sqrt 3 + 4 + 9
14.732050807568877

Prelude> sqrt $ 3 + 4 + 9
4.0
```
you can imagine a `$` being sort of the equivalent of writing an opening parentheses and then writing a closing one on the far right side of the expression.

## How about sum (filter (>10) (map (*2) \[2..10]))
```haskell=
ghci> sum $ filter (>10) $ map (*2) [2..10]
```
Well, because `$` is right-associative, `f (g (z x))` is equal to `f $ g $ z x`.

But apart from getting rid of parentheses,`$` means that function application can be treated just like another function. That way, we can, for instance, map function application over a list of functions.
```haskell=
ghci> map ($ 3) [(4+), (10*), (^2), sqrt]

ghci> (4+) $ 3
ghci> (10*) $ 3
ghci> (^2) $ 3
ghci> (sqrt) $ 3
```

