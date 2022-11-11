# Binomial Distribution

> Last updated: 2022/10/18

- [Binomial Distribution](#binomial-distribution)
  - [Binomial Distribution 1](#binomial-distribution-1)
    - [binomial distribution](#binomial-distribution-1)
    - [Source](#source)
    - [learn with first example before get formula of binomial coefficients](#learn-with-first-example-before-get-formula-of-binomial-coefficients)
  - [Binomial Distribution 2](#binomial-distribution-2)
    - [Source](#source-1)
  - [Binomial Dstribution 3](#binomial-dstribution-3)
    - [Source](#source-2)
  - [Expected Value: E(X)](#expected-value-ex)
    - [Source](#source-3)
  - [Expected value of binomial distribution](#expected-value-of-binomial-distribution)
    - [Source](#source-4)

## Binomial Distribution 1

### [binomial distribution](https://peterstatistics.com/CrashCourse/Distributions/Binomial.html)

### [Source](https://www.youtube.com/watch?v=O12yTz_8EOw&list=PL1328115D3D8A2566&index=9&ab_channel=KhanAcademy)

### learn with first example before get formula of binomial coefficients

Let's say I have a coin, and it's a fair coin, and I'm going to flip it five times. The coin can be `heads` or `tail` which is indicated as `H` or `T` , separately.

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

## Binomial Distribution 2

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

Then you will get particular instance of **binomial probaility Distribution**.

if you get kind of **infinite number of binomial coefficients value**, you will get like a **bell curve**.

![flip_5_binomial_distri](./assets/probability/flip_5_binomial_distri.drawio.svg)

$$
P(X=n) = \frac{5!}{n!(5-n)!}
$$
[Binomial Distribution vs normal distribution](https://byjus.com/maths/binomial-distribution/#:~:text=The%20main%20difference%20between%20the,an%20infinite%20number%20of%20events.)
The main difference between the binomial distribution and the normal distribution is that **binomial distribution is discrete**, whereas the **normal distribution is continuous**. It means that the binomial distribution has a finite amount of events, whereas the normal distribution has an infinite number of events

## Binomial Dstribution 3

### [Source](https://www.youtube.com/watch?v=vKNpQ_KTXvE&list=PL1328115D3D8A2566&index=11&ab_channel=KhanAcademy)

For ex, `6 shot baskests ball`, success is equal to 30%.
X = how many success shot that I make.
$$
P(X=0) = (0.7)^{6} *{6 \choose 0} = (0.7)^{6}* \frac{6!}{0!(6-0)!} \\
P(X=1) = (0.7)^{5} *{0.3}* {6 \choose 1} = (0.7)^5 *0.3* \frac{6!}{1!(6-1)!} \\
P(X=2) = (0.7)^{4} *(0.3)^{2}* {6 \choose 2} = (0.7)^4 *(0.3)^{2}* \frac{6!}{2!(6-2)!} \\
P(X=3) = (0.7)^{3} *(0.3)^{3}* {6 \choose 3} = (0.7)^3 *(0.3)^{3}* \frac{6!}{3!(6-3)!} \\
P(X=4) = (0.7)^{2} *(0.3)^{4}* {6 \choose 4} = (0.7)^2 *(0.3)^{4}* \frac{6!}{4!(6-4)!} \\
P(X=5) = (0.7)^{1} *(0.3)^{5}* {6 \choose 5} = (0.7)^1 *(0.3)^{5}* \frac{6!}{5!(6-5)!} \\
P(X=6) = (0.3)^{6} *{6 \choose 6} = (0.3)^{6}* \frac{6!}{6!(6-6)!} \\
$$

## Expected Value: E(X)

### [Source](https://www.youtube.com/watch?v=j__Kredt7vY&list=PL1328115D3D8A2566&index=13&ab_channel=KhanAcademy)

Say we have our population of numbers is $3,3,3,4,5$

mean ($\mu$) : $\frac{(3+3+3+4+5)}{5} = 3.6$

we can express mean in another way:
$$
\begin{equation}
\begin{split}
\frac{3(3) + 1(4) + 1(5)}{5} = \frac{1}{5}(3*3 + 1*4 + 1 *5) \newline
= \frac{3}{5}* 3 + \frac{1}{5} *4 + \frac{1}{5}*5 \newline
= 0.6 *3 + 0.2* 4 + 0.2 *5 \newline
= 60\%* 3 + 20\% *4 + 20\%* 5 \newline
= 1.8 + 0.8 + 1
\end{split}
\end{equation}
$$

Let's say we have random variable, what happens if **population is not finite** (We throw the coin trial as we want)?  :
$$
X = \text{number of heads after 6 tosses of fair coin.}
$$

In this condition, we can't caculate the population mean but,
we can find **expected value of random variable** as known as **arithmetic mean of an infinite population**.
$$
\begin{equation}
\begin{split}
E(X) = 0 *0.1563\% + 1* 9.375\% + 2 *23.438\% + \newline 3*31.25\% +  4 *23.438\% + 5* 9.375\% + 6 * 1.563\%
\end{split}
\end{equation}
$$

## Expected value of binomial distribution

### [Source](https://www.youtube.com/watch?v=SqcxYnNlI3Y&list=PL1328115D3D8A2566&index=14&ab_channel=KhanAcademy)

$E(X)$ was just the population mean **with a infinite poupulation**.

In following example, we say that the random variable x is equal to the number of success with probability P after N trials.

$$
E(X) = \text{number of success with probability P after N trials.}
$$

Intuitive way for $E(X)$:
n = number of trials I make
p = probability
$$
E(X) = n * p
$$

Another ex:
If $X = \text{number of basketball I make after 10 shots where I have 1 shots is 40\%}$
where is

$$
E(X) = 10 * 0.4  = 4
$$

**In binomial distribution** this is you get **k successes**. (see **Binomial Dstribution 3**)
$$
P(X=K) = {n \choose k} *p^k*(1-p)^{n-k}
$$

where **sum of expected value** is following
$$
\begin{equation}
\begin{split}
E(X) = \sum_{k=1}^n k{n \choose k} * p^k * (1-p)^{n-k} \\
= 1 {n \choose 1} p^1 (1-p)^{n-1} + 2 {n \choose 2} p^2 (2-p)^{n-2}  + \dotso + n {n \choose n} * p^n * (1-p)^{n-n} \\
= \sum_{k=1}^{n} k \frac{n!}{k!(n-k)!}*p^k* (1-p)^{n-k} \\
= \sum_{k=1}^{n} k \frac{n!}{k(k-1)!(n-k)!}*p^k*(1-p)^{n-k} \\
= \sum_{k=1}^{n} \frac{n!}{{(k-1)}!(n-k)!} *p^k* (1-p)^{n-k} \\
= \sum_{k=1}^{n} \frac{n*(n-1)!}{{(k-1)}!(n-k)!} *p *p^{k-1}* (1-p)^{n-k} \\
= np \sum_{k=1}^{n} \frac{(n-1)!}{(k-1)!(n-k)!} *p^{k-1}* (1-p)^{n-k}
\end{split}
\end{equation}
$$
