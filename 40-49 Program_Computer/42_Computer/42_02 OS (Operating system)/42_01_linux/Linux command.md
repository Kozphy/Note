# Linux command

## ls
| ls commmand | Description |
| ----------- | ----------- |
|ls -lh|	Combining -l with -h allows you to display the file/directory sizes in “human readable” format.|
|ls -F|	Appends a / to the subdirectories listed in the output|
|ls -R|	Recursively lists the contents of the subdirectories|
|ls -r|	Displays the output in reverse order|
|ls -lS|	Displays the output ordered by file size, with the largest files displayed first|
|ls -ltr|	Combining the -l, -t, and -r options display the output ordered by modification date, with the most recent displayed last|



## cat (concatenate)
> cat, short for “concatenate”, is used to not only view the contents of a file but also for creating files by redirecting the output:
```
$ cat pacific_rose
This is a test file.
```
Here, the pacific_rose file contains the ‘This is a test file.’ text. cat displays the contents of this file directly in the terminal window, which is the quick and easy way to see what’s inside.
```
$ cat > granny_smith
```
The command above creates a new file called granny_smith inside the current working directory.
```
$ cat apple1.txt apple2.txt apple3.txt > three_apples.txt
```
As mentioned, cat is short for “concatenate”, and the example above illustrates how you can combine the contents of multiple files into a single file using the > redirection operator.

Here’s a list of command flags (or options) that might also be handy to use with the cat command:
- cat -n will display the line numbers alongside the file output.
- cat -e will display the line endings and line spaces, usually with the $ character, in the file output.
- cat -T will display the tab separated lines in the file output.