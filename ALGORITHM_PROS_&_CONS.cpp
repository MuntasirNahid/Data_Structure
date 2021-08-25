/*
//##----------------------------Dijkstra's ALgorithm-----------------------------------------##


1)This is a single-source shortest path algorithm and aims to find  the shortest -path in a directed or undirected  graph with no -negative edge weights.
2)This algorithm works for both directed and undirected graphs
3)It works only for connected graphs
4)The graph should not contain negative edge weights
5)edge gular weight same na holey amra bfs er poribortey "dijkstra" use korey thaki...
6)sorce node ke 0 diye ,bakider infinity diye initialize.
7)Dijkstra uses priority Queue

//--------------------------------------Disadvantages------------------------------------//
DIjkstra's algorithm cannot obtain correct shortest path(s)with weighted graphs having negative edges.  


//-------------------------------------Time Complexity-----------------------------------//

Case 1:When graph G is represented using an adjacency matrix ,the implementation contains two nested for loops ,each of complexity O(n),
the complexity of Dijkstra's algorithm is O(n^2).where n refers to total number of vertices in given graph.

CAse 2: When Graph is represented using Adjacency List-The time complexity, in this scenario 
reduces to O(|E| + |V| log |V|) where |E|represents number of edges and |V| represents number of vertices in the graph

//##------------------------------------------------------------------------------------------##


//##--------------------------------------SEGMENT TREE--------------------------------------------##

A Segment Tree is a data structure that allows answering range queries over an array effectively, 
while still being flexible enough to allow modifying the array.
This includes finding the sum of consecutive array elements a[l…r], or finding the minimum element
in a such a range in O(logn) time.
Between answering such queries the Segment Tree allows modifying the array by replacing one element,
or even change the elements of a whole subsegment (e.g. assigning all elements a[l…r]
to any value, or adding a value to all element in the subsegment).



//----------------------------Time Complexity:-------------------------------------------------
Time Complexity for tree construction is O(n). There are total 2n-1 nodes, and value of every node is calculated only once in tree construction.
Time complexity to query is O(Logn). To query a sum, we process at most four nodes at every level and number of levels is O(Logn). 
The time complexity of update is also O(Logn). To update a leaf value, we process one node at every level and number of levels is O(Logn).

//------------------------------------Lazy Propagation-----------------------------------------
