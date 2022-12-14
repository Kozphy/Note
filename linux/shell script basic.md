# shell script basic
###### tags: `shell script`

## first line must add #! /bin/bash
```shell=
#! /bin/bash
```

## echo command
```shell=
echo Hello!
```

## variables
- Uppercase by convention
- Letters, numbers, underscores
```shell=
NAME="Brad"
echo "My name is $NAME"
echo "My name is ${NAME}"
```

## User input
```shell=
read -p "Enter your name: " NAME
echo "Hello $NAME, nice to meet you!"
```

## simple if else statement
```shell=
#! /bin/bash

NAME='bob'

if [ "$NAME" == "Brad" ]
then
    echo "Your name is Brad"
elif [ "$NAME" == "Jack" ]
then
    echo "Your name is Jack"
else
    echo "Your name is Not Brad or Jack"
fi
```

## comparison
```shell=
NUM1=3
NUM2=5
if [ "$NUM1" -gt "$NUM2" ]
then
    echo "$NUM1 is greater than $NUM2"
else
    echo "$NUM1 is less than $NUM2"
fi


#######
# val1 -eq val2 Returns true if the values are equal
# val1 -ne val2 Returns true if the values are not equal
# val1 -gt val2 Returns true if val1 is greater than val2
# val1 -ge val2 Returns true if val1 is greater than or equal to val2
# val1 -lt val2 Returns true if val1 is less than val2
# val1 -le val2 Returns true if val1 is less than or rqual to val2
#######
```

## File Conditions
```shell=
FILE="test.txt"

if [ -f "$FILE" ]
then
    echo "$FILE is a file"
else
    echo "$FILE is NOT a file"
fi

#######
# -d file True if the file is a directory
# -e file True if the file exists (note that this is not particularly portable, thus -f is generally used)
# -f file True if the provided string is a file
# -g file True if the group id is set on a file
# -r file True if the file is readable
# -s file True is the file has a non-zero size
# -u True if the user id is set on a file
# -w True if the file is writable
# -x True if the file is an executable
#######
```

# Case statement
```shell=
read -p "Are you 21 or over? Y/N " ANSWER
case "$ANSWER" in 
    [yY] | [yY][eE][sS])
     echo "You can have a beer :)"
     ;;
    [nN] | [nN][oO])
     echo "Sorry, no drinking"
     ;;
    *)
     echo "Please enter y/yes or n/no"
     ;;
esac
```

# for loop
```shell=
NAMES="Brad Kevin Alice Mark"

for NAME in $NAMES
 do
   echo "Hello $NAME"
done
```

# for loop to rename files
```shell=
FILES=$(ls *.txt)
NEW="new"
for FILE in $FILES
    do
        echo "Renaming $FILE to new-$FILE"
        mv $FILE $NEW-$FILE
done
```

# while loop - read through a file line by line
```shell=
LINE=1
while read -r CURRENT_LINE
    do
        echo "$LINE: $CURRENT_LINE"
        ((LINE++))
done < "./new-1.txt"
```

# function
```shell=
function sayHello() {
    echo "Hello"
}

sayHello
```
# function with params
```shell=
function greet() {
    echo "Hello, I am $1 and I am $2"
}

greet "Brad" "26"
```

# create folder and write to a file
```shell=
#! /bin/bash
mkdir hello
touch "hello/world.txt"
echo "Hello" >> "hello/world.txt"
echo "Created hello/world.txt"
```

