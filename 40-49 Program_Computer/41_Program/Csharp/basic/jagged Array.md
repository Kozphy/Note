
# What is jagged Array
Jagged array is a **array of arrays** such that member arrays can be of `different sizes`.
![[Pasted image 20231027123846.png]]
![[Pasted image 20231027123917.png]]

# how to create jagged array in C#?
```c#
int[][] jaggedArray = new int[3][];
jaggedArray[0] = new int[] { 1, 2 };
jaggedArray[1] = new int[] { 3, 4, 5 };
jaggedArray[2] = new int[] { 6 };
```

