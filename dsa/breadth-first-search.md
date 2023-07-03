# breadth-first-search
###### tags: `data structure`

## What is BFS
Breadth-first search allows you to find the `shortest distance` between two things.

You can use breadth-first search to
- Write a checkers AI that calculates the fewest moves to victory.
- Write a spell checker (fewest edits from your misspelling to a real word - for ex, READED -> READER is one edit)
- Find the doctor closest to you in your network.

## BFS detail
### BFS's implement need to think two types of questions
- Question type 1: Is there a path from node A to node B?
- Question type 2: What is the shortest path from node A to node B?

## implementing graph
![](https://i.imgur.com/nyaL0ct.png)
```python=
graph = {}
graph[“you”] = [“alice”, “bob”, “claire”]
graph[“bob”] = [“anuj”, “peggy”]
graph[“alice”] = [“peggy”]
graph[“claire”] = [“thom”, “jonny”]
graph[“anuj”] = []
graph[“peggy”] = []
graph[“thom”] = []
graph[“jonny”] = []
```

## About directed graph and undirected graph
An `undirected graph` doesn’t have any arrows, and both nodes are each other’s neighbors. For example, both of these graphs are equal.
![](https://i.imgur.com/ZWFC8VL.png)

## implement bfs
```python=
from collections import deque
def BFS_search(name):
    search_queue = deque()
    search_queue += graph[name]
    searched = []
    while search_queue:
        person = search_queue.popleft()
        if not persion in searched:
            if persion_is_seller(person):
                print(f"{person} is a mango seller!")
                return True
            else:
                search_queue += graph[person]
                searched.append(person)
        return False

BFS_search("you")
```
### Running time
- O(number of edges), where edges is the arrow or connection from open person to another.
- Adding one person to the search_queue takes constant time: `O(1)`.
- Doing this for every person will take O(number of people) total. 

**Breadth-first search takes O(number of people + number of edges)**, and it’s more commonly written as O(V+E) (V for number of vertices, E for number of edges).

