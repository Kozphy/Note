# Probability Density Functions

> Last Updated: 2022/10/09

## [Source](https://www.youtube.com/watch?v=Fvi9A_tEmXQ&list=PL1328115D3D8A2566&index=8&ab_channel=KhanAcademy)

## What is Probability Density function?

we use it to measure continuous Random Variable.

### example of measurement continuous Randowm Variable

Y = exact amount of rain tomorrow
![probo_rain_tomorrow](./assets/proba_rain_tomorrow.drawio.svg)

Question is what exactly 2 inches of rain in tomorrow? we don't have ruler which can say what is exactly about that.

At some point, just the way `we manufacture things`, there's going to be `an extra atom on it here or there`.

So the odds of actually anything being exactly a certain measurement to the exact infinite decimal point is actually 0.
$$
P(Y = 2) = ?
$$

The way `we would think about a continuous random variable`, we could say `what is the probabillity that Y is almost 2`?

So if we said that the absolute value of Y minus 2 is less than some tolerance?
$$
\begin{equation}
P(|Y - 2| < 0.1) \\
=P(1.9 < Y < 2.1) \\
=\int_{1.9}^{2.1}f(x)dx
\end{equation}
$$

And all of this should immediately lead to one light bulb in your head, it's that the probability of all of the events that might occur can't be more than 100%.
$$
\begin{equation}
\int_{0}^{\inf} f(x)dx = 1
\end{equation}
$$
