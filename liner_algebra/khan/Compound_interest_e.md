# Compound interest and e

## Introduction to compound interest and e

### [Source](https://www.youtube.com/watch?v=qEB6y4DklNY&ab_channel=KhanAcademy)

we have principal 1 dollor

We get `100% interest every year`, after 1 year we have:
$$
1 \text{(principal)} + 1 \text{(interest)} = 2
$$

We get `50% interest every 6 months`, after 1 year we have:
$$
(1 + (1 *0.5)) = 1.5 \\
(1.5 + (1.5*0.5)) = 2.25 \ (\text{we have 125\% annual rate})
$$

We get `8.5% interest every months`, after 1 year we have:
$$
(1.085)^{12} = 2.66
$$

## Compound interest and e (part 2)

### [Source](https://www.youtube.com/watch?v=dzMvqJMLy9c&t=20s&ab_channel=KhanAcademy)

Compound interest `0.274%` per day, after year I will get:

$$
(1.00274)^{365} = 2.7148
$$

Hourly compounding `0.0114%` = $100/(24*365)$, after year I will get:

$$
(1.000114)^{8760} = 2.714433
$$

### Formalizing the concpet

`P`: is principal
`n`: is the number of time you wanted to compound in the year.

$$
P(1 + \frac{100\%}{n})^n
$$

#### example

We have 1 principal, having `annual counpound rate 100%` divide by different time, how much Amount due we have after 1 year.

get inrestest in `per year`

$$
1(1+\frac{1.00}{1})^1 = 2.00
$$

get interest `per mounth`

$$
1(1+\frac{1.00}{12})^{12} = 2.613
$$

get interest `per day`

$$
1(1+\frac{1}{365})^{365} = 2.7144
$$

then we can formalize this to:
$$
\lim_{n \to \inf}{(1 + \frac{1}{n})}^{n} = e = 2.71....
$$
