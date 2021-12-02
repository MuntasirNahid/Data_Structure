#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi acos(-1)
#define INF 1e18
#define MN7 ios::sync_with_stdio(0);cin.tie(nullptr);
#define MOD 1000000007
#define popb pop_back()
#define popf pop_front()
#define revers(x) reverse(x.begin(),x.end())
using namespace std;
ll t, n, i, j, k, a, b, u, v, w, d, p, q, r, x, y, z, m, cnt, flag, ans;
string s, s1, s2;
struct node
{
	int next, weight;
	node(int a, int b)
	{
		next = a;
		weight = b;
	}
};
void nahid()
{
	vector<node>adj[7];
	cin >> n;
	while (n--)
	{
		cin >> u >> v >> w;
		adj[u].pb(node(v, w)); //u er adjacent hocche v and edge er weight=w;
		adj[v].pb(node(u, w)); //for bidirectional or undirectional graph;
	}
	for (i = 1; i < 7; i++)
	{	cout << i << ":";
		for (j = 0; j < adj[i].size(); j++)
		{
			cout << "(" << adj[i][j].next << "," << adj[i][j].weight << ")" << ",\n"[j == adj[i].size() - 1];
		}
	}

}
int main()
{	MN7 //cin>>t;while(t--)
	nahid();
}
/*
5
1 2 10
1 3 5
2 4 4
3 5 3
5 6 2
*/
