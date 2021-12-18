#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi acos(-1)
#define INF 1e18
#define MN7 ios::sync_with_stdio(0);cin.tie(nullptr);
#define MOD 1000000007
#define popb pop_back()
#define popf pop_front()
using namespace std;
ll t,n,i,j,k,a,b,c,d,p,q,r,x,y,z,m,cnt,ans;
bool flag;
string s,s2;
void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}


void dfs(ll src,ll par,ll col,vector<vector<ll> >&adj,vector<ll>&vis)
{
	vis[src]=col;
	for(auto x: adj[src])
	{
		if(vis[x]==-1)
		{
			dfs(x,src,3-col,adj,vis);
		}
		else
		{
			if(x!=par && vis[x]==col)
			{
				flag=true;
				break;
			}
		}
	}
}
void nahid()
{
	cin>>n>>m;
	flag=false;
	vector<vector<ll> >adj(n);
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	vector<ll>vis(n,-1);
	dfs(0,0,1,adj,vis);
	if(flag)
	cout<<"Not Bipartite"<<endl;
	else
		cout<<"Bipartite"<<endl;
    
 
}
int main()
{
   // init_code();
    MN7 
    // cin>>t;
    // while(t--)
    nahid();
}