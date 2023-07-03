# Greedy algorithems
###### tags: `data structure`

## The classroom scheduling problem
![](https://i.imgur.com/bucHDVJ.png)
![](https://i.imgur.com/XrDLYFc.png)

You want to hold as many classes as possible in this classroom. How do you pick what set of classes to hold, so that you get the biggest set of classes possible?
1. Pick the class that ends the soonest. This is the first class you'll hold in this classroom.
2. Now, you have to pick a class that starts after the first class. Again, pick the class that ends the soonest. This is the second class you'll hold.

![](https://i.imgur.com/Sm50Pl5.png)
![](https://i.imgur.com/Jwj3Wju.png)

**A greedy algorithm is simple: at each step, pick the optimal move.**

**In technical terms: at each step you pick the locally optimal solution, and in the end you’re left with the globally optimal solution.**

## The Knapsack problem
![](https://i.imgur.com/DjQOwM7.png)
![](https://i.imgur.com/z901Nof.png)
![](https://i.imgur.com/6MBZLEr.png)

## The set_convering problem
![](https://i.imgur.com/qMUWVGP.png)
![](https://i.imgur.com/tvVwbX0.png)
![](https://i.imgur.com/81Qidbd.png)

### Approximation algorithms
![](https://i.imgur.com/AygqKBn.png)

This is called an approximation algorithm. When calculating the exact solution will take too much time, an approximation algorithm will work. Approximation algorithms are judged by
- How fast they are
- How close they are to the optimal solution.

In this case, the greedy algorithm runs in **O(n^2)** time, where n is the number of radio stations.

### Code for setup
![](https://i.imgur.com/xBD1uSo.png)

![](https://i.imgur.com/bQHaKsZ.png)

The keys are station names, and the values are the states they cover. 

![](https://i.imgur.com/fbSfA0r.png)

### Calculating the answer
![](https://i.imgur.com/7JvD4J1.png)

#### What's going on
![](https://i.imgur.com/bSRgBcu.png)
![](https://i.imgur.com/xGSp2J5.png)

- A `set union` means "combine both sets"
- A `set intersection` means "find the items that show up in both sets (in this case, just the tomato.)"
- A `set difference` means "subtract the items in on set from the items in the other set."


![](https://i.imgur.com/iC5RHO2.png)
![](https://i.imgur.com/u3FbwPW.png)
![](https://i.imgur.com/0fkvPPr.png)
![](https://i.imgur.com/eOI5ecq.png)
```python=
while states_needed:
    best_station = None
    states_cover = set()
    for station, states in stations.items():
        coverd = states_needed & states
        if len(covered) > len(states_covered):
            best_station = station
            states_covered = covered
states_need -= states_covered
final_stations.add(best_station)
```

![](https://i.imgur.com/jMVGLkp.png)

## NP-complete problems
![](https://i.imgur.com/E08K13s.png)
![](https://i.imgur.com/QI7gCwy.png)
### Traveling salesperson, step by step
#### two cities

![](https://i.imgur.com/YdnOn4X.png)
Two cities = two possible routes

#### three cities
![](https://i.imgur.com/BtVDEa6.png)
![](https://i.imgur.com/0loF4Mq.png)

#### four cities
Four possible start cities, with six possible routes for each start city = 4*6 =24 possible routes.

![](https://i.imgur.com/yQE7Ugv.png)


This is called the factorial function (remember reading about this in chapter 3?). So 5! = 120. Suppose you have 10 cities. How many possible routes are there? 10! = 3,628,800. You have to calculate over 3 million possible routes for 10 cities. As you can see, the number of possible routes becomes big very fast! This is why it’s impossible to compute the “correct” solution for the traveling-salesperson problem if you have a large number of cities.

The traveling-salesperson problem and the set-covering problem both have something in common: you calculate every possible solution and pick the smallest/shortest one. Both of these problems are *NP-complete*.

## How do you tell if a problem is NP-complete?
The short answer: there’s no easy way to tell if the problem you’re working on is NP-complete. Here are some giveaways.
![](https://i.imgur.com/IfxsBnL.png)

