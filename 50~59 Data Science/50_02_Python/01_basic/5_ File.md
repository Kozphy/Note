# 5: File
###### tags: `python learn`

## Persistence
In this chapter, we start to work with Secondary Memory (or files). Secondary memory
is not erased when the power is turned off. Or in the case of a USB flash drive, the data
we write from our programs can be removed from the system and transported to another
system.

We will primarily focus on reading and writing text files such as those we create in a text
editor. Later we will see how to work with database files which are binary files, specifically
designed to be read and written through database software.

## Opening files
When we want to read or write a file (say on your hard drive), we first must open the file. 

Opening the file communicates with your operating system, which knows where the data for each file is stored.

When you open a file, you are asking the operating system to find the file by name and make sure the file exists.

```python=
>>> fhand = open('mbox.txt')
>>> print(fhand)
<_io.TextIOWrapper name='mbox.txt' mode='r' encoding='UTF-8'>
```

If the **open** is successful, the operating system returns us a file handle. The file handle is not the actual data contained in the file, but instead it is a "handle" that we can use to read the data. You are given a handle if the requested file exists and you have the proper permissions to read the file.

If the file does not exist, **open** will fail with a traceback and you will not get a handle to access the contents of the file:
```python=
>>> fhand = open('stuff.txt')
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
FileNotFoundError: [Errno 2] No such file or directory: 'stuff.txt'
```

## Text files and lines
A text file can be thought of as a sequence of lines, much like a Python string can be thought of as a sequence of characters.

To break the file into lines, there is a special character that represents the "end of the line" called the newline character.

In Python, we represent the newline character as a backslash-n in string constants. Even though this looks like two characters, it is actually a single character. When we look at the variable by entering "stuff" in the interpreter, it shows us the **\n** in the string, but when we use **print** to show the string, we see the string broken into two lines by the newline character.

```python=
>>> stuff = 'Hello\nWorld!'
>>> stuff
'Hello\nWorld!'
>>> stuff = 'X\nY'
>>> print(stuff)
X
Y
>>> len(stuff)
```

## Reading files
While the file handle does not contain the data for the file, it is quite easy to construct a for loop to read through and count each of the lines in a file:
```python=
fhand = open('mbox-short.txt')
count = 0
for line in fhand:
    count = count + 1
print('Line Count', count)
```

The **open** function does not read the entire file is that the file might be quite large with many gigabytes of data. The **open** statement takes the same amount of time regardless of the size of the file. The **for** loop actually causes the data to be read from the file.

When the file is read using a **for** loop in this manner, Python takes care of splitting the data in the file into separate lines using the newline character. Python reads each line through the newline and includes the newline as the last character in the line variable for each iteration of the **for** loop.

Because the **for** loop reads the data one line at a time, it can efficiently read and count the lines in very large files without running out of main memory to store the data. The above program can count the lines in any size file using very little memory since each line is read, counted, and then discarded.

If you know the file is relatively small compared to the size of your main memory, you can read the whole file into one string using the **read** method on the file handle.

```python=
>>> fhand = open('mbox.txt')
>>> inp = fhand.read()
print(len(inp))
print(inp[:20])
```

When the file is read in this manner, all the characters including all of the lines and newline characters are one big string in the variable **inp**. Remember that this form of the **open** function should only be used if the file data will fit comfortably in the main memory of your computer.

If the file is too large to fit in main memory, you should write your program to read the file in chunks using a **for** or **while** loop.

## Searching through a file
When you are searching through data in a file, it is a very common pattern to read through a file, ignoring most of the lines and only processing lines which meet a particular condition.

```python=
fhand = open('mbox.txt')
for line in fhand:
    if line.startswith('From:'):
        print(line)
```
```python=
fhand = open('mbox.txt')
for line in fhand:
    line = line.rstrip()
    if line.startswith('From:'):
        print(line)
```
```python=
fhand = open('mbox.txt')
for line in fhand:
    line = line.rstrip()
    if line.find('@uct.ac.za') == -1: 
        continue
    print(line)
```

## Letting the user choose the file name
```python=
fname = input('Enter the file name: ')
fhand = open(fname)
count = 0
for line in fhand:
    if line.startwith('Subject:'):
        count = count + 1
print('There were', count, 'subject lines in', fname)
```

## Using try, except, and open
```python=
fname = input('Enter the file name: ')
try:
    fhand = open(fname)
except:
    print(fname + " doesn't exist.")
    exit()
count = 0
for line in fhand:
    if line.startswith('Subject:'):
        count += 1
    print('There were', count, 'subject line in', fname)
```

The **exit** function terminates the program. It is a function that we call that never returns. Now when our user (or QA team) types in silliness or bad file names, we "catch" them and recover gracefully.

## Writing files
To write a file, you have to open it with mode "w" as a second parameter:
```python=
fout = open('ouput.txt', 'w')
print(fout)
<_io.TextIOWrapper name='mbox-short.txt' mode='w' encoding='UTF-8'>
```

If the file already exists, opening it in write mode clears out the old data and starts fresh, so be careful! If the file doesn't exist, a new one is created.

The **write** method of the file handle object puts data into the file, returning the number of characters written. The default write mode is text for writing (and reading) strings.
```python=
line1 = "This here's the wattle,\n"
fout.write(line1)
line 2 = 'the emblem of our land.\n'
fout.write(line2)
fout.close()
```
We could close the files which we open for read as well, but we can be a little sloppy if we are only opening a few files since Python makes sure that all open files are closed when the program ends. When we are writing files, we want to explicitly close the files so as to leave nothing to chance.

## Debugging
When you are reading and writing files, you might run into problems with whitespace. These errors can be hard to debug because spaces, tabs, and newlines are normally invisible:
```python=
s = '1 2\t 3\n 4'
print(s)
1 2  3
4
```

The built-in function `repr` can help. It takes any object as an argument and returns a string representation of the object.
```python=
print(repr(s))
'1 2\t 3\n 4'
```

