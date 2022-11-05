# Binomial Distribution

> Last updated: 2022/10/18

## Binomial Distribution 1

### [Source](https://www.youtube.com/watch?v=O12yTz_8EOw&list=PL1328115D3D8A2566&index=9&ab_channel=KhanAcademy)

### learn with first example before get formula of binomial coefficients

Let's say I have a coin, and it's a fair coin, and I'm going to flip it five times. The coin can be `heads` or `tail` which be indicated as `H` or `T` , separately.

$$
X = \text{number of heads after 5 flips}
$$

Question is what is probability that $X$ is equal to following?
$$
P(X = 0) = P(TTTTT) = (\frac{1}{2})^5 = \frac{1}{32} \\
P(X = 1) = P(HTTTT) \dotso P(TTTTH) = \frac{5}{32} \\
P(X = 5) = P(HHHHH) = \frac{1}{32} \\
P(X = 2) = P(HHTTT) \ or \ P(HTHTT) \dotso = \frac{5 *4}{2}* \frac{1}{32} = \frac{5!}{2! *(5-2)!}* \frac{1}{32} \\
P(X=3) = \frac{5!}{3!(5-3)!} *\frac{1}{32} \\
P(X=4) = \frac{5!}{4!(5-4)!}* \frac{1}{32}
$$

conclude:
`n` is all data
`k` is position each of which you having maximum chance of data could put into.

**This caculate result represents all scenarios in not overlap.**
$$
\bold{binomial \space{} coefficients}  = \frac{n*(n-1) \dotso (n-k+1)}{k!}= \frac{n!}{k!(n-k)!} = {n \choose k}
$$

### Binomial Distribution 2

### [Source](https://www.youtube.com/watch?v=FI8xtVaI068&list=PL1328115D3D8A2566&index=10&ab_channel=KhanAcademy)

flip coin 5 times.

$$
P(X=0) = \frac{1}{32} \\
P(X=1) = \frac{5}{32} \\
P(X=2) = \frac{10}{32} \\
P(X=3) = \frac{10}{32} \\
P(X=4) = \frac{5}{32} \\
P(X=5) = \frac{1}{32} \\
$$

then you will get particular instance of **binomial probaility Distribution**.
![flip_5_binomial_distri](./assets/probability/flip_5_binomial_distri.drawio.svg)
