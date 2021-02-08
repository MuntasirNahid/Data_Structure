/* Your Love Makes Me STRONG,
   Your Hate Makes Me UNSTOPABBLE.

   HOPE is a good thing,maybe the BEST of things.
   And no GOOD Things EVER DIES.

   Keep calm,Be patient And Chase Your DREAM

*/
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
ll t, n, i, j, k, a, b, d, p, q, r, x, y, z, m, cnt, flag, ans, u, v, w;
string s, s1, s2;
void nahid()
{
	vector<pair<int, int> >adj[7];
	cin >> n;
	while (n--)
	{
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});

	}
	for (i = 1; i < 7; i++)
	{
		cout << i << ":";
		for (j = 0; j < adj[i].size(); j++)
		{
			cout << "(" << adj[i][j].first << "," << adj[i][j].second << ")" << ",\n"[j == adj[i].size() - 1];
		}
	}



}
int main()
{	MN7 //cin>>t;while(t--)
	nahid();
}
