# Data.Char
###### tags: `Learn You a Haskell for Great Good!`

## What is Data.Char
It exports functions that deal with characters. It's also helpful when filtering and mapping over strings because they're just lists of characters.

`Data.Char` exports a bunch of predicates over characters. That is, functions that take a character and tell us whether some assumption about it is true or false.

## Data.char a bunch of function
`isControl` checks whether a character is a control character.

`isSpace` checks whether a character is a white-space characters. That includes spaces, tab characters, newlines, etc.

`isLower` checks whether a character is lower-cased.

`isUpper` checks whether a character is upper-cased.

`isAlpha` checks whether a character is a letter.

`isAlphaNum` checks whether a character is a letter or a number.

`isPrint` checks whether a character is printable. Control characters, for instance, are not printable.

`isDigit` checks whether a character is a digit.

`isOctDigit` checks whether a character is an octal digit.

`isHexDigit` checks whether a character is a hex digit.

`isLetter` checks whether a character is a letter.

`isMark` checks for Unicode mark characters. Those are characters that combine with preceding letters to form latters with accents. Use this if you are French.

`isNumber` checks whether a character is numeric.

`isPunctuation` checks whether a character is punctuation.

`isSymbol` checks whether a character is a fancy mathematical or currency symbol.

`isSeparator` checks for Unicode spaces and separators.

`isAscii` checks whether a character falls into the first 128 characters of the Unicode character set.

`isLatin1` checks whether a character falls into the first 256 characters of Unicode.

`isAsciiUpper` checks whether a character is ASCII and upper-case.

`isAsciiLower` checks whether a character is ASCII and lower-case.

All these predicates have a type signature of `Char -> Bool`.

### isAlphaNum
For instance, let's say we're making a program that takes a username and the username can only be comprised of alphanumeric characters. We can use the `Data.List` function `all` in combination with the `Data.Char` predicates to determine if the username is alright.
 
```haskell=
ghci> all isAlphaNum "bobby283"  
True  
ghci> all isAlphaNum "eddy the fish!"  
False
```

### isSpace
In case you don't remember, `all` takes a predicate and a list and returns `True` only if that predicate holds for every element in the list.

We can also use `isSpace` to simulate the `Data.List` function words.
```haskell=
ghci> words "hey guys its me"  
["hey","guys","its","me"]  
ghci> groupBy ((==) `on` isSpace) "hey guys its me"  
["hey"," ","guys"," ","its"," ","me"]  
ghci> filter (not . any isSpace) . groupBy ((==) `on` isSpace) $ "hey guys its me"  
["hey","guys","its","me"]  
```

###  enumeration type
Data.Char also exports a datatype that's kind of like Ordering

The Ordering type can have a value of `LT`, `EQ` or `GT`.

It's a sort of enumeration. It describes a few possible results that can arise from comparing two elements.

The `GeneralCategory` type is also an enumeration. It presents us with a few possible categories that a character can fall into. 

The main function for getting the general category of a character is `generalCategory`. It has a type of `generalCategory :: Char -> GeneralCategory`. There are about 31 categories so we won't list them all here, but let's play around with the function.

```haskell=
ghci> generalCategory ' '  
Space  
ghci> generalCategory 'A'  
UppercaseLetter  
ghci> generalCategory 'a'  
LowercaseLetter  
ghci> generalCategory '.'  
OtherPunctuation  
ghci> generalCategory '9'  
DecimalNumber  
ghci> map generalCategory " \t\nA9?|"  
[Space,Control,Control,UppercaseLetter,DecimalNumber,OtherPunctuation,MathSymbol] 
```

Since the `GeneralCategory` type is part of the `Eq` typeclass, we can also test for stuff like `generalCategory ' ' == Space`.

### more function
`toUpper` converts a character to upper-case. Spaces, numbers, and the like remain unchanged.

`toLower` converts a character to lower-case.

`toTitle` converts a character to title-case. For most characters, title-case is the same as upper-case.

`digitToInt` converts a character to an `Int`. To succeed, the character must be in the ranges `'0'..'9'`, `'a'..'f'` or `'A'..'F'`.
```haskell=
ghci> map digitToInt "34538"  
[3,4,5,3,8]  
ghci> map digitToInt "FF85AB"  
[15,15,8,5,10,11]  
```

`intToDigit` is the inverse function of `digitToInt`. It takes an `Int` in the range of `0..15` and converts it to a lower-case character.
```haskell=
ghci> intToDigit 15  
'f'  
ghci> intToDigit 5  
'5'  
```

The `ord` and `chr` functions convert characters to their corresponding numbers and vice versa:
```haskell=
ghci> ord 'a'  
97  
ghci> chr 97  
'a'  
ghci> map ord "abcdefgh"  
[97,98,99,100,101,102,103,104] 
```

### Caesar cipher
The Caesar cipher is a primitive method of encoding messages by shifting each character in them by a fixed number of positions in the alphabet.

We can easily create a sort of Caesar cipher of our own, only we won't constrict ourselves to the alphabet.

```haskell=
encode' :: Int -> String -> String
encode' shift msg =
  let ords = map ord msg
      shifted = map (+ shift) ords
   in map chr shifted
```

Here, we first convert the string to a list of numbers. Then we add the shift amount to each number before converting the list of numbers back to characters. If you're a composition cowboy, you could write the body of this function as `map (chr . (+ shift) . ord) msg`.

