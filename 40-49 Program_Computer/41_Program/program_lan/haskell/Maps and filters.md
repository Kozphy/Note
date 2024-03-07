# Maps and filters
###### tags: `Learn You a Haskell for Great Good!`

## map
`map` takes a function and a list and applies that function to every element in the list, producing a new list. Let's see what its type signature is and how it's defined.

```haskell=
map :: (a -> b) -> [a] -> [b]  
map _ [] = []  
map f (x:xs) = f x : map f xs  
```
The type signature says that it takes a function that takes an `a` and returns a `b`, a list of `a`'s and returns a list of `b`'s. `map` is one of those really versatile higher-order functions that can be used in millions of different ways. Here it is in action:
```haskell=
ghci> map (+3) [1,5,3,1,6]  
[4,8,6,4,9]  
ghci> map (++ "!") ["BIFF", "BANG", "POW"]  
["BIFF!","BANG!","POW!"]  
ghci> map (replicate 3) [3..6]  
[[3,3,3],[4,4,4],[5,5,5],[6,6,6]]  
ghci> map (map (^2)) [[1,2],[3,4,5,6],[7,8]]  
[[1,4],[9,16,25,36],[49,64]]  
ghci> map fst [(1,2),(3,5),(6,3),(2,6),(2,5)]  
[1,3,6,2,2]  
```
## filter
`filter` is a function that takes a predicate (a predicate is a function that tells whether something is true or not, so in our case, a function that returns a boolean value) and a list and then returns the list of elements that satisfy the predicate. The type signature and implementation go like this:
```haskell=
filter :: (a -> Bool) -> [a] -> [a]  
filter _ [] = []  
filter p (x:xs)   
    | p x       = x : filter p xs  
    | otherwise = filter p xs
```

Pretty simple stuff. If `p x` evaluates to `True`, the element gets included in the new list. If it doesn't, it stays out. Some usage examples:
```haskell=
ghci> filter (>3) [1,5,3,2,1,6,4,3,2,1]  
[5,6,4]  
ghci> filter (==3) [1,2,3,4,5]  
[3]  
ghci> filter even [1..10]  
[2,4,6,8,10]  
ghci> let notNull x = not (null x) in filter notNull [[1,2,3],[],[3,4,5],[2,2],[],[],[]]  
[[1,2,3],[3,4,5],[2,2]]  
ghci> filter (`elem` ['a'..'z']) "u LaUgH aT mE BeCaUsE I aM diFfeRent"  
"uagameasadifeent"  
ghci> filter (`elem` ['A'..'Z']) "i lauGh At You BecAuse u r aLL the Same"  
"GAYBALLS"  
```

All of this could also be achived with list comprehensions by the use of predicates. There's no set rule for when to use `map` and `filter` versus using list comprehension, you just have to decide what's more readable depending on the code and the context.

### use filter to implement quicksort
```haskell=
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
    let smallerSorted = quicksort (filter (<=x) xs)
        biggerSorted = quicksort (filter (>x) xs)
    in smallerSorted ++ [x] ++ biggerSorted
```

### largest number under 100,000 that's divisible by 3829 
Let's find the `largest number under 100,000 that's divisible by 3829`. To do that, we'll just filter a set of possibilities in which we know the solution lies.
```haskell=
largestDivisible :: (Integral a) => a
largestDivisible = head (filter p [100000,99999..])
    where p x = x `mod` 3829 == 0
```

### find the sum of all odd squares that are smaller than 10,000
Next up, we're going to **find the sum of all odd squares that are smaller than 10,000**. But first, because we'll be using it in our solution, we're going to introduce the `takeWhile` function.

#### takeWhile function
**It takes a predicate and a list and then goes from the beginning of the list and returns its elements while the predicate holds true**. Once an element is found for which the predicate doesn't hold, it stops. If we wanted to get the first word of the string ``"elephants know how to party"``, we could do `takeWhile (/=' ') "elephants know how to party"` and it would return "elephants". 

```haskell=
ghci> sum (takeWhile (<10000) (filter odd (map (^2) [1..])))  
166650 
```

We could have also written this using list comprehensions:
```haskell=
*Main> sum (takeWhile (<10000) [n^2 | n <- [1..], odd n])
166650
```

It's a matter of taste as to which one you find prettier. Again, Haskell's property of laziness is what makes this possible. **We can map over and filter an infinite list, because it won't actually map and filter it right away, it'll delay those actions.** Only when we force Haskell to show us the `sum` does the sum function say to the `takeWhile` that it needs those numbers. **`takeWhile` forces the filtering and mapping to occur, but only until a number greater than or equal to 10,000 is encountered.**

### dealing with Collatz sequences
We take a natural number. If that number is even, we divide it by two. If it's odd, we multiply it by 3 and then add 1 to that. We take the resulting number and apply the same thing to it, which produces a new number and so on.

```haskell=
chain :: (Integral a) => a -> [a]  
chain 1 = [1]  
chain n  
    | even n =  n:chain (n `div` 2)  
    | odd n  =  n:chain (n*3 + 1) 

ghci> chain 10  
[10,5,16,8,4,2,1]  
ghci> chain 1  
[1]  
ghci> chain 30  
[30,15,46,23,70,35,106,53,160,80,40,20,10,5,16,8,4,2,1] 
```
Now what we want to know is this: **for all starting numbers between 1 and 100, how many chains have a length greater than 15?**
```haskell=
numLongChains :: Int  
numLongChains = length (filter isLong (map chain [1..100]))  
    where isLong xs = length xs > 15  
```
> Note: This function has a type of `numLongChains :: Int` because `length` returns an `Int` instead of a `Num a` for historical reasons. If we wanted to return a more general `Num a`, we could have used `fromIntegral` on the resulting length.

So far, we've only mapped functions that take one parameter over lists, like `map (*2) [0..]` to get a list of type `(Num a) => [a]`, but we can also do `map (*) [0..]` without a problem. 

What happens here is that the number in the list is applied to the function `*`, which has a type of `(Num a) => a -> a -> a`. Applying only one parameter to a function that takes two parameters returns a function that takes one parameter. If we map `*` over the list `[0..]`, we get back a list of functions that only take one parameter, so `(Num a) => [a -> a]`. `map (*) [0..]` produces a list like the one we'd get by writing `[(0*),(1*),(2*),(3*),(4*),(5*)...`.

```haskell=
ghci> let listOfFuns = map (*) [0..]  
ghci> (listOfFuns !! 4) 5  
20  
```
Getting the element with the index `4` from our list returns a function that's equivalent to `(4*)`. And then, we just apply `5` to that function. So that's like writing `(4*) 5` or just `4 * 5`.

