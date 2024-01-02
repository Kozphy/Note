# create file

## Create A file Using CMD (Empty, Text, Batch)
### Text file
We will need to use the **Echo** command along with a **redirector**.

- **Echo** is primarily used to **print** variables or strings to the command line, similar to "print" or "Console.WriteLine" in other programming languages.
- **Redirectors** are special symbols that can be used complete many functions such as **combine** two commands or **redirect** the output of one command into input for another.

We can use the echo command to print a **string** and redirect its output into a **new file** by using a redirector, specifically the greater than redirector (>).

To do so all we have to do is type the **echo** command followed by the **text** we want our new file to have, the greater than **redirector**, and the **name** of your new file within quotes along with the .txt **extension**.
```cmd
Echo Hello World > "File.txt"
```

To **view** the contents of a file we just created directly from the command line we can use the "**Type**" command. Simply enter type followed by the name of the file we just created.
```cmd
Type "File.txt"
```

Apart from creating a new file we can **add** or **append** text to an existing text file. To do so we need to use the greater than symbol **twice**. Here is what that would look like:
```cmd
Echo Goodbye World >> "File.txt"
```

Our file will now contain the following text:
```text
Hello World
Goodbye World
```

### Empty Text files
In many cases you might want to create a completely **empty** text file. The syntax for this command is very similar to our previous command however this time we need to add a **dot** directly after the echo command.
```text
Echo. > "File.txt"
```

An empty file will immediately appear in your **current** directory.

The dot tells the echo command to **not** output anything.

### Batch files
While creating text files is nice, in may case you will want to create **batch** files. Doing so is very simple, all we have to do is replace **extension** of the name of our file from **.txt** to **.bat**.

```txt
Echo. > "Script.bat"
```

## Create files with Current Date - Using CMD:
You can embed the current **date** right into the name of the file you are creating by taking advantage of the **%Date%** automatic variable. Here is what our command would like:
```cmd
echo. > "%DATE:/=-%.txt"
```

This command will create a text file with the current date as its name in our **current** directory.

By default, the date in the **%Date%** variable is stored in this format:
```txt
Mon 12/14/2020
```

However, to use this as the name of a file we need to replace the backward **slashes** with any other symbol, so that the command line doesn't **misinterpret** our date as a directory.

That is exactly what **/=-**  does, you can replace the **dash** with any symbol of your choice.

## Creating file with Specific Size - Using CMD:
To do so we need to use the FSutil command instead of echo.

FSutil stands for **file system utility** and as the name suggests it can be used to perform various operations on our file system.

To do so all you have to do is use the following **syntax**:
```
FSutil File CreateNew "Dummy file" 10485760
```
- The **File** parameter instructs the FSutil command to create a file.
- **CreateNew** instruct it to create a new item.
- finally, the **size** we want out file to have in **bytes**.

In case you want to conver **gigabytes** to **bytes**, [use this online converter](https://convertlive.com/u/convert/gigabytes/to/bytes)

## Create files from different directories - from CMD
In case you want to create you new file in a directory **other** than your current one, you need to enter your **target** directory just before the name of your new file.

So here is what our echo command would look like:
```txt
Echo. > "C:\Users\<Username>\Documents\File.txt"
```

This command will create an empty file in our **documents** directory.

And here is what our FSutil command would look like:
```
FSutil File CreateNew "C:\Users\<Username>\Documents\File.txt" 10485760
```

## Create Multiple files At once - Using CMD:
### Nubmered Files (File1, File2, File3)
```cdm
FOR \L %A IN (1 1 10) DO (echo. > "File %A.txt")
```

This command will create **ten** empty files in our **current** dicrectory with the following names: File 1.txt, File 2.txt, File 3.txt, and so on...

This command might also look a little complicated, so let's break it down:
- The /L parameter instructs the for command to iterate through the numbers in our parentheses, instead of using them directly as the names of our files.
- Our **A** parameter specifies a single letter replaceable parameter. You can replace A with any letter of your choice. This is similar to a **variable**, in the sense that its value changes.
- After that we have our condition, the first number specifies the **starting** number, the second number is the **step**, and the third number is the **ending** number.
- And finally, in parenthesis we have the **command** that will be executed every time the loop is executed.

To create your file in a **different** directory, add the path of your choice, just before, the name of your new files.
```cmd=
FOR /L %A IN (1 1 10) DO (echo. > “C:\Users\\Desktop\File %A.txt”)
```
### Named files (First, second, third):
```cmd
FOR %A IN ("First", "Second", "Third") DO (echo. > %A.txt)
```

The above command will create **three** files in your **current** directory with the following names.

