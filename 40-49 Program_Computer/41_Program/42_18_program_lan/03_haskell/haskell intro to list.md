# haskell intro to list
###### tags: `Learn You a Haskell for Great Good!`

## list
- In Haskell, lists are a _homogenous_ data structure. It stores several elements of the same type. That means that we can have a list of integers or a list of characters but we can't have a list that has a few integers and then a few characters.
>  We can use the let keyword to define a name right in GHCI. Doing let a = 1 inside GHCI is the equivalent of writing a = 1 in a script and then loading it.
```haskell
ghci> let lostNumbers = [4,8,15,16,23,42] 
ghci> lostNumbers 
[4,8,15,16,23,42]
```
## ++ and : Operator
- Speaking of characters, **strings are just lists of characters**. "hello" is just syntactic sugar for \['h','e','l','l','o'\]. Because strings are lists, we can use list functions on them, which is really handy.
- A common task is putting two lists together. This is done by using the `++` operator.
```haskell
1.  ghci> [1,2,3,4] ++ [9,10,11,12] 
2.  [1,2,3,4,9,10,11,12] 
3.  ghci> "hello" ++ " " ++ "world" 
4.  "hello world" 
5.  ghci> ['w','o'] ++ ['o','t'] 
6.  "woot"
```
- Watch out when repeatedly using the `++` operator on long strings.  internally, Haskell has to walk through the whole list on the left side of `++`.
- However, putting something at the beginning of a list using the `:` operator (also called the cons operator) is instantaneous.
- \[1,2,3\] is actually just syntactic sugar for 1:2:3:\[\]. \[\] is an empty list. If we prepend 3 to it, it becomes \[3\]. If we prepend 2 to that, it becomes \[2,3\], and so on.
```haskell
ghci> [1,2,3,4] ++ [9,10,11,12]
[1,2,3,4,5,6,7,8,9,10,11,12]
ghci> "hello" ++ " " ++ "world"
"hello world"
ghci> ['w', 'o'] ++ ['o', 't']
"woot"
ghci> 'A':"SMALL CAT"
"A SMALL CAT"
ghci> 5:[1,2,3,4,5]
[5,1,2,3,4,5]
```
## !! Operator
- If you want to get an element out of a list by index, use !!. The indices start at 0.
```haskell
1.  ghci> "Steve Buscemi" !! 6 
2.  'B' 
3.  ghci> [9.4,33.2,96.2,11.2,23.25] !! 1 
4.  33.2
```

## list compare
- Lists can be compared if the stuff they contain can be compared. When using `<, <=, >` and`>=` to compare lists, they are compared in lexicographical order. First the heads are compared. If they are equal then the second elements are compared, etc.
```haskell
ghci> [3,2,1] > [2,1,0]  
True  
ghci> [3,2,1] > [2,10,100]  
True  
ghci> [3,4,2] > [3,4]  
True  
ghci> [3,4,2] > [2,4]  
True  
ghci> [3,4,2] == [3,4,2]  
True  
```
## basic functions operator on lists
- `head` takes a list and returns its head. The head of a list is basically its first element.
```haskell
ghci> head [5,4,3,2,1]  
5 
```
- `tail` takes a list and returns its tail. In other words, it chops off a list's head.
```haskell
ghci> tail [5,4,3,2,1]  
[4,3,2,1] 
```
- `last` takes a list and returns its last element.
```haskell
ghci> last [5,4,3,2,1]  
1   
```
- `init` takes a list and returns everything except its last element.
```haskell
ghci> init [5,4,3,2,1]  
[5,4,3,2]
```
- `length` takes a list and returns its length, obviously.
```haskell
ghci> length [5,4,3,2,1]  
5  
```
- `null` checks if a list is empty. If it is, it returns True, otherwise it returns False. Use this function instead of xs == \[\] (if you have a list called xs)
```haskell
ghci> null [1,2,3]  
False  
ghci> null []  
True  
```
- `reverse` reverses a list.
```haskell
ghci> reverse [5,4,3,2,1]  
[1,2,3,4,5]  
```
- `take` takes number and a list. It extracts that many elements from the beginning of the list. Watch.
```haskell
ghci> take 3 [5,4,3,2,1]  
[5,4,3]  
ghci> take 1 [3,9,3]  
[3]  
ghci> take 5 [1,2]  
[1,2]  
ghci> take 0 [6,6,6]  
[]  
```
- `drop` works in a similar way, only it drops the number of elements from the beginning of a list.
```haskell
ghci> drop 3 [8,4,2,1,5,6]  
[1,5,6]  
ghci> drop 0 [1,2,3,4]  
[1,2,3,4]  
ghci> drop 100 [1,2,3,4]  
[]
```
- `maximum` takes a list of stuff that can be put in some kind of order and returns the biggest element.
- `minimum` returns the smallest.
```haskell
ghci> minimum [8,4,2,1,5,6]  
1  
ghci> maximum [1,9,2,3,4]  
9
```
- `sum` takes a list of numbers and returns their sum.
- `product`  takes a list of numbers and returns their product.
```haskell
ghci> sum [5,2,1,6,3,2,5,7]  
31  
ghci> product [6,2,1,2]  
24  
ghci> product [1,2,5,6,7,9,2,0]  
0   
```
- `elem`  takes a thing and a list of things and tells us if that thing is an element of the list. It's usually called as an infix function because it's easier to read that way.
```haskell
ghci> 4 `elem` [3,4,5,6]  
True  
ghci> 10 `elem` [3,4,5,6]  
False  
```

