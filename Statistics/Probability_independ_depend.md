# Probability explained Independent and dependent events

- [Probability explained Independent and dependent events](#probability-explained-independent-and-dependent-events)
  - [probability independent event](#probability-independent-event)
    - [Source](#source)
  - [Mutually-Exclusive Events](#mutually-exclusive-events)
  - [probability dependent event example](#probability-dependent-event-example)
    - [Source](#source-1)
  - [Compound probability of independent events](#compound-probability-of-independent-events)
    - [Source](#source-2)

## probability independent event

### [Source](https://www.youtube.com/watch?v=uzkc-qNVoOk&ab_channel=KhanAcademy)

we don't know whether it's heads or tails, but we can start to `describe the chances of it`.

![](./assets/flip_coin.drawio.svg)

$$
P(H) = ? = \frac{\text{number of possibilities that meet by condition}}{\text{number of equally likely possibilities}} = \frac{1}{2}
$$

Another way to think about or conceptualize probaility that will give you this exact same answer is to say, if I was to run the flipping a coin experiment, which is every time you run this random event `many times` and `the more the better`, `you would really approach to get this 50%`.

## Mutually-Exclusive Events

if we are rolling fair dice at once what the probability is 2 and 3.
$$
P(\text{2 and 3}) = \frac{0}{6}
$$

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
  
- $\frac{3}{8}$ change we get Unfair coin in a beg
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
