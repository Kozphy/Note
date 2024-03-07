# regex 符號

## 用途
- Search / Match (Validation)
- Replace
- Extract

## Quantifiers
| Quantifiers | description                     |
| ----------- | ------------------------------- |
| *           | 0 or more                       |
| +           | 1 or more                       |
| ?           | 0 or 1                          |
| {m}         | Exactly m times                 |
| {n,}        | Min n times                     |
| {m, n}      | From m to n times               |
| {m, n}?     | From m to n, as few as possible |


## 字符串介紹
| Special sequence   | description                          |
| ------------------ | ------------------------------------ |
| *                  | 可以表達任何東西                     |
| \\d                | digit (0-9)                          |
| \\D                | Not a Digit (0-9)                    |
| \\w                | Word character (a-z, A-Z, 0-9,_)     |
| \\W                | Not a word character                 |
| \\s                | Whitespace (space, tab, blank, line) |
| \\S                | Non-whitespace                       |
| \\b                | Word boundary                        |
| \\B                | Not a word boundary                  |
| \\A or ^           | Start of string                      |
| \\Z or $           | End of string                        |
| \\g<id>            | Matches a previously defined group   |
| \\                 | Escape special characters            |
| .                  | Matches any character                |
| $                  | Matches end of string                |
| ^                  | Matches beginning of string          |
| []                 | Matches characters in bracket        |
| [^]                | Matches characters NOT in bracket    |
| \|                 | Either or                            |
| ()                 | Group                                |