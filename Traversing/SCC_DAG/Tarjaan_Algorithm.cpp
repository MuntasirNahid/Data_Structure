/*
The low link value of a node is the smallest(lowest)node id reachable from that node when doing a dfs(including itself)

Same low link value belongs to the same scc

Low link values are highly dependent on the order  of dfs while exploring the nodes..This is a kind of flow in this case
with

To cope with the random traversal order of the DFS,Tarjan's algorithm maintains a set (often as a stack)
of valid nodes from which to update low-link values from


Nodes are added to the stack[set]of a valid nodes as they're explored for the first time

Nodes are removed from the stack[set]each time a complete SCC is found

On DFS callback ,if the previous node is on the stack then min the current node's low-link
value with the last node's low-link value

we will see a node started a connected component if it's id equals its low link value



*/

// Tarjaan ALgorithm

#include <bits/stdc++.h>
#define sz 1000
#define pb push_back
using namespace std;
vector<int> adj[sz];
int ids[sz], low[sz], sccs[sz];
bool visited[sz];
int sccCount, id;

void dfs(int at)
{
    ids[at] = low[at] = id++;
    stack<int> stk;
    stk.push(at);
    visited[at] = true; // stack er moddhe achey
    int to;
    for (int i = 0; i < adj[at].size(); i++)
    {
        to = adj[at][i];
        if (ids[to] == -1)
            dfs(to);
        if (visited[to]) // jodi adjacent ta age thekei stack e thakey
        {
            low[at] = min(low[at], low[to]);
        }
    }

    // On recursive callback, if we're at the root node (start of SCC)
    // empty the stack until back to root.
    if (ids[at] == low[at])
    {
        int node = stk.top();
        while (node != at)
        {
            visited[node] = false; // stack theke ber korey dilam
            sccs[node] = sccCount;
            stk.pop();
            node = stk.top();
        }
        sccCount++;
    }
}

void tarjaan_to_find_scc(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (ids[i] == -1)
        {
            dfs(i); // dfs on
        }
    }
}

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = false, ids[i] = -1;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y); // bi -direction graph
    }
    tarjaan_to_find_scc(n);
    cout << "Number of Strongly Connected Component's are=" << sccCount << endl;
}
//https://www.youtube.com/watch?v=wUgWX0nc4NY&ab_channel=WilliamFiset
