# Bayes theorem

## [Source](https://www.youtube.com/watch?v=HZGCoVF3YvM&ab_channel=3Blue1Brown)

> last updated: 2022/10/14

## Intro example

This formula is central to scientific discovery, It's a core tool for ML, AI, and it's even been used for treasure hunting.

### Bayes formula

$$
P(H|E) = \frac{P(H) * P(E|H)}{P(E)}
$$

### When is it usuful?

Steve is very `shy and withdrawn`, invariably helpful but with very little interest in people or in the world of reality. A `meek and tidy soul`, he has a need for order and structure, and a passion for detail.

Which of the following do you find more likely:

1. Steve is a librarian
2. Steve is a farmer

Some of you may recognize this as an example from a study conducted by the psychologists which researched human judgments, with frequent focus on when these judgments irrationally contradict what the laws of probability suggest they should be.

Or maybe I should say "alleged" irrationality; some people debate the conclusion, but more on all that later on.

According to psychologists, after people are given this description of Steve as "meek and tidy soul", most say he is more likely to be a librarian than a farmer.

## Why is true?

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
