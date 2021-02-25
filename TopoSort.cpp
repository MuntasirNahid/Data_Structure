/* Your Love Makes Me STRONG,
   Your Hate Makes Me UNSTOPABBLE.
*/
//dependency er upor nirvor korey..
//impossible to do a toposort if there are any cycle..

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
#define sz 1000
using namespace std;
int t, n, i, j, k, a, b, d, p, q, r, x, y, z, m, cnt, flag, ans;
string s, s1, s2;
vector<int>adj[sz];
int indeg[sz];

vector<int>TopoSort(int n)
{
	queue<int>q;
	vector<int>res;
	for (i = 0; i < n; i++)
		if (indeg[i] == 0)q.push(i);
	if (q.empty())return res; //q empty holey res return korey dibo..
	//baki kaj assert korey nibe..mane ekhane kono order generate kora possible na..
	int x;
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		res.pb(x);
		for (i = 0; i < adj[x].size(); i++) //x theke kothay kothay jawa jay check..
		{
			if (--indeg[ adj[x][i] ] == 0)q.push(adj[x][i]); //x theke jegulay jawa jay shegular indeg "--"" korey dilam.
			//indeg =0 hoye gele shetakey q tey pyush korey dilam...
		}
	}
	return res;

}

void init(int n)//must for nultiple test cases
{
	for (i = 0; i < n; i++)
		indeg[i] = 0;
}

void nahid()
{
	cin >> n >> m; //n=node,m=edge;
	init(n);
	while (m--)
	{
		cin>>x>>y;
		adj[x].pb(y);
		indeg[y]++;
	}

	vector<int>sorted = TopoSort(n); //sorted vector..
	assert(sorted.size() == n); //condition ta true na holey ekta runtime error generate kore.known as
	//assertion error..condition true holey continue..

//alternative:
	if (sorted.size() == 0)cout << "Sorry!Toposort is impossible!" << endl;
	else
	{
		cout << "The Toposort of the graph is given below:  " << endl;
		for (i = 0; i < sorted.size(); i++)
			cout << sorted[i] << ",\n"[i == sorted.size() - 1];

	}
}
	int main()
	{	MN7 //cin >> t; while (t--)
			nahid();
	}
	/*
	8 14
	7 6
	0 2
	0 4
	4 1
	0 3
	3 6
	1 2
	1 3
	4 6
	2 3
	5 6
	5 2
	5 4
	7 5
	*/