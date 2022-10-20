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
> At smaller input data O(n) doesn't run faster than $O(n^2)$

## BigO cheet sheet

[cheet_sheet](https://www.bigocheatsheet.com)

## Amortized Analysis

### potential function

![potential function](./asset/potentila_Function.drawio.svg)
$$
\overset{\land}{c_i} = \text{amortized cost} \\
c_i = \text{actual cost}
$$

### Example Binary Counter (Round-trip)

![binary round trip](./asset/binary_round_trip.drawio.svg)
