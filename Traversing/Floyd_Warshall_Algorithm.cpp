/*known as all pair shortest path.
 The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.
*/
/*Difference between dijkstra and floyd warshall's Algo:
Dijkstra’s Algorithm is one example of a single-source shortest or SSSP algorithm, i.e., given a source vertex it finds shortest path from source to all other vertices.
Floyd Warshall Algorithm is an example of all-pairs shortest path algorithm, meaning it computes the shortest path between all pair of nodes

1)We can use Dijskstra’s shortest path algorithm for finding all pair shortest paths by running it for every vertex.
But time complexity of this would be O(VE Log V) which can go (V3 Log V) in worst case.

2)Another important differentiating factor between the algorithms is their working towards distributed systems.
 Unlike Dijkstra’s algorithm, Floyd Warshall can be implemented in a distributed system,
 making it suitable for data structures such as Graph of Graphs (Used in Maps).

3)Lastly Floyd Warshall works for negative edge but no negative cycle, whereas Dijkstra’s algorithm don’t work for negative edges.
*/

/*jekono node theke jekono node e jawar kono way ache kina check kora jay..
P0(p zero/p not)=vi and vj er  moddhe direct edge thakley 1 ..direct edge na thakle 0(if there is an edge between vi and vj)
p1=only v1 vaya hoye jeshob vi and vj node  e jawa jay sheshob node 1 korey dibo..+direct edge(if there is a simple path vi and vj which does not use 
any other node except possibly v1).
p2= only v1 and v2 vaya hoye jeshob node e jawa jay sheshob node 1 korey dibo..+direct edge(if there is a simple path vi and vj which does not use
any other node except possibly v1 and v2)
and so on..

//final path matrix Pn ke amra reachability matrix bole thake.

// p1,p2,p3...all these matrices are dependent..p0 e kothaw 1 thakley p1 tey oikhane 1 thaktey hobe..
*/

/*
Main formula: P(k)[i,j]=P(k-1)[i,j] || P(k-1)[i,k] && P(k-1)[k,j];

means:path matrix P(k) er moddhe  i theke j tey jawar way ache jodi P(k-1) er moddhe i theke j tey jawar way thakey..or(P(k-1) er modddhe k vaya hoye i theke j tey jawa jay)
*/

/*For weighted matrix:
Q(k)[i,j]=Min(Q(k-1)[i,j] , (Q(k-1)[i,k]+Q(k-1)[k,j]);
*/

#include<iostream>
#define sz 1000
#define inf (1 << 20)
using namespace std;

int adj[sz][sz], Next[sz][sz];

void printMatrix(int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << adj[i][j] << " \n"[j == n - 1];
}
void warshall(int n)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
				{
					adj[i][j] = adj[i][k] + adj[k][j];//minimun ta rekhe dilam..
					Next[i][j] = Next[i][k];////ekhn k diye jacche destination er dikey....
				}
}
void path(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (adj[i][j] == 0)
			{
				adj[i][j] = inf;//input newar por adj[i][j]==0(global declare) holey shegulakey infinity korey dilam..
				//mane direct path nai tader moddhe..
				Next[i][j] = -1;
			}
			else
				Next[i][j] = j;
		}
	}
}
int main()
{
	int n, m, x, y, z, i, w;

	cin >> n >> m;

	for (i = 0; i < m; i++)
	{
		cin >> x >> y >> w;
		adj[x][y] = w;
		adj[y][x] = w;
	}
	path(n);
	cout << "Before Running Warshall\'s Algo:\n";
	printMatrix(n);
	warshall(n);
	cout << "After Running Warshall\'s Algo:\n";
	printMatrix(n);

	cin >> m;//number of queries
	for (i = 0; i < n; i++)
	{
		cin >> x >> y;
		cout << "Path Cost = " << adj[x][y] << endl;
		cout << "Path From " << x << " To " << y <<":" << endl;
		cout << x;
		while (x != y)
		{
			x = Next[x][y];
			cout << " " << x;
		}
		cout << endl;
	}
	return 0;


}
/*
6 8
5 2 6
1 3 2
4 0 1
3 4 8
0 2 9
5 0 1
0 1 5
0 3 2
4 4
0 1 5
2 0 2
1 2 2
3 1 1
*/

//output er moddhe 1048576 egula hocche infinity bujhacche..

//output:
/*
Before Running Warshall's Algo:
1048576 5 9 2 1 1
5 1048576 1048576 2 1048576 1048576
9 1048576 1048576 1048576 1048576 6
2 2 1048576 1048576 8 1048576
1 1048576 1048576 8 1048576 1048576
1 1048576 6 1048576 1048576 1048576
After Running Warshall's Algo:
2 4 7 2 1 1
4 4 11 2 5 5
7 11 12 9 8 6
2 2 9 4 3 3
1 5 8 3 2 2
1 5 6 3 2 2
Path Cost = 1
Path From 4 To 0:
4 0
Path Cost = 5
Path From 1 To 5:
1 3 0 5
Path Cost = 7
Path From 2 To 0:
2 5 0
Path Cost = 11
Path From 2 To 1:
2 5 0 3 1
Path Cost = 12
Path From 2 To 2:
2
Path Cost = 2
Path From 3 To 1:
3 1

*/
