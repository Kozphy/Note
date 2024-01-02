# CS Tools
###### tags: `base shall`

## base command
- `date`
- `echo`: print out the arguments that you give it
- `echo $PATH`: show all of the paths on my machine that the shell will search for program.
- `pwd`: print out current path
- `cd:` change directory
- `ls`
- `cd ~`: go to home directory
- `cd -`: go back previous directory
- `mv <filename> <where/newfilename>`: move file to different directory, or change file name in current directory
- `cp <filename> <where/newfilename>`: cp copy file to different directory, in addition can change file name
- `rm`: not recursive remove
- `rm -r`: recursive remove
- `rmdir`: only can remove empty directory
- `mkdir`
- `man`: manual pages
- `<`: rewire the input for this program to be the contents of file
- `>` : rewire the output of the preceding program into this file
- `cat`: show content of file
- `>>`: append
- `|`: take the output of the program to the left and make it the input of the program to the right
- `tail -n<number>`: print last n line of its input
- `sys`:this file system are not actually files on your computer instead these are various kernel parameters so the kernel is like basically the core of your computer this is a way for you to access various kernel parameters through what look like a file system
- `sudo` : do the following thing as the super user
- `sudo su`: this is saying run the following command is root and su that effectively gets you a shell as the super user 
- `tee`: takes its input and writes it to a file but also to standard out
- `xdg-open <filename>`: it will open file in the appropriate program
- `pushd <where>`: go somewhere directory and record the previous place, it can use popd to return the previous place
- `popd`: go to the previous place
- `locate <filename>`: show where all the file which match the `<filename>`.
- `file <filename>`: show the file attribute.
- `history`: show all the command which you have used.

## shell Tools and Scripting
To assign variables in bash, use the syntax foo=bar and access the value of the variable with $foo. 

Strings in bash can be defined with ' and " delimiters, but they are not equivalent. Strings delimited with ' are literal strings and will not substitute variable values whereas " delimited strings will.
```shell=
foo=bar
echo "$foo"
# prints bar
echo '$foo'
# prints $foo
```
> Note that foo = bar will not work since it is interpreted as calling the foo program with arguments = and bar. In general, in shell scripts the space character will perform argument splitting.

As with most programming languages, bash supports control flow techniques including if, case, while and for. Similarly, bash has functions that take arguments and can operate with them. Here is an example of a function that creates a directory and cds into it.
```shell=
mcd () {
    mkdir -p "$1"
    cd "$1"
}
```

Here `$1` is the first argument to the script/function. Unlike other scripting languages, bash uses a variety of special variables to refer to arguments, error codes, and other relevant variables. Below is a list of some of them. A more comprehensive list can be found here.

- $0 - Name of the script
- $1 to $9 - Arguments to the script. $1 is the first argument and so on.
- $@ - All the arguments
- $# - Number of arguments
- $? - Return code of the previous command
- $$ - Process identification number (PID) for the current script
- !! - Entire last command, including arguments. A common pattern is to