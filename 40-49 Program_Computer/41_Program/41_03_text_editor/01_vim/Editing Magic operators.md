# Editing Magic operators
###### tags: `vim tutorial`

## how to use Operators
**Operators** are commands that let you perform actions to change the content of your editor.

You use **operators** in combination with **counts** and **motions** to define the range of text to which an action applies:

```
   what to do (delete, change...)
      /
     /      how many times
    /         /
   v         v
{operator}{count}{motion}
                    ^
                   /
                  /
           where to perform
             the action
```

For example, take `d2w`. It tells Vim to **d**elete **2** **w**ords. Try it!

## undo and redo
Press `u` to undo and you last change will be reveted. You can continue pressing `u` if serveral things went sideways.

If you want to redo, type `<Ctrl-R>`

