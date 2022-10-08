# 1. Introduction to descriptive statistics and Inferentail statistic, population, sample, mean, central tendency, variance, standerd deviation

> Last update: 2022/10/08

- [1. Introduction to descriptive statistics and Inferentail statistic, population, sample, mean, central tendency, variance, standerd deviation](#1-introduction-to-descriptive-statistics-and-inferentail-statistic-population-sample-mean-central-tendency-variance-standerd-deviation)
	- [1.1. Source](#11-source)
	- [1.2. Statistics](#12-statistics)
	- [1.3. Descriptive](#13-descriptive)
		- [1.3.1. dataset](#131-dataset)
		- [1.3.2. central tendency (the number that is most representative of a dataset)](#132-central-tendency-the-number-that-is-most-representative-of-a-dataset)
		- [1.3.3. Sample and population](#133-sample-and-population)
		- [1.3.4. formula of pupulation mean and sample mean](#134-formula-of-pupulation-mean-and-sample-mean)
	- [1.4. Dispersion](#14-dispersion)
		- [1.4.1. population dataset](#141-population-dataset)
		- [1.4.2. $\mu$ of dataset](#142-mu-of-dataset)
		- [1.4.3. 👉 variance notion](#143--variance-notion)
		- [1.4.4. population variance formula](#144-population-variance-formula)
		- [1.4.5. $\sigma$ of dataset](#145-sigma-of-dataset)
			- [1.4.5.1. result](#1451-result)
	- [1.5. Inferential](#15-inferential)
		- [1.5.1. 👉 inferential notion](#151--inferential-notion)
		- [1.5.2. sample variance formula (bias)](#152-sample-variance-formula-bias)
			- [1.5.2.1. intuitive bias variance](#1521-intuitive-bias-variance)
		- [1.5.3. unbiased sample variance](#153-unbiased-sample-variance)
	- [1.6. conclude and standerd deviation](#16-conclude-and-standerd-deviation)
		- [1.6.1. why even talk about the standerd deviation?](#161-why-even-talk-about-the-standerd-deviation)
		- [1.6.2. standerd deviation caculate](#162-standerd-deviation-caculate)
			- [1.6.2.1. if it is population](#1621-if-it-is-population)
			- [1.6.2.2. if it is sample](#1622-if-it-is-sample)
	- [1.7. Alternate variance formulas](#17-alternate-variance-formulas)
	- [1.8. Experiment preview code chunk with Markdown Preview Enhanced or vscode-markdown-run-snippet](#18-experiment-preview-code-chunk-with-markdown-preview-enhanced-or-vscode-markdown-run-snippet)

## 1.1. [Source](https://www.youtube.com/watch?v=uhxtUt_-GyM&list=PL1328115D3D8A2566&ab_channel=KhanAcademy)

## 1.2. Statistics

It can broadly be classified into maybe three categories.

- **Descriptive** = you can find indicative numbers that somehow represent all of that data without having to go over all the data.
- **Inferential** = if we can do some math on the samples, maybe we can make inferences or conclusions about the Maternal data.

## 1.3. Descriptive

### 1.3.1. dataset

1. odd number: [1, 1, 2, 3, 4]
2. even number: [1, 1, 2, 3, 4, 4]

### 1.3.2. central tendency (the number that is most representative of a dataset)

- `central tendency` also called the `average` which you can use following method to measure.
    - mean (arithmetic): (1+1+2+3+4) / 5 = 2.2
    - median: `2` is median in `dataset of odd number`, when you have a set with `even` numbers and someone tells you to figure out the median, what you do is take the middle two numbers and then you take the `arithmetic mean of these two numbers`, so `2.5` is median `in dataset of even number`.
    - mode: what number is most common in a dataset.

In statistic speak, these can kind of be representative of a data set or population's central tendency or sample central tendency, and they are all collectively, be forms of an average.

### 1.3.3. Sample and population

if we wanted to know the average height of all 150 million men in America.

it would be nearly impossible, even if I was intent on doing it, to actually measure the average height of every men in America.

So the best way I can get a sense of this, because I'm interested in what the average of the population is, maybe I can take the average of a `sample` (random people and random situations where it wouldn't be skewed based on height).

This would be a sample of the population, `The more people I get the more indicative it is`.

![sample_population](./sample_population.drawio.svg)

### 1.3.4. formula of pupulation mean and sample mean

In statistics speak, the `pupulation mean` is 🟥 $\mu$
$$
\begin{equation}
	\mu = \frac{\sum\limits_{i=1}^N x_i}{N}
\end{equation}
$$
,and 🟥 "$\bar{x}$" is equal to `sample mean` =
$$
\begin{equation}
	\frac{\sum\limits_{i=1}^n x_i}{n}
\end{equation}
$$.

> Note that:\
In formula, big "N" is used in poluation mean, and small "n" is used in sample mean.

## 1.4. Dispersion

### 1.4.1. population dataset

 frist dataset

$$
\begin{array}{cc}
 2 & 2 & 3 & 3
\end{array}
$$
second dataset

$$
\begin{array}{cc}
 0 & 0 & 5 & 5
\end{array}
$$

### 1.4.2. $\mu$ of dataset

1. (2+2+3+3)/4 = 2.5
2. (0+0+5+5)/4 = 2.5

### 1.4.3. 👉 variance notion

So the arithmetic mean of both of these populations are the same number, but In second situation `each of the distance of number from mean is further away than first sitiuation`.

You can view them that're more `dispersed`, It's not quite as indicative of all the numbers.

### 1.4.4. population variance formula

In this case, You can measure that with a `variance` which is 🟥 $\sigma^2$ in math notation, formula is
$$
\begin{equation}
 	\frac{\sum\limits_{i=1}^N (x_i-\mu)^2}{N}
\end{equation}
$$, because of you square it which become a `positive number`.

### 1.4.5. $\sigma$ of dataset

the golang calculation process file is in [here](./stat_func/basic_concept.go)

#### 1.4.5.1. result

1. 0.25
2. 6.25

we can conclude the more number of sigma the more dispersion.

## 1.5. Inferential

You want to estimate things by looking at sample, and this is actually what most of inferential statistic is all about.

Figuring out descriptive statistics about the sample, and making inferences about the population.

### 1.5.1. 👉 inferential notion

`Let's me try this drug on 100 people, and if it seems to have statistically significant results, this drug will probably work on the population as a whole.`

### 1.5.2. sample variance formula (bias)

So your natural reaction is, Ok, I have this sample, if I want to estimate the variance of the population, why don't I just apply this same formula?

So I could say this $s^2$ is `sample variance` which formula is:
$$
\begin{equation}
 	s_n^2 = \frac{\sum\limits_{i=1}^n(x_i-\bar{x})^2}{n}
\end{equation}
$$

> Note bias_variance:
> when you take a sample, there has some chance that your sample mean is pretty close to the population mean, but there's a reasonable chance that your population mean is always outside of your sample mean.
> In other word, your sample variance has chance to underestimate or overestimate, but more often than underestimating.

#### 1.5.2.1. intuitive bias variance

Each dot is data all of which represent population dataset more on the right side more larger, you may get all data of sample on the left side or right side of population data.

As a result you will get bias sample variance.

![bias_variance](./bias_variance.drawio.svg)

### 1.5.3. unbiased sample variance

Because sample variance often be underestimated, we usually substract 1 in denominator to get bigger result , using unbiased sample variance instead.

$$
\begin{equation}
	s_{n-1}^2 = \frac{\sum\limits_{i=1}^n({x_i}-\bar{x})^2}{n-1}
\end{equation}
$$

## 1.6. conclude and standerd deviation

|         Concept         |                       Population                        |                             Sample                             |
| :---------------------: | :-----------------------------------------------------: | :------------------------------------------------------------: |
|          mean           |       $\mu = \frac{\sum\limits_{i=1}^N{x_i}}{N}$        |         $\bar{x} = \frac{\sum\limits_{i=1}^n{x_i}}{n}$         |
|        variance         | $\sigma^2 = \frac{\sum\limits_{i=1}^N({x_i}-\mu)^2}{N}$ | $s_{n-1}^2 = \frac{\sum\limits_{i=1}^n({x_i}-\bar{x})^2}{n-1}$ |
| standerd deviation (SD) |               $\sigma = \sqrt{\sigma^2}$                |                  $s_{n-1} = \sqrt{s_{n-1}^2}$                  |

### 1.6.1. why even talk about the standerd deviation?

- the units work out a little better.
    - If let's say all of our data points, we're measured in meters. if we are taking a bunch of measurements of length, than `the units of the variance would be meter squared`, right? And that's kind of a strange concept if you say the average dispersion from the center has been meter squared.
    - So well, first when you take the square root of it, getting `SD` then, saying the standard deviation is x or y meters.

### 1.6.2. standerd deviation caculate

$$
\begin{array}{cc}
 1 & 2 & 3 & 8 & 7
\end{array}
$$

#### 1.6.2.1. if it is population

$\mu = \frac{21}{5} = 4.2$
$\sigma^2 = \frac{\sum\limits_{i=1}^{N}({(1-\mu)^2 \dotsm (7-\mu)^2)}}{5} = 7.76 $
$\sigma = \sqrt{7.76} = 2.79$

#### 1.6.2.2. if it is sample

$\bar{x} = \frac{21}{5} = 4.2$
$s^2 = \frac{\sum\limits_{i=1}^{n}({(1-\bar{x})^2 \dotsm (7-\bar{x})^2)}}{4} = 9.7$
$s = \sqrt{9.7}=3.11$

## 1.7. Alternate variance formulas

$$
	\begin{equation}
		\sigma^2 = \frac{\sum\limits_{i=1}^N(x_i-\mu)^2}{N} = \frac{\sum\limits_{i=1}^N{(x_i^2-2{x_i}{\mu} + \mu^2)}}{N}
	\end{equation}
$$
where
$$
	\tag{6.*}
	\frac{\sum\limits_{i=1}^N(x_i-\mu)^2}{N} = \frac{\sum\limits_{i=1}^N((x_i-\mu)(x_i-\mu))}{N} = \frac{\sum\limits_{i=1}^N{(x_i^2-2{x_i}{\mu} + \mu^2)}}{N}
$$

equal

$$
	\tag{6.*.1}
	\frac{\sum\limits_{i=1}^N{x_1}^2 - 2\mu\sum\limits_{i=i}^{N}x_i + \mu^2\sum\limits_{i=1}^N{1}}{N}
$$

same

$$
	\tag{6.*.2}
	\frac{\sum\limits_{i=1}^N{x_i}^2}{N} - \frac{2\mu\sum\limits_{i=1}^N{x_i}}{N} + \frac{\mu^2{N}}{N}
$$

then get `raw score method`, which is often times a fater way of calculating.

$$
	\tag{6.*.3}
	\frac{\sum\limits_{i=1}^N{x_i}^2}{N} - 2\mu^2 + \mu^2 = \frac{\sum\limits_{i=1}^N{x_i^2}}{N} - \mu^2
$$

or

$$
	\tag{6.*.4}
	\frac{\sum\limits_{i=1}^N{x_i}^2}{N} - \frac{\sum\limits_{i=1}^N{x_i}^2}{N^2}
$$

-----

## 1.8. Experiment preview code chunk with Markdown Preview Enhanced or vscode-markdown-run-snippet

```python {cmd=true}
print("This will run python3 program")
```

```go
package main

import (
 "github.com/montanaflynn/stats"
   "fmt"
)

func main() {
 population_dataset := map[string]stats.Float64Data{
  "first":  {2, 2, 3, 3},
  "second": {0, 0, 5, 5},
 }
 for dataset_name, data := range population_dataset {
  if result, err := stats.Variance(data); err == nil {
   fmt.Printf("%s dataset variance is %v\n", dataset_name, result)
  }
 }
}
```

```python {cmd=true matplotlib=true}
import matplotlib.pyplot as plt
plt.plot([1,2,3, 4])
plt.show() # show figure
```

```latex {cmd=true}
\documentclass{standalone}
\begin{document}
  Hello world!
\end{document}
```
