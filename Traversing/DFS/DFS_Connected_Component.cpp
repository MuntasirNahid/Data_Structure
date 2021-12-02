/*
Application of DFS Algorithm:

1)For finding the path
2)To test if the graph is bipartite
3)For finding the strongly connected components of a graph
4)For detecting cycles in a graph

*/
//number of connected components:
#include<iostream>
#include<vector>
using namespace std;
vector<int>adj[10];
bool visited[10];
void dfs(int s)
{
	visited[s] = true;
	for (int i = 0; i < adj[s].size(); ++i)
	{
		if (visited[adj[s][i]] == false)
			dfs(adj[s][i]);
	}

}

void init()
{
	for (int i = 0; i < 10; ++i)
	{
		visited[i] = false;
	}
}
int main()
{
	int n, m, i, j, x, y, connectedComponents=0;
	cin >> n >> m; //n=node,m=edge...
	while (m--)
	{
		cin >> x >> y;
		//bi-directional graph.
		adj[x].push_back(y);
		adj[y].push_back(x);

	}
	init();//initializing every node as unvisited.
	for (int i = 1; i <= n; ++i)
	{
		if (visited[i] == false)
		{
			dfs(i);
			connectedComponents++;
		}
	}
	cout << "Number of connected components: " << connectedComponents << endl;
	
        return 0;

}

