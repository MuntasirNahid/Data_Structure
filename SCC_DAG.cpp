//shafaet er blog..

#include<iostream>
#include<vector>
#include<stack>
#define sz 1000
using namespace std;

vector<int> adj[sz], radj[sz], nadj[sz], components[sz];//radj->reverse adjacent gula..(reverse raph er khetre)..nadj->dag er  new adjacent gula..
bool col[sz], vis[sz];
int group_id[sz];
stack<int>stk;

void DFS(int u)//finishing time onujayi node gulakey sort korar jonno...
{
    col[u] = true;//color true korey dilam u er...
    for (int i = 0; i<adj[u].size(); i++)
        if(!col[ adj[u][i] ])
            DFS(adj[u][i]);//adjacent gula colored na holey abar dfs calaboo..
    stk.push(u);//stack e push...shobceye boro finishing time wala ta top a thakbe...
}

void DFS2(int u, int group)//scc khujey ber korar jonno..
{
    components[group].push_back(u);//u ke oi comoponent er oi group er under a push korey dilam...
    group_id[u] = group;//u er group id takey group korey dilam...
    vis[u] = true;//u ke visited korey dilam...
    for (int i = 0; i<radj[u].size(); i++)//reverse graph er khetre...kono component a normal graph a na jawa geley reverse graph e jawa jay...
        if(!vis[ radj[u][i] ])
            DFS2(radj[u][i], group);//ekoi comoponent er moddhe tai group same e thake...
}

int findSCC(int n)
{
    int mark=0, u;
    for (int i = 0; i<n; i++)
        if(!col[i])//col ==0 mane ekhno color kora hoy nai...
            DFS(i);//dfs e pathalam...finishing time inujayi node sort korar jonno

    while(!stk.empty())
    {
        u = stk.top();
        stk.pop();
        if(!vis[u])
            DFS2(u,mark++);//visited na holey dfs2 tey pathabo..scc khuje ber korar jonno..marl er man 1 baraya dilam jst for component alada korar jonno
    }
    return mark;//koyta component pailam shetay return..
}

void findDAG(int n)
{
    for (int i = 0; i<n; i++)
        for (int j = 0; j<adj[i].size(); j++)
            if(group_id[i] != group_id[ adj[i][j] ])
                nadj[ group_id[i] ].push_back( group_id[ adj[i][j] ] );
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;

    for (int i = 0; i<m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);//x er adjacent holo y..
        radj[y].push_back(x);//reverse graph er khetre adjacent...
    }

    m = findSCC(n);//scc khuje ber kora...(strongly connected component)

    cout << "Total Components in SCC = " << m << endl;

    for (int i = 0; i<m; i++)
    {
        cout << i <<":";
        for (int j = 0; j<components[i].size(); j++)
            cout << " " << components[i][j];
        cout << endl;
    }

    findDAG(n);//Dag koyta asey khuje ber kora...

    cout << "Total Node in DAG = " << m << endl;
    cout << "Adjacency List of the DAG:" << endl;

    for (int i = 0; i<m; i++)
    {
        cout << i <<":";
        for (int j = 0; j<nadj[i].size(); j++)//nadj[]holo dag er adjacent gula...
            cout << " " << nadj[i][j];
        cout << endl;
    }

    return 0;
}
/**
7 8
0 1
1 2
2 0
5 6
6 4
4 5
2 3
3 4

7 9
0 1
1 2
2 0
5 6
6 4
4 5
2 3
3 4
0 3
*/
