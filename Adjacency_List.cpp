#include<iostream>
#include<vector>
using namespace std;
#define sz 1000
vector<int>adj[sz], weight[sz]; //2 dimension..parallel..ekta adj er..arekta weight er..

void PrintList(int n)
{
	for (int i = 0; i < n; i++)
	{	cout << i << ":";
		for (int j=0; j < adj[i].size(); j++)//i er adjacent gula adj [i] er moddhe biddoman..
			cout << "(" << adj[i][j] << "," << weight[i][j] << ")" << " \n"[j == adj[i].size() - 1];
	}
}
int main()
{
	int n, m, i, j, w, x, y; //n=node,m=edge,w=weight;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> x >> y >> w;
		adj[x].push_back(y);//x er adjacent y;
		adj[y].push_back(x);
		weight[x].push_back(w);//x er adj weight w
		weight[y].push_back(w);
	}
	cout << "The Adjacency List are given below:" << endl;
	PrintList(n);
	return 0;
}