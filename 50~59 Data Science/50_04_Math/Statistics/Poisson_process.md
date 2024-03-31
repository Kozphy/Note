# Poisson distribution

> last updated: 2022/11/16

## Possion process 1

### Source

[khan Academy](https://www.youtube.com/watch?v=3z-M6sbGIZ0&list=PL1328115D3D8A2566&index=15&ab_channel=KhanAcademy)

[term_of_indeterminate](https://byjus.com/maths/indeterminate-forms/#:~:text=The%20term%20“indeterminate”%20means%20an,the%20substitution%20of%20the%20limits.)

[Scribber_Possion_distribution](https://www.scribbr.com/statistics/poisson-distribution/)

### intro possion

we assume
$$
X = \text{number of cars pass in an hour}
$$

Let's say you estimate **best estimation of this random variable $\lambda$ in binomial distribution**.

$$
E(X) = \lambda = np
$$

Maybe we could say $\lambda\frac{cars}{hours}$ = $60\frac{min}{hour} * \frac{\lambda}{60}\frac{cars}{mins}$

$$
P(X=k) = {60 \choose k} * (\frac{\lambda}{60})^k * (1-\frac{\lambda}{60})^{60-k}
$$

we change above func into second, and this is `Poisson distribution`

$$
P(X=k) = {3600 \choose {k}} *({\frac{\lambda}{3600}})^k* (1-\frac{\lambda}{3600})^{3600-k}
$$

### Some mathematical tool for derivation Possion distribution

#### first tool

$$
\lim_{x \to \inf} (1+ \frac{a}{x}) ^ x = e^a
$$

##### prove above function

we assume
$$
\frac{1}{n} = \frac{a}{x} \\
x = na \\
$$

then

$$
\lim_{n \to \inf}(1+\frac{1}{n})^{na} = \lim_{n \to \inf}((1+\frac{1}{n})^n)^a = e^a
$$

#### second tool

$$
\frac{x!}{(x-k)!} = x * (x-1) * (x-2) \dotso (x-k+1)
$$

## Poisson process 2

## Source

[Khan](https://www.youtube.com/watch?v=Jkr4FSrNEVY&list=PL1328115D3D8A2566&index=16&ab_channel=KhanAcademy)

$$
E(X) = \lambda = np \\
p = \frac{\lambda}{n}
$$

if we describes this as binomial distribution with the limit as it approach to infinity.

$$
P(X = K) = \lim_{n \to \inf} {n \choose k} * (\frac{\lambda}{n})^k * (1 - \frac{\lambda}{n})^{n-k}
$$

we can rearrange above function
$$
\lim_{n \to \inf} \frac{n!}{(n-k)!k!} * \frac{\lambda^k}{n^k} * (1-\frac{\lambda}{n})^n *(1 - \frac{\lambda}{n})^{-k}
$$

$$
\lim_{n \to \inf} \frac{n * (n-1) * (n-2) \dotso (n-k+1)}{n^k} * \frac{\lambda^k}{k!} * (1-\frac{\lambda}{n})^n * (1- \frac{\lambda}{n})^{-k}
$$

$$
\lim_{n \to a}  f(x)g(x) = \lim_{n \to a}f(x) \lim_{x \to a}g(x)
$$

$$
\lim_{n \to \inf} \frac{n^k + \dotso + k}{n^k}
$$
