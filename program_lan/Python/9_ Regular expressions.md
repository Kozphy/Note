# 9: Regular expressions
###### tags: `python learn`
## source
[reg search in list](https://stackoverflow.com/questions/3640359/regular-expressions-search-in-list)
-----

The regular expression library `re` must be imported into your program before you can use it. The simplest use of the regular expression library is the **search()** function. The
following program demonstrates a trivial use of the search function.
```python=
import re
hand = open('mbox-short.txt')
for line in hand:
    line = line.rstrip()
    if re.search('From:', line):
        print(line)
```

For example, the `caret character` is used in regular expressions to match “the beginning” of a line. We could change our program to only match lines where “From:” was at the beginning of the line as follows:
```python=
import re
hand = open('mbox-short.txt')
for line in hand:
    line = line.rstrip()
    if re.search('^From:', line):
        print(line)

```
## Character matching in regular expressions
In the following example, **the regular expression “F..m:”** would match any of the strings “From:”, “Fxxm:”, “Fm:”, or “F!@m:” since **the period characters in the regular expression match any character**.
```python=
import re
hand = open('mbox-short.txt')
    for line in hand:
        line = line.rstrip()
        if re.search('^F..m:', line):
            print(line)
```
This is particularly powerful when combined with the ability to indicate that a character can be repeated any number of times using the “*” or “+” characters in your regular expression. 

**These special characters mean that instead of matching a single character in the search string, they match zero-or-more characters (in the case of the asterisk) or one-or-more of the characters (in the case of the plus sign)**.

```python=
import re
hand = open('mbox-short.txt')
for line in hand:
    line = line.rstrip()
    if re.search('^From:.+@', line):
        print(line)
```

## Extracting data using regular expressions
If we want to extract data from a string in Python we can use the `findall()` method to extract all of the substrings which match a regular expression. Let’s use the example
of wanting to extract anything that looks like an email address from any line regardless of format. 

We don’t want to write code for each of the types of lines, splitting and slicing differently for each line. This following program uses findall() to find the lines with email addresses in them and extract one or more addresses from each of those lines.

```python=
import re
s = 'A message from csev@umich.edu to cwen@iupui.edu about meeting @2PM'
lst = re.findall('\S+@\S+', s)
print(lst)
```
The `findall()` method searches the string in the second argument and returns a list of all of the strings that look like email addresses. We are using a two-character sequence
that matches a non-whitespace character (\S).

```python=
import re
hand = open('mbox-short.txt')
for line in hand:
    line = line.rstrip()
x = re.findall('\S+@\S+', line)
if len(x) > 0:
    print(x)
```

Square brackets are used to indicate a set of multiple acceptable characters we are willing to consider matching. In a sense, the “\S” is asking to match the set of “non-whitespace characters”. Now we will be a little more explicit in terms of the characters we will match.

This is getting a little complicated and you can begin to see why regular expressions are their own little language unto themselves. Translating this regular expression, we are
looking for substrings that start with a single lowercase letter, uppercase letter, or number “[a-zA-Z0-9]”, followed by zero or more non-blank characters (“\S*”), followed by an atsign, followed by zero or more non-blank characters (“\S*”), followed by an uppercase or lowercase letter. Note that we switched from “+” to “*” to indicate zero or more nonblank characters since “[a-zA-Z0-9]” is already one non-blank character. Remember that the “*” or “+” applies to the single character immediately to the left of the plus or asterisk.
```python=
import re
hand = open('mbox-short.txt')
for line in hand:
    line = line.rstrip()
x = re.findall('[a-zA-Z0-9]\S+@\S+[a-zA-Z]', line)
if len(x) > 0:
    print(x)
```

## Combining searching and extracting
If we want to find numbers on lines that start with the string “X-” such as:
```python=
X-DSPAM-Confidence: 0.8475
X-DSPAM-Probability: 0.0000
```
```python=
import re
hand = open('mbox-short.txt')
for line in hand:
    line = line.rstrip()
    if re.search('^X\S*: [0-9.]+', line):
        print(line)


```
Parentheses are another special character in regular expressions. When you add parentheses to a regular expression, they are ignored when matching the string. But when you are using `findall()`, parentheses indicate that while you want the whole expression to match, you only are interested in extracting a portion of the substring that matches the regular expression.
```python=
import re
hand = open('mbox-short.txt')
for line in hand:
    line = line.rstrip()
    x = re.findall('^X\S*: ([0-9.]+)', line)
    if len(x) > 0:
        print(x)
```
Instead of calling `search()`, we add parentheses around the part of the regular expression that represents the floating-point number to indicate we only want `findall()` to give us back the floating-point number portion of the matching string.

Now we can use regular expressions to redo an exercise from earlier in the book where we were interested in the time of day of each mail message. We wanted to extract the hour of the day for each line.
We looked for lines of the form:
```txt
From stephen.marquard@uct.ac.za Sat Jan 5 09:14:16 2008
```

```python=
import re
hand = open('mbox-short.txt')
for line in hand:
    line = line.rstrip()
    x = re.findall('^From .* ([0-2][0-9]):', line)
    if len(x) > 0:
        print(x)

```

## Escape character
Since we use special characters in regular expressions to match the beginning or end of a line or specify wild cards, we need a way to indicate that these characters are “normal” and we want to match the actual character such as a dollar sign or caret.

We can indicate that we want to simply match a character by prefixing that character with a backslash.
```python=
import re
x = 'We just received $10.00 for cookies.'
y = re.findall('\$[0-9.]+', x)
```
**Note: Inside square brackets, characters are not “special”. So when we say “[0-9.]”, it really means digits or a period. Outside of square brackets, a period is the “wild-card” character and matches any character. Inside square brackets, the period is a period.**

 ## Summary
- ^ Matches the beginning of the line.
- $ Matches the end of the line.
- . Matches any character (a wildcard).
- \s Matches a whitespace character.
- \S Matches a non-whitespace character (opposite of \s).
- * Applies to the immediately preceding character and indicates to match zero or more of the preceding character(s).
- *? Applies to the immediately preceding character and indicates to match zero or more of the preceding character(s) in “non-greedy mode”.
- + Applies to the immediately preceding character and indicates to match one or more of the preceding character(s).
- +? Applies to the immediately preceding character and indicates to match one or more of the preceding character(s) in “non-greedy mode”.
- [aeiou] Matches a single character as long as that character is in the specified set. In this example, it would match “a”, “e”, “i”, “o”, or “u”, but no other characters.
- [a-z-] You can specify ranges of characters using the minus sign. This example is a single character that must be a lowercase letter or a digit.
- [ˆA-Za-z] When the first character in the set notation is a caret, it inverts the logic. This example matches a single character that is anything other than an uppercase or lowercase letter.
- ( ) When parentheses are added to a regular expression, they are ignored for the purpose of matching, but allow you to extract a particular subset of the matched string rather than the whole string when using findall().
- \b Matches the empty string, but only at the start or end of a word.
- \B Matches the empty string, but not at the start or end of a word.
- \d Matches any decimal digit; equivalent to the set [0-9] character; equivalent to the set [ˆ0-9].

## Bonus section for Unix / Linux users
As a matter of fact, there is a command-line program built into Unix called grep (Generalized Regular Expression Parser) that does pretty much the same as the `search()` examples in this chapter. So if you have a Macintosh or Linux system, you can try the following commands in your command-line window.
```vim
$ grep '^From:' mbox-short.txt
From: stephen.marquard@uct.ac.za
From: louis@media.berkeley.edu
From: zqian@umich.edu
From: rjlowe@iupui.edu
From: zqian@umich.edu
```

This tells **grep** to show you lines that start with the string “From:” in the file mbox-short.txt. If you experiment with the **grep** command a bit and read the documentation for **grep**, you will find some subtle differences between the regular expression support in Python and the regular expression support in **grep**. As an example, **grep** does not support the non-blank character “\S” so you will need to use the slightly more complex set notation “[^ ]”, which simply means match a character that is anything other than a space.
