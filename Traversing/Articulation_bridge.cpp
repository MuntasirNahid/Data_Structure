#include <iostream>
#include <vector>
#define sz 1000
using namespace std;

vector<int> adj[sz];
int d[sz], low[sz], time;
bool visited[sz];
vector< pair<int,int> > arti_bridge;

void find_articulation_bridge(int u, int par)
{
    low[u] = d[u] = ++time;
    visited[u] = true;
    int child = 0, v;
    for (int i = 0; i<adj[u].size(); i++)
    {
        v = adj[u][i];
        if(v == par)
            continue;
        if(visited[ v ])
            low[u] = min(low[u], d[v]);
        else
        {
            find_articulation_bridge(v,u);
            low[u] = min( low[u], low[v]);
            if(d[u] < low[v] && par!=-1)
                arti_bridge.push_back({u,v});
            child++;
        }

        if(d[v] == low[v] && par==-1)
            arti_bridge.push_back({u,v}); /// replace
    }
}


int main()
{
    int n, m, x, y;

    cin >> n >> m;

    for (int i = 0; i<m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    find_articulation_bridge(0,-1);

    cout << "Node\td[i]\tlow[i]" << endl;
    for (int i = 0; i<n; i++)
        cout << i << "\t \t" << d[i] << "\t \t" << low[i] << endl;

    cout << "Articulation Bridge = " << arti_bridge.size() << endl;

    cout << "Articulation Bridge List:" << endl;
    for (auto &k: arti_bridge)
            cout << k.first << " " << k.second << endl;

    return 0;
}


/*
Why d[u]<low[v]?
-
If discovery_time[U] is equal to low[V] it means that there is a path from V that goes back to U ( V in this case represents an adjacent node of U ),
or in other words we can just say that we found a cycle rooted in U. For articulation points if we remove U from the graph it will increase the number of 
connected components, but in the case of bridges if we remove the edge UV the number of connected components will remain the same.
For bridges we need to be sure that the edge UV is not involved in any cycle.
A way to be sure of this is just to check that low[V] is strictly greater than discovery_time[U]


*/
/**
7 7
0 1
0 2
2 3
3 4
3 5
5 6
6 2


7 8
0 1
0 2
2 3
3 4
3 5
5 6
6 2
1 2


9 11
0 1
0 2
2 3
3 4
3 5
5 6
6 2
1 2
0 7
8 1
0 8

*/
