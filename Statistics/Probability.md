# Probability

> Last updated: 2022/10/13

- [Probability](#probability)
  - [probability independent event](#probability-independent-event)
    - [Source](#source)
  - [Mutually-Exclusive Events](#mutually-exclusive-events)
  - [Compound probability of independent events](#compound-probability-of-independent-events)
    - [Source](#source-1)
  - [Addition rule for probability (overlap)](#addition-rule-for-probability-overlap)
    - [Source](#source-2)
    - [study with example](#study-with-example)
  - [Coin flipping probability](#coin-flipping-probability)
    - [Source](#source-3)
      - [In flipping coin three time condition](#in-flipping-coin-three-time-condition)
  - [Probability without equally likely events (multiply)](#probability-without-equally-likely-events-multiply)
    - [Source](#source-4)
  - [Getting exactly two heads (combinatorics)](#getting-exactly-two-heads-combinatorics)
    - [Source](#source-5)
    - [Fair Coin: Flip 4 times](#fair-coin-flip-4-times)
  - [Exactly three heads in five flips](#exactly-three-heads-in-five-flips)
    - [Source](#source-6)
    - [Fiar Coin: Flip 5 times](#fiar-coin-flip-5-times)
  - [Generalizing with binomial coefficients (bit advanced)](#generalizing-with-binomial-coefficients-bit-advanced)
    - [Source](#source-7)
  - [Probability tree](#probability-tree)
    - [Source](#source-8)
    - [set theory](#set-theory)
  - [Prabability of throwing two dice](#prabability-of-throwing-two-dice)
    - [Source](#source-9)
  - [probability dependent event example](#probability-dependent-event-example)
    - [Source](#source-10)
  - [Dependent probability example 2](#dependent-probability-example-2)
    - [Source](#source-11)
  - [Probability using combinations](#probability-using-combinations)
    - [Source](#source-12)
  - [Probability and combinations 2](#probability-and-combinations-2)
    - [Source](#source-13)
  - [Conditional probability and combinations](#conditional-probability-and-combinations)
    - [Source](#source-14)
      - [Bayes' Theorem](#bayes-theorem)

## probability independent event

### [Source](https://www.youtube.com/watch?v=uzkc-qNVoOk&list=PLC58778F28211FA19&index=1&ab_channel=KhanAcademy)

we don't know whether it's heads or tails, but we can start to `describe the chances of it`.

![flip_coin](./assets/probability/flip_coin.drawio.svg)

$$
P(H) = ? = \frac{\text{number of possibilities that meet by condition}}{\text{number of equally likely possibilities}} = \frac{1}{2}
$$

Another way to think about or conceptualize probaility that will give you this exact same answer is to say, if I was to run the flipping a coin experiment, which is every time you run this random event `many times` and `the more the better`, `you would really approach to get this 50%`.

## Mutually-Exclusive Events

if we are rolling fair dice at once what the probability is 2 and 3.
$$
P(\text{2 and 3}) = \frac{0}{6}
$$

![mutually_exclusive](./assets/probability/mutually_exclusive.drawio.svg)

`this mean both cannot happen at  the same time`.

## Compound probability of independent events

### [Source](https://www.youtube.com/watch?v=xSc4oLA9e8o&list=PLSQl0a2vh4HB3WvDaHYcqbfgw7cBNx8DO&index=28&ab_channel=KhanAcademy)

if we are flipping fair coin at once. the probability of heads and tail separately is

$$
P(H) = \frac{1}{2}
$$

$$
P(T) = \frac{1}{2}
$$

Now Let's figure out the probability of taking this coin then flip it twice.

we will get result as $P(HH), P(HT), P(TH), P(TT)$ each of which probability caculation process is the same as following, essentially.

$$
P(HH) = P(H_1) *P(H_2) = \frac{1}{2*2} = \frac{1}{4}
$$

> Note that Each flipping is **independent event**.
> What happes in the first flip in no way to affect what happens in the second flip which be known as gambler's fallacy.

## Addition rule for probability (overlap)

### [Source](https://www.youtube.com/watch?v=QE2uR6Z-NcU&list=PLC58778F28211FA19&index=3&ab_channel=KhanAcademy)

### study with example

![addtion_rule_example](./assets/probability/addition_rule.drawio.svg)

What is probability of getting something that is yellow or a cube, a cube of any color?

$$
P(\text{yellow or cube}) = \frac{P(yellow) + P(cube) - P(\text{yellow and cube})}{all}= \frac{12+13-5}{30}
$$

$$
P(\text{A or B}) = P(A) + P(B) - P(\text{A and B})
$$

## Coin flipping probability

### [Source](https://www.youtube.com/watch?v=mkyZ45KQYi4&list=PLSQl0a2vh4HB3WvDaHYcqbfgw7cBNx8DO&index=24&ab_channel=KhanAcademy)

#### In flipping coin three time condition

All probability
$$
P(\text{not all tail})\ or \ P(\text{all tails}) = 1
$$

how many possibilites have at least 1 head?

$$
P(\text{at least 1 head}) = P(\text{Not getting all tails}) = 1 - P(TTT) = \frac{7}{8}
$$

## Probability without equally likely events (multiply)

### [Source](https://www.youtube.com/watch?v=RI874OSJp1U&list=PLC58778F28211FA19&index=7&ab_channel=KhanAcademy)

If we get a unfair coin, which have 60% chance to get head.
In this situation, in order to visualize the probaility, we have to kind of taking what's called a `frequentist approach` ,which is known as `frequency probability`. You have 100% chance of getting a heads or a tails, and these are **mutually exclusive event**.

$$
P(H)=60\% \\
P(T)=40\%
$$

what the probability of getting heads on our first flip and on our second flip, these are **independent events**, no matter how I get on first flip, I have equal chance of getting heads on second flip.
$$
P(H_1H_2) = P(H_1) * P(H_2) = 0.36
$$

Another example, flipping coin three time what the probability of $P(THT)$
$$
P(T_1H_2T_3) = P(T_1)P(H_2)P(T_3) = 0.096
$$

## Getting exactly two heads (combinatorics)

### [Source](https://www.youtube.com/watch?v=8TIben0bJpU&list=PLC58778F28211FA19&index=8&ab_channel=KhanAcademy)

### Fair Coin: Flip 4 times

what the probability of getting `exaclty 1 heads`?
we can **add** them together because they are **mutually exclusive**, which meaning **each event will not occur at same time**.

$$
P(\text{exactly 1 heads}) = P(HTTT) + P(THTT) + P(TTHT) + P(TTTH) = \frac{4}{16}
$$

what the probability of getting `exaclty 2 heads`? we don't want to count $P(H_1H_2TT)$ and $P(H_2H_1TT)$ for our purposes, these are exact same outcomes.

Thinking of following, we have four flip position, having 4 place to show up head in first flip, having 3 place to show up head in second flip, `multiplying all the differenct ways` that you could `get all of the different scenarios`, but there `have overlap` on all scenarios, so we `divide it by all the different ways that you can swap two different things`.

![flip_position](./assets/probability/flip_position.drawio.svg)

$$
P(\text{exactly 2 heads}) = \frac{4*3}{2} * \frac{1}{16} = \frac{6}{16}
$$

## Exactly three heads in five flips

### [Source](https://www.youtube.com/watch?v=udG9KhNMKJw&list=PLC58778F28211FA19&index=9&ab_channel=KhanAcademy)

### Fiar Coin: Flip 5 times

what the probability of getting `exaclty 3 heads`

$$
P(\text{exactly 3 heads}) = \frac{5*4*3}{3*2} * \frac{1}{32} = \frac{10}{32}
$$

## Generalizing with binomial coefficients (bit advanced)

### [Source](https://www.youtube.com/watch?v=AOsWph2FNLw&list=PLC58778F28211FA19&index=11&ab_channel=KhanAcademy)

Figure out the probability of getting exactly k heads in n flips of the fair coin.

$$
P(\text{k heads in n flips of the fair coin})
$$

- it's `n flips` of buckets, equalling all posibility is $(\frac{1}{2})^n$
- having $n * (n-1) \dotso (n-(k-1))$ ways to get all different scenarios, but there have overlap, so we divide by $k!$
- abstract: you have `n` bucket and you want to choose `k` of them to be heads, don't wanting to overlap.
$$
\begin{equation}
\begin{split}
\text{all scenarious in no overlap} =  \frac{n*(n-1) \dotso (n-(k-1))}{k!} = \frac{n!}{k!(n-k)} \\
= _nC_k ={n \choose k}
\end{split}
\end{equation}
$$

$$
\tag{1.*}
\begin{equation}
n * (n-1) \dotso (n-(k-1)) = \frac{n!}{(n-k)!} = \frac{n * (n-1) \dotso 1}{(n-k) * (n-k-1) \dotso 1}
\end{equation}
$$
> Note:
> $n-(k-1) = n-k+1$ is the interger that's one larger than $(n-k)$.
> $\frac{n!}{k!(n-k)}$ is actually a generalized formula for binomial coefficients.

## Probability tree

### [Source](https://www.youtube.com/watch?v=6E_NVnboMB8&list=PLC58778F28211FA19&index=12&ab_channel=KhanAcademy)

![probability tree](./assets/probability/probability_tree.drawio.svg)

### set theory

$$
P(\text{1 head, 1 tail}) = P(TH) + P(HT) = P(TH \bigcup HT) = \frac{2}{4}
$$

## Prabability of throwing two dice

### [Source](https://www.youtube.com/watch?v=2XToWi9j0Tk&list=PLC58778F28211FA19&index=15&ab_channel=KhanAcademy)

![throw two time dice](./assets/probability/throw_two_dice.drawio.svg)
what the probability of getting 7 when I add up two rolls of dice?
$$
P(7) = \frac{6}{36}
$$

or
getting 5 or 9.
$$
P(5 \bigcup 9) = P(5) + P(9) = \frac{4}{36} + \frac{4}{36} = \frac{2}{9}
$$

## probability dependent event example

### [Source](https://www.youtube.com/watch?v=xPUm5SUVzTE&list=PLC58778F28211FA19&index=17&ab_channel=KhanAcademy)

You have 8 coins in a bag. 3 of them are unfair in that they have a 60% chance of coming up heads when flipped (the rest are fair coins). you randomly choose on coin from the bag and flip it 2 times. What is the percent probability of getting 2 heads?

- $\frac{5}{8}$ chance we get Fair coin in a beg
  - what the probability we get twice of head if coin is fair?

$$
P(HH|Fair) = 0.5 * 0.5 = 0.25
$$

  - probability of that we get fair coin in a bag then getting heads through flipping it twice.

$$
P(\text{Fair and HH}) = P(\text{Fair}) *P(HH|\text{Fair}) = \frac{5}{8}* 0.25 = 0.15625
$$
  
- $\frac{3}{8}$ chance we get Unfair coin in a beg
  - what the probability we get twice of head if coin is unfair?

$$
P(HH|UnFair) = 0.6*0.6 = 0.36
$$

  - probability of that we get unfair coin in a beg then getting heads through flipping it twice.

$$
P(\text{UnFair and HH}) = P(UnFair) *P(HH|UnFair) = \frac{3}{8}* 0.36 = 0.135
$$

answer:

$$
0.15625 + 0.135 = 0.29125
$$

## Dependent probability example 2

### [Source](https://www.youtube.com/watch?v=7BkcNLOf56w&list=PLC58778F28211FA19&index=18&ab_channel=KhanAcademy)

You have 4 coins in a bag. 3 of them are unfair in that they have 45% chance of coming up tails when flipped (the rest are fair coin). You randomly choose one coin from the bag and flip it 4 times. What is the percent probability of getting 4 heads?

- unfair: 45% tails | 55% heads, $\frac{3}{4}$ chance get unfair coin
$$
  0.55*0.55*0.55*0.55 = \frac{3}{4}* (0.55)^4 = 0.0686297
$$

- fair: 50 tails | 50% heads
$$
  0.5*0.5*0.5*0.5 = \frac{1}{4}* (0.5)^4 = 0.015625
$$
answer: 0.08425

## Probability using combinations

### [Source](https://www.youtube.com/watch?v=Xqfcy1rqMbI&list=PLC58778F28211FA19&index=23&ab_channel=KhanAcademy)

we want to flip the coin 8 times and I want to figure out the probability of getting exactly 3 out of 8 heads.

$$
P(\frac{3}{8}H) = \frac{3H}{\text{total outcome}} = {8 \choose 3} = \frac{1}{2^n} * \frac{n!}{k!(n-k)!} =  \frac{8!}{3!(8-3)!} * (\frac{1}{2^8}) = 0.21875
$$

> Note:
> $\frac{n!}{(n-k)}$, it is just essentially just saying, how many ways can I pick 3 things out of 8, which is essentially the number of permutations and $k!$ is be used for elimination overlap.

## Probability and combinations 2

### [Source](https://www.youtube.com/watch?v=Xqfcy1rqMbI&list=PLC58778F28211FA19&index=23&ab_channel=KhanAcademy)

I'm shooting free throws, having free throw percentage of 80%. But 20% of time I will miss it.

if 5 free throws, what is the probability that I make 3 of the 5 free throws?
$$
  P(\frac{3}{5}) = {5 \choose 3} = (0.8)^3*(0.2)^2* \frac{5!}{3!(5-3)!} = 20.48\%
$$

if 5 free throws, what is the probability that I make at least 3 of the 5 free throws?
$$
  P(\frac{3}{5} + \frac{4}{5} + \frac{5}{5}) = 94.21\%
$$

## Conditional probability and combinations

### [Source](https://www.youtube.com/watch?v=xw6utjoyMi4&list=PLC58778F28211FA19&index=25&ab_channel=KhanAcademy)

if we have bag that have 5 fair coin and 10 unfiar coin, fair coin is  50:50 chance of getting heads or tails, and the unfair coin has 80% chance of getting heads for any one of those coins, 20% chance of getting tails.

Question is what happends is I put my hand in bag, picking out one coin, flipping it six times , getting four heads out of six times. $P(Fair | \frac{4}{6}heads)$

#### Bayes' Theorem

It tells us the probability of both a and b happening $A \bigcap B$, which is essentially saying, **it's a set of events in which both a and b occur**. That's equal to the probability of a occurring given b times the probability of b which is $P(A | B) *P(B) = P(B|A)* P(A)$
