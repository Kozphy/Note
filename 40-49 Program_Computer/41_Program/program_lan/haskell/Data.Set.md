# Data.Set
###### tags: `Learn You a Haskell for Great Good!`

## what is Data.set
**Sets are kind of like a cross between lists and maps**.

**All the elements in a set are unique**. And because they're internally implemented with trees (much like maps in Data.Map), **they're ordered**.

The most common operation when dealing with sets are inserting into a set, checking for membership and converting a set to a list.


## use Data.set
Because the names in `Data.Set` clash with a lot of `Prelude` and `Data.List` names, we do a qualified import.
```haskell=
import qualified Data.Set as Set
```

Let's say we have two pieces of text. We want to find out which characters were used in both of them.
```haskell=
text1 = "I just had an anime dream. Anime... Reality... Are they so different?"  
text2 = "The old man left his garbage can out and now his trash is all over my lawn!"  
```

The `fromList` function works much like you would expect. **It takes a list and converts it into a set**.
```haskell=
ghci> let set1 = Set.fromList text1  
ghci> let set2 = Set.fromList text2  
ghci> set1  
fromList " .?AIRadefhijlmnorstuy"
ghci> set2  
fromList " !Tabcdefghilmnorstuvwy"
```

As you can see, the items are ordered and each element is unique. Now let's use the `intersection` function to see which elements they both share.
```haskell=
ghci> Set.intersection set1 set2  
fromList " adefhilmnorstuy"  
```

We can use the difference function to see which letters are in the first set but aren't in the second one and vice versa.
```haskell=
ghci> Set.difference set1 set2  
fromList ".?AIRj"  
ghci> Set.difference set2 set1  
fromList "!Tbcgvw"  
```

Or we can see all the unique letters used in both sentences by using `union`.
```haskell=
ghci> Set.union set1 set2  
fromList " !.?AIRTabcdefghijlmnorstuvwy"  
```

The `null`, `size`, `member`, `empty`, `singleton`, `insert` and `delete` functions all work like you'd expect them to.
```haskell=
ghci> Set.null Set.empty  
True  
ghci> Set.null $ Set.fromList [3,4,5,5,4,3]  
False  
ghci> Set.size $ Set.fromList [3,4,5,3,4,5]  
3  
ghci> Set.singleton 9  
fromList [9]  
ghci> Set.insert 4 $ Set.fromList [9,3,8,1]  
fromList [1,3,4,8,9]  
ghci> Set.insert 8 $ Set.fromList [5..10]  
fromList [5,6,7,8,9,10]  
ghci> Set.delete 4 $ Set.fromList [3,4,5,4,3,4,5]  
fromList [3,5]  
```

We can also check for subsets or proper subset. Set A is a subset of set B if B contains all the elements that A does. Set A is a proper subset of set B if B contains all the elements that A does but has more elements.
```haskell=
ghci> Set.fromList [2,3,4] `Set.isSubsetOf` Set.fromList [1,2,3,4,5]  
True  
ghci> Set.fromList [1,2,3,4,5] `Set.isSubsetOf` Set.fromList [1,2,3,4,5]  
True  
ghci> Set.fromList [2,3,4,8] `Set.isSubsetOf` Set.fromList [1,2,3,4,5]  
False  
ghci> Set.fromList [1,2,3,4,5] `Set.isProperSubsetOf` Set.fromList [1,2,3,4,5]  
False  
ghci> Set.fromList [1,2,3] `Set.isProperSubsetOf` Set.fromList [1,2,3,4]
```
We can also `map` over sets and `filter` them.
```haskell=
ghci> Set.filter odd $ Set.fromList [3,4,5,6,7,2,3,4]
fromList [3,5,7]
ghci> Set.map (+1) $ Set.fromList [3,4,5,6,7,2,3,4]  
fromList [3,4,5,6,7,8] 
```

