# Hello recursion!
###### tags: `Learn You a Haskell for Great Good!`

Recursion is actually a way of defining functions in which the function is applied inside its own definition. Definitions in mathematics are often given recursively.

For instance, the fibonacci sequence is defined recursively. First, we define the first two fibonacci numbers non-recursively. We say that F(0) = 0 and F(1) = 1, meaning that the 0th and 1st fibonacci numbers are 0 and 1, respectively. Then we say that for any other natural number, that fibonacci number is the sum of the previous two fibonacci numbers. So F(n) = F(n-1) + F(n-2). That way, F(3) is F(2) + F(1), which is (F(1) + F(0)) + F(1). Because we've now come down to only non-recursively defined fibonacci numbers, we can safely say that F(3) is 2. 

Having an element or two in a recursion definition defined non-recursively (like F(0) and F(1) here) is also called the **edge condition** and is important if you want your recursive function to terminate. If we hadn't defined F(0) and F(1) non recursively, you'd never get a solution any number because you'd reach 0 and then you'd go into negative numbers. All of a sudden, you'd be saying that F(-2000) is F(-2001) + F(-2002) and there still wouldn't be an end in sight!