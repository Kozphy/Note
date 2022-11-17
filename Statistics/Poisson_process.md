# Poisson distribution

> last updated: 2022/11/16

## Possion process 1

### Source

[khan Academy](https://www.youtube.com/watch?v=3z-M6sbGIZ0&list=PL1328115D3D8A2566&index=15&ab_channel=KhanAcademy)

[term_of_indeterminate](https://byjus.com/maths/indeterminate-forms/#:~:text=The%20term%20“indeterminate”%20means%20an,the%20substitution%20of%20the%20limits.)

[Scribber_Possion_distribution](https://www.scribbr.com/statistics/poisson-distribution/)

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

we change above func into second, and this is Poisson distribution

$$
P(X=k) = {3600 \choose {k}} *({\frac{\lambda}{3600}})^k* (1-\frac{\lambda}{3600})^{3600-k}
$$

$$
\lim_{x \to \inf} (1+ \frac{a}{x}) ^ x = e^a
$$
