# Moving Fast: Motions
###### tags: `vim tutorial`

## movement
           ↑
     ← h j k l →
         ↓
         
## change mode
- Type `i` to get into **Insert mode**.
- Type `<ESC>`, `<CTRL-[>` or `<CTRL-C>` to get back to **Normal mode**.

## Moving horizontally Word by Word
Let's start with two great motions to move horizontally:

- `w` to move word by word
- `b` to jump to the start of the previous word

Using `w` and `b` go to the end of the following sentence and back.

- `W` to move word by WORD
- `B` to move backwards WORD by WORD

- `e` to jump to the end of a word
- `ge` to jump to the end of the previous word


## Moving to Specific Character
Find character motions let you move horizontally quickly and with high precision:

- Use `f{character}` (find) to move to the next occurrence of a character in a line.
- Use `F{character}` to find the previous occurrence of a character

For instance, `f(` sends you to the next occurrence of `(`. Try it!

In addition to `f` Vim also offers the `t` (until) command:

- Use `t{character}` to move the cursor just before the next occurrence of a character (think of `t{character}` of moving your cursor until that character).
- Again, you can use `T{character}` to do the same as `t{character}` but backwards

After using `f{character}` you can type `;` to go to the next occurrence of the character or `,` to go to the previous one. You can see the `;` and `,` as commands for repeating the last character search.

## Moving Horizontally Extremely
- `0`: Moves to the first character of a line
- `^`: Moves to the first non-blank character of a line
- `$`: Moves to the end of a line
- `g_`: Moves to the non-blank character at the end of a line


## Moving Vertically

Starting from `k` and `j`, we move on to a faster way of maneuvering vertically with:

- `}` jumps entire paragraphs downwards
- `{` similarly but upwards
- `CTRL-D` lets you move down half a page by scrolling the page
- `CTRL-U` lets you move up half a page also by scrolling

## High Precision Vertical Motions With Search Pattern

To move anywhere within a file when you have a target in mind, the best option is to search using:

- `/{pattern}` to search forward
- `?{pattern}` to search backwards

Remember that in order to execute a search you need to press `ENTER` at the end of the command

- `n` to go to the next match
- `N` to go to the previous match

## Moving Faster With Counts

Counts are numbers which let you multiply the effect of a command:

```
{count}{command}
```

## Moving Semantically

In addition to the previous motions which don’t really take into account the meaning of your code, Vim offers additional bindings that take your code semantics into consideration:

- Use `gd` to **g**o to **d**efinition of whatever is under your cursor.
- Use `gf` to **g**o to a **f**ile in an import.

## And Some More Nifty Core Motions

These are yet more motions that can come in handy from time to time:

- Type `gg` to go to the top of the file.
- Use `{line}gg` to go to a specific line.
- Use `G` to go to the end of the file.
- Type `%` jump to matching `({[]})`.

## Select multiple words, one at a time, then replace them all
https://vi.stackexchange.com/questions/27812/select-multiple-words-one-at-a-time-then-replace-them-all