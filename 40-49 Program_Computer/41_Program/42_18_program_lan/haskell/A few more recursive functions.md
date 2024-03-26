# A few more recursive functions
###### tags: `Learn You a Haskell for Great Good!`

### replicate recursive
First off, we'll implement `replicate`. `replicate` takes an `Int` and some element and returns a list that has several repetitions of the same element.

For instance, `replicate 3 5` returns `[5,5,5]`.
```haskell=
replicate' :: (Num i, Ord i) => i -> a -> [a]
replicate' n x
    | n <= 0 = []
    | otherwise = x:replicate' (n-1) 
```

We used guards here instead of patterns because we're testing for a boolean condition. If `n` is less than or equal to 0, return an empty list. Otherwise return a list that has `x` as the first element and then `x` replicated n-1 times as the tail. Eventually, the `(n-1)` part will cause our function to reach the edge condition.

> Note: `Num` is not a subclass of `Ord`. That means that what constitutes for a number doesn't really have to adhere to an ordering. So that's why we have to specify both the `Num` and `Ord` class constraints when doing addition or subtraction and also comparison.

### take recursive
Next up, we'll implement `take`. It takes a certain number of elements from a list. For instance, `take 3 [5,4,3,2,1]` will return `[5,4,3]`. If we try to take 0 or less elements from a list, we get an empty list. Also if we try to take anything from an empty list, we get an empty list. Notice that those are two edge conditions right there. So let's write that out:

```haskell=
take' :: (Num i, Ord i) => i -> [a] -> [a]
take' n _
    | n <= 0 = []
take' _ [] = []
take' n (x:xs) = x:take' (n-1) xs
```
Try using a piece of paper to write down how the evaluation would look like if we try to take, say, 3 from `[4,3,2,1]`.

### reverse recursive
`reverse` simply reverses a list. Think about the edge condition. 
```haskell=
reverse' :: [a] -> [a]  
reverse' [] = []  
reverse' (x:xs) = reverse' xs ++ [x]
```

### repeat recursive
Because Haskell supports infinite lists, our recursion doesn't really have to have an edge condition. But if it doesn't have it, it will either keep churning at something infinitely or produce an infinite data structure, like an infinite list. The good thing about infinite lists though is that we can cut them where we want. `repeat` takes an element and returns an infinite list that just has that element. A recursive implementation of that is really easy, watch.
```haskell=
repeat' :: a -> [a]  
repeat' x = x:repeat' x  
```
repeat `3` will never finish evaluating, whereas take 5 (repeat 3) will give us a list of five 3's. So essentially it's like doing replicate 5 3.

### zip recursive
`zip` takes two lists and zips them together. `zip [1,2,3] [2,3]` returns `[(1,2),(2,3)]`, because it truncates the longer list to match the length of the shorter one. How about if we zip something with an empty list? Well, we get an empty list back then. So there's our edge condition. However, `zip` takes two lists as parameters, so there are actually two edge conditions.

```haskell=
zip' :: [a] -> [b] -> [(a,b)]  
zip' _ [] = []  
zip' [] _ = []  
zip' (x:xs) (y:ys) = (x,y):zip' xs ys  
```

First two patterns say that if the first list or second list is empty, we get an empty list. The third one says that two lists zipped are equal to pairing up their heads and then tacking on the zipped tails. Zipping `[1,2,3]` and `['a','b']` will eventually try to zip `[3]` with `[]`. The edge condition patterns kick in and so the result is `(1,'a'):(2,'b'):[]`, which is exactly the same as `[(1,'a'),(2,'b')]`.

### elem recursion
 It takes an element and a list and sees if that element is in the list.
 ```haskell
 elem' :: (Eq a) => a -> [a] -> Bool  
elem' a [] = False  
elem' a (x:xs)  
    | a == x    = True  
    | otherwise = a `elem'` xs  
 ```