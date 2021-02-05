//finding shortest path between two node..have no weight..
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define sz 1000
vector<int >adj[sz];
bool visited[sz];
int parent[sz];
int bfs(int s, int d)
{
	queue < pair<int, int> >q;
	q.push({s, 0}); //kontatey ashche ,koto cost a ashche..
	visited[s] = true;
	int node, cost, u;
	while (!q.empty())
	{
		node = q.front().first;
		cost = q.front().second;
		q.pop();
		if (node == d)return cost;
		for (int i = 0; i < adj[node].size(); i++)
		{
			u = adj[node][i];
			if (visited[u] == true)continue;
			visited[u] = true;
			q.push({u, cost + 1});//porer level e..cost 1 bere gelo..
			parent[u] = node;//u er parent=node k korey dilam..
		}

	}
	return -1;
}


void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
	}
}
int main()
{
	int n, m, i, j, s, d, x, y, w; //n=node,m=edge;
	cin >> n >> m;
	init(n);
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> x >> y; //source and destination;
	w = bfs(x, y);
	if (~w) //w=-1 holey  dhukbey na..
	{
		cout << "Minimun Cost To Visit From " << x << " To " << y << " Is = " << w << endl;
		vector<int>path;
		while (~y)
		{
			path.push_back(y);
			y = parent[y];
		}
		reverse(path.begin(), path.end());
		cout << "The Path Is : " << endl;
		for (i = 0; i < path.size(); i++)
		{
			cout << path[i] << " \n"[i == path.size() - 1];
		}


	}
	else cout << "Sorry ! There Is No Path From " << x << " To " << y << " In This Graph." << endl;


}