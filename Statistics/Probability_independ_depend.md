# Probability explained Independent and dependent events

- [Probability explained Independent and dependent events](#probability-explained-independent-and-dependent-events)
  - [probability independent event](#probability-independent-event)
    - [Source](#source)
  - [Mutually-Exclusive Events](#mutually-exclusive-events)
  - [probability dependent event example](#probability-dependent-event-example)
    - [Source](#source-1)
  - [Compound probability of independent events](#compound-probability-of-independent-events)
    - [Source](#source-2)
  - [Addition rule for probability (overlap)](#addition-rule-for-probability-overlap)
    - [Source](#source-3)
    - [study with example](#study-with-example)
  - [Coin flipping probability](#coin-flipping-probability)
    - [Source](#source-4)
      - [In flipping coin three time condition](#in-flipping-coin-three-time-condition)
  - [Probability without equally likely events](#probability-without-equally-likely-events)
    - [Source](#source-5)
  - [Getting exactly two heads (combinatorics)](#getting-exactly-two-heads-combinatorics)
    - [Source](#source-6)
    - [Fair Coin: Flip 4 times](#fair-coin-flip-4-times)
  - [Exactly three heads in five flips](#exactly-three-heads-in-five-flips)
    - [Source](#source-7)
    - [Fiar Coin: Flip 5 times](#fiar-coin-flip-5-times)

## probability independent event

### [Source](https://www.youtube.com/watch?v=uzkc-qNVoOk&list=PLC58778F28211FA19&index=1&ab_channel=KhanAcademy)

we don't know whether it's heads or tails, but we can start to `describe the chances of it`.

![](./assets/probability/flip_coin.drawio.svg)

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

## probability dependent event example

### [Source](https://www.youtube.com/watch?v=xPUm5SUVzTE&list=PLSQl0a2vh4HB3WvDaHYcqbfgw7cBNx8DO&index=27&ab_channel=KhanAcademy)

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

> Note that Each flipping is independent event.
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

## Probability without equally likely events

### [Source](https://www.youtube.com/watch?v=RI874OSJp1U&list=PLC58778F28211FA19&index=7&ab_channel=KhanAcademy)

If we get a unfair coin, which have 60% chance to get head.
In this situation, in order to visualize the probaility, we have to kind of take what's called a `frequentist approach` be known as `frequency probability`. You have 100% chance of getting a heads or a tails, and these are `mutually exclusive event`.

$$
P(H)=60\% \\
P(T)=40\%
$$

what the probability of getting heads on our first flip and on our second flip, these are `independent events`, no matter how I get on first flip, I have equal chance of getting heads on second flip.
$$
P(H_1H_2) = P(H_1) * P(H_2) = 0.36
$$

Another example, flipping coin three time
$$
P(T_1H_2T_3) = P(T_1)P(H_2)P(T_3) = 0.096
$$

## Getting exactly two heads (combinatorics)

### [Source](https://www.youtube.com/watch?v=8TIben0bJpU&list=PLC58778F28211FA19&index=8&ab_channel=KhanAcademy)

### Fair Coin: Flip 4 times

what the probability of getting `exaclty 1 heads`.
we can `add` them together because they are `mutually exclusive`, which meaning each event will not occur at same time.

$$
P(\text{exactly 1 heads}) = P(HTTT) + P(THTT) + P(TTHT) + P(TTTH) = \frac{4}{16}
$$

what the probability of getting `exaclty 2 heads`. we don't want to count $P(H_1H_2TT)$ and $P(H_2H_1TT)$ for our purposes, these are exact same outcomes.

Thinking of following, we have four flip position, having 4 place to show up head in first flip, having 3 place to show up head in second flip, multiplying all the differenct ways that you could `get all of the different scenarios`, but there have overlap on all scenarios, so we `divide it by all the different ways that you can swap two different things`.

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
