# Quick, sort
###### tags: `Learn You a Haskell for Great Good!`

We have a list of items that can be sorted. Their type is an instance of the `Ord` typeclass. And now, we want to sort them! There's a very cool algoritm for sorting called quicksort.

## quick sort
the type signature is going to be `quicksort :: (Ord a) => [a] -> [a]`.
Now here comes the main algorithm: **a sorted list is a list that has all the values smaller than (or equal to) the head of the list in front (and those values are sorted), then comes the head of the list in the middle and then come all the values that are bigger than the head (they're also sorted)**.
```haskell=
quicksort :: (Ord a) => [a] -> [a]  
quicksort [] = []  
quicksort (x:xs) =   
    let smallerSorted = quicksort [a | a <- xs, a <= x]  
        biggerSorted = quicksort [a | a <- xs, a > x]  
    in  smallerSorted ++ [x] ++ biggerSorted  
```

That's what I'm talking about! So if we have, say `[5,1,9,4,6,7,3]` and we want to sort it, this algorithm will first take the head, which is 5 and then put it in the middle of two lists that are smaller and bigger than it. So at one point, you'll have `[1,4,3] ++ [5] ++ [9,6,7]`. Here's an illustration:

![](https://i.imgur.com/i7Elqvs.png)

An element that is in place and won't move anymore is represented in <font color="orange">**orange**</font>. If you read them from left to right, you'll see the sorted list. Although we chose to compare all the elements to the heads, we could have used any element to compare against. In quicksort, an element that you compare against is called a pivot. They're in <font color="green">**green**</font> here. We chose the head because it's easy to get by pattern matching. The elements that are smaller than the pivot are <font color="lightgreen">**light green**</font> and elements larger than the pivot are dark green. The yellowish gradient thing represents an application of quicksort