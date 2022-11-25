# Dijkstra's algo
###### tags: `data structure`

## shortest path vs faster path
### shortest path
![](https://i.imgur.com/gFZ7Ahr.png)
It’s the shortest path, because it has the least number of segments (three segments).

### faster path
But suppose you add travel times to those segments. Now you see that there's a faster path.
![](https://i.imgur.com/ZK2rkv0.png)


**You can do that fastest with a different algorithm called Dijkstra’s algorithm**.

## Terminology
When you work with Dijkstra’s algorithm, each edge in the graph has a number associated with it. These are called **weights**.
![](https://i.imgur.com/nb2QZzU.png)

A graph with weights is called a **weighted graph**. A graph without  weights is called an **unweighted graph**.

- To calculate the shortest path in an unweighted graph, use breadth-first search.

- To calculate the shortest path in a weighted graph, use Dijkstra’s algorithm.

Graphs can also have cycles. A cycle looks like this.
![](https://i.imgur.com/wL0WaH4.png)
It means you can start at a node, travel around, and end up at the same node. 

![](https://i.imgur.com/peGzUbX.png)


## Working with Dijkstra's algorithm
### four steps to Dijkstra's algo
- Find the "cheapest" node. This is the node you can get in the least amount of time.
- Update the costs of the neighbors of this node. I'll explain what I mean by this shortly.
- Repeat until you've done this for every node in the graph.
- Calculate the final path.

## Step 1
![](https://i.imgur.com/idmWE9z.png)
![](https://i.imgur.com/4HCXlWW.png)

## Step 2
![](https://i.imgur.com/62Vgi2m.png)
- A shorter path to A (down from 6 to 5 minutes)
- A shorter path to the finish (down from infinity to 7 minutes)

## Step 3
![](https://i.imgur.com/UzWZnmp.png)
![](https://i.imgur.com/ZbbDREb.png)

