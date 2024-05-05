#ai 

## When shouldn't you use machine learning?
- Will simple hand-coded instruction based system work?

## Main types of machine learning
###  Supervised Learning (I know my inputs and outputs.)
-  It's called Supervised learning because you have data and labels.
- It tries to `use the data to predict a label` If it guesses the label wrong, the algorithm corrects itself and tries again (This act of correction is why it's called supervised).
- A supervised learning algorithm repeats this process over and over again, trying to get better.
- Main types of supervised learning problems are `classification and regression`.
![](Pasted%20image%2020240505170656.png)
#### Classification
It involves predicting if something is one thing or another, such as if you want it to predict whether or not a patient had heart disease or not based on their medical records or what type of dog breed was in an image.
 - Is this example one thing or another?
 - `Binary classification` = two options
 - `Multi-class classification` = more than two options
#### Regression
It involve trying to `predict a number`. You might hear it referred to as a continuous number as well, which just means a number which can go up or down.
- How much will this house sell for?
- How many people will buy this app?

###  Unsupervised Learning (I'm not sure of the outputs but I have inputs)
it has data but not labels.
#### Example
You might have purchase history of all customers at your store, and your marketing team wants to send out a promotion for next summer, but they know not everyone will be interested in new summer clothes.
##### Action
You use algorithm to find patterns in the data and group customers who purchase similar things together.

Once it's finished, you notice two groups. One group of customers who purchase only during winter time, and one group of customers who purchase mostly during summer time.
 ![](Pasted%20image%2020240505184118.png)
Problem like this are also called `clustering` or `putting groups of similar examples together`.

Recommendation problems such as recommending what music someone should listen to `based on their previous music choices`, often start out as unsupervised learning problems.
###  Transfer Learning (I think my problem may be similar to something else)
It leverages what one machine learning model has learned in another machine learning.

You could find an existing model which is learned to decipher different car types and fine tune it for your task.
- `fine tuning`: **Fine-tuning** is a technique in machine learning, optimization, and statistics used to tune the parameters of a model by making small adjustments to the initial set of parameters. Fine-tuning is typically performed using a `gradient-based optimization algorithm`, such as `gradient descent`.

![](Pasted%20image%2020240505220450.png)
#### Why is this valuable?
Because training a machine learning algorithm, which means letting it find all of the patterns in data, can be a `very expensive task to find patterns in data`.

###  Reinforcement Learning
It involves having a computer program perform some actions within a `defined space and rewarding it for doing it well or punishing it for doing poorly`.

![](Pasted%20image%2020240505221728.png)

#### Real word example
Deepmind's AlphaGo

