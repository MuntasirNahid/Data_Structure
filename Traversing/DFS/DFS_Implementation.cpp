#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
#define sz 1000
vector<int >adj[sz];
bool visited[sz];
int dfs(int s, int d)
{

	stack<int>stk;
	stk.push(s);
	while (!stk.empty())
	{
		int x = stk.top();
		stk.pop();
		visited[x] = true;
		if (x == d)return true;
		for (int i = 0; i < adj[x].size(); i++)
		{
			int u = adj[x][i];
			if (visited[u] == true)continue;
			stk.push(u);
			visited[u] = true;
		}
	}
	return false;

}
int main()
{
	int n, m, i, j, s, d, x, y, w; //n=node,m=edge;
	cin >> n >> m;

	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> x >> y; //source and destination;
	w = dfs(x, y);
	if (w)
	{
		cout << "There is a way to go from " << x << " To " << y << endl;
	}
	else
		cout << "There is  no way" << endl;



}
