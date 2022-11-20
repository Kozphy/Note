# Bayes theorem

> last updated: 2022/10/15

- [Bayes theorem](#bayes-theorem)
  - [Source](#source)
  - [Intro example](#intro-example)
    - [Bayes formula](#bayes-formula)
    - [What is it saying?](#what-is-it-saying)
    - [When is it usuful?](#when-is-it-usuful)
      - [When to use Bayes' theory](#when-to-use-bayes-theory)
      - [Generalizing as a formula](#generalizing-as-a-formula)
      - [more intuitive formula](#more-intuitive-formula)
  - [how to make probability more intuitive](#how-to-make-probability-more-intuitive)
  - [need to tatto in mind](#need-to-tatto-in-mind)

## [Source](https://www.youtube.com/watch?v=HZGCoVF3YvM&ab_channel=3Blue1Brown)

## Intro example

This formula is central to scientific discovery, It's a core tool for ML, AI, and it's even been used for treasure hunting.

### Bayes formula

$$
P(H|E) = \frac{P(H) * P(E|H)}{P(E)}
$$

### What is it saying?

$$
P(H) = \text{Probability a \textbf{hypothesis} is true (before any evidence)} \\
$$

$$
P(E|H) = \text{Probability of seeing the \textbf{evidence} if the \textbf{hypothesis} is true} \\
$$

$$
P(E) = \text{Probability of seeing the \textbf{evidence}} \\
$$

$$
P(H|E) = \text{Probability a \textbf{hypothesis} is true given some \textbf{evidence}} \\
$$

### When is it usuful?

Steve is very `shy and withdrawn`, invariably helpful but with very little interest in people or in the world of reality. A `meek and tidy soul`, he has a need for order and structure, and a passion for detail.

Which of the following do you find more likely:

1. Steve is a librarian
2. Steve is a farmer

Some of you may recognize this as an example from a study conducted by the psychologists which researched human judgments, with frequent focus on `when these judgments irrationally contradict what the laws of probability suggest they should be`.

Or maybe I should say "alleged" irrationality; some people debate the conclusion, but more on all that later on.

According to psychologists, after people are given this description of Steve as "meek and tidy soul", most say he is more likely to be a librarian than a farmer.

After all these traits line up better with the stereotypical view of a librarian than that of a farmer.

And according to psychologists, this is irrational. `The point is` not whether people hold correct or biased views about the personalities of librarians or farmers, it's that almost no one thinks to incorperate information about the ratio of farmers to librarians into their judgments.

The question is whether people even think to consider this ratio, enough to make a rough estimate.

`Rationality is not about knowing facts, it's about recognizing which facts are relevant.`

Example:
Assumption have 200 farmers and 10 librarians. Then when you hear the meek and tidy soul descriptionm let's say your got instinct is that 40% of librarians would fit that description and that 10% of farmers would.

![bayes_farmer_lib_1](./assets//probability/bayes_farmer_lib_1.drawio.svg)
If those was your estimate, that would mean that from your sample, you would expect about 4 librarians to fit this description, and about 20 famers fit that description.

So the probability that a random person among those who fits this description is a librarian is

$$
(\text{Librarian given description}) = \frac{4}{(20+4)} \approx{} 16.7\%
$$

So even if you think a librarian is 4 times as likely as a farmer to fit this description, that is not enough to overcome the fact that there are way more farmers.

![likelihood of fitting the description](./assets/probability/likelihood_of_fitting_the_desc.drawio.svg)

The upshot, `this is the key mantra underlying Bayes' theorem` is that `new evidence should not completely determine your beliefs in a vacuum; it should update prior beliefs`.

`The way of seeing evidence restricts the space of possibilities, and the ratio you need to consider after that`.

#### When to use Bayes' theory

The general situation where Bayes' theorem is relevant is when you have some hypothesis,like Steve is a librarian, and you see some evidence, say this verbal description of Steve as "meek and tidy soul", and you want to know the probability that the hypothesis holds given that the evidence is true.

![when to use Bayes rules](./assets/probability/when_to_use_Bayes'_rule.drawio.svg)

1. You have a hypothesis
2. You've observed some evidence
3. You want P(Hypothesis given the evidence) = $P(H|E)$

#### Generalizing as a formula

In the example, the first relevant number is the probability that the hypothesis holds `before considering any of that new evidence` which is $P(H) = \frac{1}{21}$ which came from considering the ratio of librarians to farmers in general population, this number is known as the `prior`, the `vertical bar` is means we're talking about a proportion of a limited part of the total space of possibilities, the `limited part to the left side` where the hypothesis hold which is called `likelihood` in context of Bayes' theorem.

After that, we needed to consider the proportion of librarians that fit this description the probability we would see the evidence given that the hypothesis is true.

Similarly, we need to know how much of the other side of space includes the evidence; the probability of seeing the evidence given that our hypothesis isn't true.

$$
P(E| \lnot{} H) = 0.1
$$
where **elbow symbol is used to mean "not"** in probability.

The `probability that our librarian hypothesis` is true given the evidence is the total number of librarians fitting the evidence, 4 divided by the total number of people fitting the evidence, 24.
$$
\begin{equation}
\begin{split} P(H|E)
&=\frac{\text{total of population} *P(H)P(E|H)} {\text{total of population}* P(H)P(E|H) + \text{total of population} *P(\lnot{} H)P(E|\lnot{}H)}
\\
&= \frac{P(H)P(E|H)} {P(H)P(E|H) + P(\lnot{} H)P(E|\lnot{}H)}
\\
&= \frac{P(H)P(E|H)}{P(E)}
\\
&= \frac{\frac{10}{210}*0.4}{\frac{10}{210}*0.4 + \frac{200}{210}*0.1}
\end{split}
\end{equation}
$$

> Note:
P(H) is called `Prior`, which means that hypothesis holds probability before considering any of that new evidence.
P(E|H), where E is called `Likelihood`, vertical bar means that we're talking about a proportion of a limited part of the total space of possibilities.
P(H|E) is called `Posterior`, which means is that you're belief about the hypothesis after seeing the evidence.

#### more intuitive formula

![generalizing_bayes_formula](./assets/probability/generalizing_bayes_formula.drawio.svg)

This is sort of the distilled version of thinking with a representative sample where we think with areas instead of counts, which is more flexible and easier to sketch on the fly.

Rather than bringing to mind some specific number of examples, `think of the space of all possibilities as 1 x 1 square`. Any event occupies some subset of this space, and the probability of that even can be thought about as the area of that subset.

![1x1 square](./assets/probability/1*1_square.drawio.svg)

for example:
thinking of the hypothesis as filling the left part of this square with a witdth of $P(H)$
![hypothesis_square](./assets/probability/hypothesis_square.drawio.svg)

When you see evidence, the space of possibilities gets restricted. Crucially, that restriction may not happen evenly between the left and the right.

## how to make probability more intuitive

Another example:
Linda is 31 years old, single, outspoken, and very bright. She majored in philosophy. As a student, she was `deeply concerned with issues of discrimination` and social justice, and also participated in anti-nuclear demonstrations.

1. Linda is a bank teller.
2. Linda is a bank teller and is actice in the feminist movement.

85% of participants choose 2, which has to be smaller because `2 is subset of 1`.
what's fascinating is that there's a simple way to rephrase the question that dropped this error from 80% to 0. Instead, if participants were told there are 100 people who fit this description, and asked people to estimate how many of those 100 are bank seller, and how many are bank tellers who are active in the feminist movement, Everyone correctly assigns a higher number to the first option than to the second.

People often think of probability as being the study of uncertainty. While that is of course how it's applied to science, the actual math of probability is really `just the math of proportions`.

![probability essence](./assets/probability/probability_essence.drawio.svg)

Take a look at Bayes' theorem as a statement about proportions, once you digest what it's saying, it's actually kind of obvious. Both sides tell you to look at all the cases where the evidence is true and consider the proportion of those cases where the hypothesis is also true.

$$
P(H|E) = \frac{P(H)P(E|H)}{P(E)}
$$

## need to tatto in mind

`evidence should not determine beliefs, but update them.`
