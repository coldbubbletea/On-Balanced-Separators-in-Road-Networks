# inertial-flow

Work flow:


1 finish Mincut(already 2023.06.28)

2 inertial flow(Start, but not runable,Coming Soon)



### We will refer to Daniel J. H.'s code as his code has many advantages by using excellent std skills:
https://daniel-j-h.github.io/post/selection-algorithms-for-partitioning/


#### Q: how to dual with multi-source and multi-sink.
![](image/multi_sink_1.svg)
![](image/multi_sink_2.svg)


A: It is equivalent to single-source single-sink version.


## USAGE:

### Use Graph.addNode to add Node for a graph
we have 3 parameters for this:
The first is node_id, it's type is int.
The Second is latitude, it's type is double.
The Third is longitude, it's type is double.
Sample:
```cpp
g.addNode(1, 40.730610, -73.935242);
```
In this sample we add a node with node_id 0 and lat:40.730610, lon:-73.935242, yes, this node coordinate is New York.