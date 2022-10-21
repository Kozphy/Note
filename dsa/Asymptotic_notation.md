# Algorithmic complexity / Big-O / Asymptotic analysis

## Asymptotic Notation

### [Source](https://www.youtube.com/watch?v=iOq5kSKqeR4&ab_channel=CS50)

This notation measrue how does the runtime of your programe grow?
$$
\text{best case} = \Omega(number) \\
\text{worst case} = O(number) \\
\text{best case and worst case are the same} = \theta(number)
$$

> Note:
> Maybe for smaller input data O(n) doesn't run faster than $O(n^2)$

## BigO cheet sheet

[cheet_sheet](https://www.bigocheatsheet.com)

## Amortized Analysis

This analysis is not going to make out algorithms run faster it's just a way of thinking about the cost of them and maybe in our thinking we can convince ourselves that it's cheaper than meets the eye.

### potential function

potential function is basically that `is gathering up value that not necessarily paid on the current operation` (the doughnut you currently making), but `some costs` were gathering up into some function that `will go into some how spread out over all our operations` (all doughnut).

![potential function](./asset/potentila_Function.drawio.svg)
$$
\overset{\land}{c_i} = \text{amortized cost} \\
{c_i} = \text{actual cost} \\
\Phi{(D_i)} - \Phi{(D_{i-1})} = \text{how much incrementally amotized cost during amortization period} \\
\Phi{(D_n)} = \text{all cost of Intangible Assets} \\
\Phi{(D_0)} = \text{amortized cost at start time}
$$

### Example Binary Counter (Round-trip)

![binary round trip](./asset/binary_round_trip.drawio.svg)

- Let $\Phi{(D_i)} = b_i \space \text{the number of 1's in i}$
- The cost of changing 0000 to 0001 would be

$$
\overset{\land}{c_i} = c_i + \Phi{(D_i)} - \Phi{(D_{i-1})} = 1 + 1 - 0 = 2
$$

- The cost of changing  0001 to 0010 would be

$$
\overset{\land}{c_i} = c_i + \Phi{(D_i)} - \Phi{(D_{i-1})} = 2 + 1 - 1 = 2
$$

- The cost of changing  0010 to 0011 would be

$$
\overset{\land}{c_i} = c_i + \Phi{(D_i)} - \Phi{(D_{i-1})} = 1 + 2 - 1 = 2
$$

- The cost of changing 0011 to 0100 would be
$$
\overset{\land}{c_i} = c_i + \Phi{(D_i)} - \Phi{(D_{i-1})} = 3 + 1 - 2 = 2
$$
