# Only folds and horses
###### tags: `Learn You a Haskell for Great Good!`

## introduce forld
Back when we were dealing with recursion, we noticed a theme throughout many of the recursive functions that operated on lists. Usually, we'd have an edge case for the empty list. We'd introduce the `x:xs` pattern and then we'd do some action that involves a single element and the rest of the list. It turns out this is a very common pattern, so a couple of very useful functions were introduced to encapsulate it. **These functions are called folds**. They're sort of like the `map` function, only they reduce the list to some single value.


### fold concept
A fold takes a binary function, a starting value (I like to call it the accumulator) and a list to fold up.

**The binary function itself takes two parameters. The binary function is called with the accumulator and the first (or last) element and produces a new accumulator**. 

Then, the binary function is called again with the new accumulator and the now new first (or last) element, and so on. Once we've walked over the whole list, only the accumulator remains, which is what we've reduced the list to.

First let's take a look at the `foldl` function, also called the left fold. It folds the list up from the left side. **The binary function is applied between the starting value and the head of the list**. That produces a new accumulator value and the binary function is called with that value and the next element, etc.

###  implement sum again, only this time, we'll use a fold instead of explicit recursion
```haskell=
sum' :: (Num a) => [a] -> a
sum' xs = foldl (\acc x -> acc + x) 0 xs
```

Testing, one two three:
```haskell=
ghci> sum' [3,5,2,1]  
11  
```

Let's take an in-depth look into how this fold happens. `\acc x -> acc + x `is the binary function. `0` is the starting value and `xs` is the list to be folded up. Now first, `0` is used as the acc parameter to the binary function and `3` is used as the `x` (or the current element) parameter. `0 + 3` produces a `3` and it becomes the new accumulator value, so to speak.
![](https://i.imgur.com/ULBRwjs.png)

If we take into account that functions are curried, we can write this implementation ever more succinctly, like so:
```haskell=
sum' :: (Num a) => [a] -> a  
sum' = foldl (+) 0  
```

The lambda function `(\acc x -> acc + x)` is the same as `(+)`. We can omit the xs as the parameter because calling `foldl (+) 0` will return a function that takes a list. Generally, if you have a function like `foo a = bar b a`, you can rewrite it as `foo = bar b`, because of currying.

### implement elem use left fold
```haskell=
elem' :: (Eq a) => a -> [a] -> Bool  
elem' y ys = foldl (\acc x -> if x == y then True else acc) False ys  
```
The starting value and accumulator here is a boolean value. The type of the accumulator value and the end result is always the same when dealing with folds. 

### use right fold, foldr to implement map function
The right fold, `foldr` works in a similar way to the left fold, only the accumulator eats up the values from the right.

Also, the left fold's binary function has the accumulator as the first parameter and the current value as the second one `(so \acc x -> ...)`,the right fold's binary function has the current value as the first parameter and the accumulator as the second one `(so \x acc -> ...)`. 

It kind of makes sense that the right fold has the accumulator on the right, because it folds from the right side.

The accumulator value (and hence, the result) of a fold can be of any type. It can be a number, a boolean or even a new list.

We'll be implementing the map function with a right fold.

The accumulator will be a list, we'll be accumulating the mapped list element by element. From that, it's obvious that the starting element will be an empty list.
```haskell=
map' :: (a -> b) -> [a] -> b
map f xs = foldr (\x acc -> f x : acc) [] xs
```

If we're mapping `(+3)` to `[1,2,3]`, we approach the list from the right side. We take the last element, which is `3` and apply the function to it, which ends up being `6`. Then, we prepend it to the accumulator, which is was `[]`. `6:[]` is `[6]` and that's now the accumulator. We apply `(+3)` to `2`, that's `5` and we prepend `(:)` it to the accumulator, so the accumulator is now `[5,6]`. We apply `(+3)` to `1` and prepend that to the accumulator and so the end value is `[4,5,6]`.

Of course, we could have implemented this function with a left fold too. It would be `map' f xs = foldl (\acc x -> acc ++ [f x]) [] xs`, but the thing is that the `++` function is much more expensive than `:`, so we usually use right folds when we're building up new lists from a list.

### right fold and left fold compare
If you reverse a list, you can do a right fold on it just like you would have done a left fold and vice versa. Sometimes you don't even have to do that. The sum function can be implemented pretty much the same with a left and right fold. **One big difference is that right folds work on infinite lists, whereas left ones don't!**

To put it plainly, if you take an infinite list at some point and you fold it up from the right, you'll eventually reach the beginning of the list. However, if you take an infinite list at a point and you try to fold it up from the left, you'll never reach an end!

**Folds can be used to implement any function where you traverse a list once, element by element, and then return something based on that. Whenever you want to traverse a list to return something, chances are you want a fold.**


### foldl1 and foldr1
The `foldl1` and `foldr1` functions work much like `foldl` and `foldr`, only you don't need to provide them with an explicit starting value. 

They assume the first (or last) element of the list to be the starting value and then start the fold with the element next to it. With that in mind, the `sum` function can be implemented like so: `sum = foldl1 (+)`.

foldl and foldr, on the other hand, work fine with empty lists. When making a fold, think about how it acts on an empty list. If the function doesn't make sense when given an empty list, you can probably use a `foldl1` or `foldr1` to implement it.

```haskell=
maximum' :: (Ord a) => [a] -> a  
maximum' = foldr1 (\x acc -> if x > acc then x else acc)  
  
reverse' :: [a] -> [a]  
reverse' = foldl (\acc x -> x : acc) []  
{- you can also writte reverse like this -}
reverse' = foldl (flip (:)) []
  
product' :: (Num a) => [a] -> a  
product' = foldr1 (*)  
  
filter' :: (a -> Bool) -> [a] -> [a]  
filter' p = foldr (\x acc -> if p x then x : acc else acc) []  
  
head' :: [a] -> a  
head' = foldr1 (\x _ -> x)  
  
last' :: [a] -> a  
last' = foldl1 (\_ x -> x) 
```

Another way to picture right and left folds is like this: say we have a right fold and the binary function is `f` and the starting value is `z`.

If we're right folding over the list `[3,4,5,6]`, we're essentially doing this: `f 3 (f 4 (f 5 (f 6 z)))`. `f` is called with the last element in the list and the accumulator, that value is given as the accumulator to the next to last value and so on. 

If we take `f` to be `+` and the starting accumulator value to be `0`, that's `3 + (4 + (5 + (6 + 0)))`. 

Or if we write `+` as a prefix function, that's `(+) 3 ((+) 4 ((+) 5 ((+) 6 0)))`. 

Similarly, doing a left fold over that list with `g` as the binary function and `z` as the accumulator is the equivalent of `g (g (g (g z 3) 4) 5) 6`. 

If we use `flip (:)` as the binary function and `[]` as the accumulator (so we're reversing the list), then that's the equivalent of `flip (:) (flip (:) (flip (:) (flip (:) [] 3) 4) 5) 6`. And sure enough, if you evaluate that expression, you get `[6,5,4,3]`.

### scanl and scanr
`scanl` and `scanr` are like foldl and foldr, only they report all the intermediate accumulator states in the form of a list. There are also `scanl1` and `scanr1`, which are analogous to `foldl1` and `foldr1`.

```haskell=
ghci> scanl (+) 0 [3,5,2,1]  
[0,3,8,10,11]  
ghci> scanr (+) 0 [3,5,2,1]  
[11,8,3,1,0]  
ghci> scanl1 (\acc x -> if x > acc then x else acc) [3,4,5,3,7,9,2,1]  
[3,4,5,5,7,9,9,9]  
ghci> scanl (flip (:)) [] [3,2,1]  
[[],[3],[2,3],[1,2,3]] 
```

When using a `scanl`, the final result will be in the last element of the resulting list while a `scanr` will place the result in the head.

Scans are used to monitor the progression of a function that can be implemented as a fold.

### How many elements does it take for the sum of the roots of all natural numbers to exceed 1000?
To get the squares of all natural numbers, we just do `map sqrt [1..]`. Now, to get the sum, we could do a fold, but because we're interested in how the sum progresses, we're going to do a scan. Once we've done the scan, we just see how many sums are under 1000. The first sum in the scanlist will be 1, normally. The second will be 1 plus the square root of 2. The third will be that plus the square root of 3. **If there are X sums under 1000, then it takes X+1 elements for the sum to exceed 1000**.

```haskell=
sqrtSums :: Int
sqrtSums = length (takeWhile (<1000) (scanl1 (+) (map sqrt [1..]))) + 1

ghci> sqrtSums  
131  
ghci> sum (map sqrt [1..131])  
1005.0942035344083  
ghci> sum (map sqrt [1..130])  
993.6486803921487  
```
We use `takeWhile` here instead of `filter` because `filter` doesn't work on infinite lists. Even though we know the list is ascending, `filter` doesn't, so we use `takeWhile` to cut the scanlist off at the first occurence of a sum greater than 1000.

