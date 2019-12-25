# Dijkstras-Algorithm-Path
Implement Dijkstra's algorithm on vertices numbered 0 to V-1 to find the __SHORTEST PATH__. The edges are denoted by “u v w”, denoting an edge from the vertex u to the vertex v with a weight of w.

## Input Format 
The first input is T, the number of test cases. Thereafter, each test case starts with “V E”, where V is the number of vertices and E is the number of edges. Thereafter, each E line contains “u v” denoting an edge from the vertex u to the vertex v. The source is always taken to be vertex numbered 0.

## Output Format 
V lines, each printing the __PATH__ from source of the vertex V. If there is no path from source to V, print "NIL".

The edges are prioritized in the order they are input, with an earlier edge in input having a higher priority. The edges must be processed in the same order for any vertex.

## NOTE
The tie breaking condition is that a vertex prefers a smaller parent. The vertices are all unique!

## Sample Input

1<br/>
7 14<br/>
0 5 12<br/>
5 0 12<br/>
0 1 6<br/>
1 0 6<br/>
1 2 1<br/>
2 1 1<br/>
2 5 3<br/>
5 2 3<br/>
0 3 7<br/>
3 0 7<br/>
3 4 1<br/>
4 3 1 <br/>
4 5 1<br/>
5 4 1<br/>

## Sample Output

0<br/> 
0 1<br/> 
0 1 2 <br/>
0 3 <br/>
0 3 4 <br/>
0 3 4 5 <br/>
NIL
