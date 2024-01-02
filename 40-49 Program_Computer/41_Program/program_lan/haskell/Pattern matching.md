# Pattern matching
###### tags: `Learn You a Haskell for Great Good!`

## Pattern matching
Pattern matching consists of specifying patterns to which some data should conform and then checking to see if it does and deconstructing the data according to those patterns

Let's make a really trivial function that checks if the number we supplied to it is a seven or not.

```haskell=
lucky :: (Integral a) => a -> String  
lucky 7 = "LUCKY NUMBER SEVEN!"  
lucky x = "Sorry, you're out of luck, pal!" 
```

This function could have also been implemented by using an if statement. But what if we wanted a function that says the numbers from 1 to 5 and says `"Not between 1 and 5" for any other number?` Without pattern matching, we'd have to make a pretty convoluted if then else tree. However, with it:

```haskell=
sayMe :: (Integral a) => a -> String  
sayMe 1 = "One!"  
sayMe 2 = "Two!"  
sayMe 3 = "Three!"  
sayMe 4 = "Four!"  
sayMe 5 = "Five!"  
sayMe x = "Not between 1 and 5"  
```

Note that if we moved the last pattern (the catch-all one) to the top, it would always say `"Not between 1 and 5"`, because it would catch all the numbers and they wouldn't have a chance to fall through and be checked for any other patterns.

## define factorial function recursively
```haskell=
factorial :: (Integral a) => a -> a  
factorial 0 = 1  
factorial n = n * factorial (n - 1) 
```

This is the first time we've defined a function recursively. Recursion is important in Haskell and we'll take a closer look at it later. But in a nutshell, this is what happens if we try to get the factorial of, say, 3. It tries to compute `3 * factorial 2`. The factorial of 2 is `2 * factorial 1`, so for now we have `3 * (2 * factorial 1)`. factorial 1 is `1 * factorial 0`, so we have `3 * (2 * (1 * factorial 0))`. Now here comes the trick — we've defined the factorial of 0 to be just 1 and because it encounters that pattern before the catch-all one, it just returns 1. So the final result is equivalent to `3 * (2 * (1 * 1))`.

## pattern matching in tuples
What if we wanted to make a function that takes two vectors in a 2D space (that are in the form of pairs) and adds them together? To add together two vectors, we add their x components separately and then their y components separately. Here's how we would have done it if we didn't know about pattern matching:
```haskell=
addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)  
addVectors a b = (fst a + fst b, snd a + snd b)  
```

Well, that works, but there's a better way to do it. Let's modify the function so that it uses pattern matching
```haskell=
addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)  
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2)
```
> Note that this is already a catch-all pattern. The type of `addVectors` (in both cases) is `addVectors :: (Num a) => (a, a) -> (a, a) - > (a, a)`, so we are guaranteed to get two pairs as parameters.

`fst` and `snd` extract the components of paris. But what about tuples? Well, there are no provided functions that do that but we can make our own.
```haskell=
first :: (a, b, c) -> a  
first (x, _, _) = x  
  
second :: (a, b, c) -> b  
second (_, y, _) = y  
  
third :: (a, b, c) -> c  
third (_, _, z) = z 
```

The `_` means the same thing as it does in list comprehensions. It means that we really don't care what that part is, so we just write a `_`.

## pattern matching in list
```haskell=
ghci> let xs = [(1,3), (4,3), (2,4), (5,3), (5,6), (3,1)]  
ghci> [a+b | (a,b) <- xs]  
[4,7,6,8,11,4]   
```

Lists themselves can also be used in pattern matching. You can match with the empty list `[]` or any pattern that involves `:` and the empty list. But since `[1,2,3]` is just syntactic sugar for `1:2:3:[]`, you can also use the former pattern. A pattern like `x:xs` will bind the head of the list to `x` and the rest of it to `xs`, even if there's only one element so `xs` ends up being an empty list.

> Note: The `x:xs` pattern is used a lot, especially with recursive functions. But patterns that have : in them only match against lists of length 1 or more.

If you want to bind, say, the first three elements to variables and the rest of the list to another variable, you can use something like `x:y:z:zs`. It will only match against lists that have three elements or more.

Now that we know how to pattern match against list, let's make our own implementation of the head function.
```haskell=
head' :: [a] -> a
head' [] = error "Can't call head on an empty list, dummy!"
head' (x:_) = x
ghci> head' [4,5,6]  
4  
ghci> head' "Hello"  
'H'
```

Notice that **if you want to bind to several variables (even if one of them is just `_` and doesn't actually bind at all), we have to surround them in parentheses**. Also notice the `error` function that we used. It takes a string and generates a runtime error, using that string as information about what kind of error occurred. It causes the program to crash, so it's not good to use it too much.

Let's make a trivial function that tells us some of the first elements of the list in (in)convenient English form.

```haskell=
tell :: (Show a) => [a] -> String  
tell [] = "The list is empty"  
tell (x:[]) = "The list has one element: " ++ show x  
tell (x:y:[]) = "The list has two elements: " ++ show x ++ " and " ++ show y  
tell (x:y:_) = "This list is long. The first two elements are: " ++ show x ++ " and " ++ show y  
```

This function is safe because it takes care of the empty list, a singleton list, a list with two elements and a list with more than two elements. Note that `(x:[])` and `(x:y:[])` could be rewriten as `[x]` and `[x,y]` (because its syntatic sugar, we don't need the parentheses). We can't rewrite `(x:y:_)` with square brackets because it matches any list of length 2 or more.

#### use pattern matching and recursive implement length
```haskell=
length' :: (Num b) => [a] -> b  
length' [] = 0  
length' (_:xs) = 1 + length' xs 
```

Let's see what happens if we call length' on "ham". First, it will check if it's an empty list. Because it isn't, it falls through to the second pattern. It matches on the second pattern and there it says that the length is `1 + length' "am"`, because we broke it into a head and a tail and discarded the head. O-kay. The length' of "am" is, similarly, `1 + length' "m"`. So right now we have `1 + (1 + length' "m")`. `length' "m"` is `1 + length' ""` (could also be written as `1 + length' [])`. And we've defined `length' []` to be 0. So in the end we have `1 + (1 + (1 + 0))`.

Let's implement `sum`.
```haskell=
sum' :: (Num a) => [a] -> a
sum' [] = 0
sum' (x:xs) = x + sum' xs
```

Those are a handy way of breaking something up according to a pattern and binding it to names whilst still keeping a reference to the whole thing. You do that by putting a name and an `@` in front of a pattern.

For instance, the pattern `xs@(x:y:ys)`. This pattern will match exactly the same thing as `x:y:ys` but you can easily get the whole list via `xs` instead of repeating yourself by typing out `x:y:ys` in the function body again.  Here's a quick and dirty example:
```haskell=
capital :: String -> String  
capital "" = "Empty string, whoops!"  
capital al

(x:xs) = "The first letter of " ++ all ++ " is " ++ [x]
ghci> capital "Dracula"  
"The first letter of Dracula is D"  
```
