/*Signle source shortest path.
edge gular weight same na holey amra bfs er poribortey "dijkstra" use korey thaki...
sorce node ke 0 diye ,bakider infinity diye initialize.

priority queue use kora hoye thake...

priority queue tey (koto cost a ashchi,kon node ashchi)

backtrack korey path ta bahir kora hoisey..

0 based er jonno x--

porey +1 kora hoisey main value ta ashar jonno

1) Initialize distances of all vertices as infinite.

2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or
   distance) is used used as first item  of pair
   as first item is by default used to compare
   two pairs

3) Insert source vertex into pq and make its
   distance as 0.

4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq.
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do
       following for every vertex v.

           // If there is a shorter path to v
           // through u.
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)

5) Print distance array dist[] to print all shortest
   paths.

   */
#include<bits/stdc++.h>
#define sz 1000
#define INF 1<<29
using namespace std;
vector<int>adj[sz], w[sz];
int parent[sz], cost[sz];
int dijkstra(int st, int en)
{
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
	pq.push({0, st}); //0 cost a ashchi st tey..
	cost[st] = 0;
	int u, c;
	while (!pq.empty())
	{
		c = pq.top().first;
		u = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[u].size(); i++)
		{
			if (c + w[u][i] < cost[ adj[u][i] ])
			{
				cost[ adj[u][i] ] = c + w[u][i];
				pq.push({cost[ adj[u][i] ], adj[u][i]});
				parent[ adj[u][i] ] = u;
			}
		}
	}
	return cost[en];
}
void init(int n)
{
	for (int i = 0; i < n; i++) {
		parent[i] = -1; cost[i] = INF;
	}
}
int main()
{
	int n, m, i, j, x, y, z, st, en;
	cin >> n >> m; //n=node,m=edge
	init(n);
	for (i = 0; i < m; i++)
	{
		cin >> x >> y >> z; //z=weight of the edge
		x--;//for 0 based indexing.
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
		w[x].push_back(z);
		w[y].push_back(z);
	}
	cin >> st >> en; //start and end
	x = dijkstra(st - 1, en - 1); //0 based indexing er jonno
	cout << "The Minimum Cost From " << st << " To " << en << " = " << x << endl;
	x = en - 1; //for 0 based indexing;
	vector<int>path;

	while (~x)
	{
		path.push_back(x + 1); //+1 korey dile 0 based indexing er fole j -1 hoye gechilo oita cover hoye jabey.
		x = parent[x];
	}
	reverse(path.begin(), path.end());
	cout << "The Path Is Given Below :" << endl;
	for (i = 0; i < path.size(); i++)
		cout << path[i] << ",\n"[i == path.size()-1];

}
/**
7 10
1 3 1
1 4 6
2 6 1
4 2 2
2 7 5
3 6 8
3 4 2
5 4 9
5 6 2
7 5 1
1 7
*/
