# Introduction to Random Variables

> Last update: 2022/10/09

## [Source](https://www.youtube.com/watch?v=IYdiKeQ9xEI&list=PL1328115D3D8A2566&index=8&ab_channel=KhanAcademy)

## Random Variable

A Random Variable can take on multiple values, but it's not really ever solve for, it `quantify random process in real world to number`.

In other words, it isn't a variable in the traditional sense of world. It's more of a function that `maps us from the world of random process to a number` and then this number is going to be random.

we get used to start with the notation of Random Variable `capital letter`.

$$
X = \begin{cases}
1 & \text{rain tomorrow}\\
0 & \text{no rain}
\end{cases}
$$

### example for: Rolling pair dice with random variable

$$
X = \begin{cases}
1 & \text{if heads}\\
0 & \text{if tail}
\end{cases}
$$

### There are two type of Random Variable

1. discrete random variables
    - the same as above definition conclude that In all of these situations you could almost say you could have `accountable number of outcomes`.
2. continuous random varaibles
    - `it could take on an infinite outcome`. ex: X = Exact amount inches of rain in tomorrow. `why it be known as continuous?` well, if you think about it that could take on any of an infinite set of values. you might have 1 inch or 1.1 inches or 1.111 inches or 2.1111 inches of rain tomorrow. As you could see, `you can come up with an infinite number of combinations of a amount of rain you have`.

## Probability distribution

### uniform distribution

#### dice probability

X = number facing up on a fair dice.

![dice_probability](./dice_probability.drawio.svg)

#### dice Random Variable

$$
X = \begin{cases}
    1 & \text{if head}\\
    0 & \text{if tail}
\end{cases}
$$
![dice_random_var_probability](./dice_random_var_probability.drawio.svg)

### if dice is not uniform distribution

![not unitform distribution](./not_uniform_distribution.drawio.svg)

In this situation, the X is 6 or greater than and equal to 5, the probability is:
$$
\begin{align}
    P(X=6) = \frac{2}{6} \\
    P({X\geq}5) = \frac{3}{6}
\end{align}
$$
