#include<iostream>
#include<queue>
#include<algorithm>
#define sz 10005
using namespace std;
int rr []= {0, 0, 1, -1}; // to - right, left, down, up
int cc[] = {1, -1, 0, 0}; //from - left, right, up, down
int parent[sz][sz], adj[sz][sz], graph[sz][sz], path[sz][sz];

pair<int,int> bfs(int x, int y, int n, int m)
{
	queue<pair<int, int> > q;
	q.push({x, y});//robot er co-ordinate push korlam..
	adj[x][y] = 1;//source hishebe alada kora hoisey..
	int u, v;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)//adjacent 4 ta co-ordinate..tai <4;
		{
			u = x + rr[i];
			v = y + cc[i];
			if (u < 0 || u >= n || v < 0 || v >= m || adj[u][v])continue;//grid er corner point gula..and adj[u][v] diye bujacche visited.
			adj[u][v] = adj[x][y] + 1;//ekta step berey gelo..
			path[u][v] = i;//i=0 holey kotha theke eshechi..rr,cc er kahini..
			q.push({u, v});
			if (graph[u][v] == 1)return {u, v};
		}
	}
	return {-1, -1};

}
int main()
{
	int n, m, x, y, k, u, v;
	cin >> n >> m;//grid
	cin >> x >> y;//co-ordinate of robot
	graph[x][y] = 2;//robot er co odinate =2 korey dewa hoisey graph a..
	cin >> k;//number of exit point.
	for (int i = 0; i < k; i++)
	{
		cin >> u >> v;//co ordinate of exit point
		graph[u][v] = 1;// exit point er co ordinate gula k 1 korey dewa hoise.
	}
	pair<int, int>dest = bfs(x, y, n, m), cur;
	if (dest.first == -1)
	{
		cout << "Alas! Robot has no way to exit!" << endl;
		return 0;
	}
	cur = dest;
	vector<char>res;
	while (adj[cur.first][cur.second] != 1)
	{
		if (path[cur.first][cur.second] == 0) //left theke eshechi..
		{
			res.push_back('R');
			cur.second--;//left er moddhe firey jetey holey y-- kortey hobe + move ta hobe 'R' orthat bam theke dan e gechi..;
		}
		else if (path[cur.first][cur.second] == 1) //right theke eshechi..
		{
			res.push_back('L');
			cur.second++;
		}
		else if (path[cur.first][cur.second] == 2)
		{
			res.push_back('D');
			cur.first--;
		}
		else if (path[cur.first][cur.second] == 3)
		{
			res.push_back('U');
			cur.first++;
		}
	}
	reverse(res.begin(), res.end());
	cout << res.size() << " move is needed to go from (" << x << "," << y << ") to ("  <<
	     dest.first << "," << dest.second << ")" << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << ",\n"[i == res.size() - 1];
	return 0;



}
/*
4 6
1 1
1
2 4
*/