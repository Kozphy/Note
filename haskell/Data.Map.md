# Data.Map
###### tags: `Learn You a Haskell for Great Good!`

### what is map
Association lists (also called dictionaries) are lists that are used to store key-value pairs where ordering doesn't matter. 

The most obvious way to represent association lists in Haskell would be by having a list of pairs. The first component in the pair would be the key, the second component the value. Here's an example of an association list with phone numbers:
```haskell=
phoneBook =   
    [("betty","555-2938")  
    ,("bonnie","452-2928")  
    ,("patsy","493-2928")  
    ,("lucille","205-2928")  
    ,("wendy","939-8282")  
    ,("penny","853-2492")  
    ]  
```
### search map value
Despite this seemingly odd indentation, this is just a list of pairs of strings. The most common task when dealing with association lists is looking up some value by key. Let's make a function that looks up some value given a key.
```haskell=
findKey :: (Eq k) => k -> [(k,v)] -> v  
findKey key xs = snd . head . filter (\(k,v) -> key == k) $ xs  
```

The function that takes a key and a list, filters the list so that only matching keys remain, gets the first key-value that matches and returns the value. But what happens if the key we're looking for isn't in the association list? 
```haskell=
findKey :: (Eq k) => k -> [(k,v)] -> Maybe v  
findKey key [] = Nothing  
findKey key ((k,v):xs) = if key == k  
                            then Just v  
                            else findKey key xs 
```

### search map value use foldr
```haskell=
findKey' :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey' key = foldr (\(k, v) acc -> if key == k then Just v else acc) Nothing
```

> Note: It's usually better to use folds for this standard list recursion pattern instead of explicitly writing the recursion because they're easier to read and identify. Everyone knows it's a fold when they see the foldr call, but it takes some more thinking to read explicit recursion.

## Let's go ahead and see what Data.Map has in store for us! Here's the basic rundown of its functions.
Because Data.Map exports functions that clash with the Prelude and Data.List ones, we'll do a qualified import.
```haskell=
import qualified Data.Map as Map  
```

### fromList
**The `fromList` function takes an association list (in the form of a list) and returns a map with the same associations.**
```haskell=
ghci> Map.fromList [("betty","555-2938"),("bonnie","452-2928"),("lucille","205-2928")]  
fromList [("betty","555-2938"),("bonnie","452-2928"),("lucille","205-2928")]  
ghci> Map.fromList [(1,2),(3,4),(3,2),(5,5)]  
fromList [(1,2),(3,2),(5,5)]  
```
If there are duplicate keys in the original association list, the duplicates are just discarded. This is the type signature of `fromList`

```haskell=
Map.fromList :: (Ord k) => [(k, v)] -> Map.Map k v  
```

You should always use `Data.Map` for key-value associations unless you have keys that aren't part of the `Ord` typeclass.

### empty
`empty` represents an empty map. It takes no arguments, it just returns an empty map.
```haskell=
ghci> Map.empty  
fromList [] 
```

### insert
`insert` takes a key, a value and a map and returns a new map that's just like the old one, only with the key and value inserted.
```haskell=
ghci> Map.empty  
fromList []  
ghci> Map.insert 3 100 Map.empty  
fromList [(3,100)]  
ghci> Map.insert 5 600 (Map.insert 4 200 ( Map.insert 3 100  Map.empty))  
fromList [(3,100),(4,200),(5,600)]  
ghci> Map.insert 5 600 . Map.insert 4 200 . Map.insert 3 100 $ Map.empty  
fromList [(3,100),(4,200),(5,600)]  
```

We can implement our own `fromList` by using the empty map, insert and a `fold`. Watch:
```haskell=
fromList' :: (Ord k) => [(k,v)] -> Map.Map k v  
fromList' = foldr (\(k,v) acc -> Map.insert k v acc) Map.empty  
```

### null
`null` checks if a map is empty.
```haskell=
ghci> Map.null Map.empty  
True  
ghci> Map.null $ Map.fromList [(2,3),(5,5)]  
False 
```
### size
size reports the size of a map.
```haskell=
ghci> Map.size Map.empty  
0  
ghci> Map.size $ Map.fromList [(2,4),(3,3),(4,2),(5,4),(6,4)]  
5  
```

### singleton
`singleton` takes a key and a value and creates a map that has exactly one mapping.
```haskell=
ghci> Map.singleton 3 9  
fromList [(3,9)]  
ghci> Map.insert 5 9 $ Map.singleton 3 9  
fromList [(3,9),(5,9)] 
```

### lookup
`lookup` works like the `Data.List lookup`, only it operates on maps. It returns `Just something` if it finds something for the key and `Nothing` if it doesn't.

### member
member is a predicate takes a key and a map and reports whether the key is in the map or not.
```haskell=
ghci> Map.member 3 $ Map.fromList [(3,6),(4,3),(6,9)]  
True  
ghci> Map.member 3 $ Map.fromList [(2,5),(4,5)]  
False  
```

### map and filter
`map` and `filter` work much like their list equivalents.
```haskell=
ghci> Map.map (*100) $ Map.fromList [(1,1),(2,4),(3,9)]  
fromList [(1,100),(2,400),(3,900)]  
ghci> Map.filter isUpper $ Map.fromList [(1,'a'),(2,'A'),(3,'b'),(4,'B')]  
fromList [(2,'A'),(4,'B')]
```

### toList
`toList` is the inverse of `fromList`
```haskell=
ghci> Map.toList . Map.insert 9 2 $ Map.singleton 4 3  
[(4,3),(9,2)]  
```

`keys` and `elem` return lists of keys and values respectively. `keys` is the equivalent of `map fst. Map.toList` and `elems` is the equivalent of `map snd . Map.toList`

### fromListWith
`fromListWith` is a cool little function. It acts like `fromList`, only it doesn't discard duplicate keys but it uses a function supplied to it to decide what to do with them. Let's say that a girl can have several numbers and we have an association list set up like this.
```haskell=
phoneBook =   
    [("betty","555-2938")  
    ,("betty","342-2492")  
    ,("bonnie","452-2928")  
    ,("patsy","493-2928")  
    ,("patsy","943-2929")  
    ,("patsy","827-9162")  
    ,("lucille","205-2928")  
    ,("wendy","939-8282")  
    ,("penny","853-2492")  
    ,("penny","555-2111")  
    ]  
```
Now if we just use `fromList` to put that into a map, we'll lose a few numbers! So here's what we'll do:
```haskell=
phoneBookToMap :: (Ord k) => [(k, String)] -> Map.Map k String  
phoneBookToMap xs = Map.fromListWith (\number1 number2 -> number1 ++ ", " ++ number2) xs
```
```haskell=
ghci> Map.lookup "patsy" $ phoneBookToMap phoneBook  
"827-9162, 943-2929, 493-2928"  
ghci> Map.lookup "wendy" $ phoneBookToMap phoneBook  
"939-8282"  
ghci> Map.lookup "betty" $ phoneBookToMap phoneBook  
"342-2492, 555-2938"
```

If a duplicate key is found, the function we pass is used to combine the values of those keys into some other value. We could also first make all the values in the association list singleton lists and then we can use `++` to combine the numbers.
```haskell=
phoneBookToMap :: (Ord k) => [(k, a)] -> Map.Map k [a]  
phoneBookToMap xs = Map.fromListWith (++) $ map (\(k,v) -> (k,[v])) xs  

ghci> Map.lookup "patsy" $ phoneBookToMap phoneBook  
["827-9162","943-2929","493-2928"]  
```

Pretty neat! Another use case is if we're making a map from an association list of numbers and when a duplicate key is found, we want the biggest value for the key to be kept.
```haskell=
ghci> Map.fromListWith max [(2,3),(2,5),(2,100),(3,29),(3,22),(3,11),(4,22),(4,15)]  
fromList [(2,100),(3,29),(4,22)]  
```
Or we could choose to add together values on the same keys.
```haskell=
ghci> Map.fromListWith (+) [(2,3),(2,5),(2,100),(3,29),(3,22),(3,11),(4,22),(4,15)]  
fromList [(2,108),(3,62),(4,37)] 
```

`insertWith` is to `insert` what `fromListWith` is to `fromList`. It inserts a key-value pair into a map, but if that map already contains the key, it uses the function passed to it to determine what to do.
```haskell=
ghci> Map.insertWith (+) 3 100 $ Map.fromList [(3,4),(5,103),(6,339)]  
fromList [(3,104),(5,103),(6,339)]  
```

These were just a few functions from `Data.Map`. You can see a complete list of functions in the documentation.

