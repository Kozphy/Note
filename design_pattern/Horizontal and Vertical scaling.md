# Horizontal and Vertical scaling
###### tags: design pattern

## article source
https://dev.to/wmahathre/horizontal-and-vertical-scaling-1lid

## what is Scalability
Scalability is being able to handle more request and both vertical and horizontal scaling handle these request differently. 

## differently
Horizontal scaling has multiple servers that receive the request but vertical scaling has only one big server that handles them.

![](https://i.imgur.com/IDUmpY9.png)

## Horizontal scaling advantage
Horizontal scaling has what’s called load balancing so if one of the servers fails then the load balancer redirects the request to other servers and if a new server is added the load balancer will start to send requests to it.

Horizontal scaling is ideal for big companies because they can add more servers if the demand is needed and its scaled well as users increase.

## Vertical scaling advantage
The good thing about vertical scaling is that it has data consistency.

This is because there is only one system where all the data resides. Having a horizontal scaling where transaction send data across multiple servers can get complicated and is harder to maintain.

## Vertical scaling disadvantage
The bad thing about vertical scaling is that it has hardware limits.

You can add more resources like cpu/ram/disk capacity to your server but it’s not enough if you have large users.

## which to choose
When deciding which scaling to use its best to decide which one is most suitable for your needs. If you’re running a small company and don’t expect many users/data to increase then having a vertical scaling can be ideal for you. If you’re working with a large company where there are increase in users then using horizontal scaling is the way to go.