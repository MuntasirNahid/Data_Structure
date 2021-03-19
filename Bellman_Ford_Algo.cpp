//obohelito algorithm
//shafayet er blog


//shortest path ber korar algorithm.
//jekono ekta node k source dhorey oi node theke shob node a jawar shortest path ber kora jay.
/*
Given a graph and a source vertex src in graph, find shortest paths from src to all 
vertices in the given graph.
 The graph may contain negative weight edges.
*/
//BFS-failed when edges have different weight.
//Dijkstra-failed when negative cycle exist
//solution-->Bellman Ford algorithm

//edge er upor vitti kore kaj korey thaeky.
//n-1 times iteration korbo..node er value change.
//dis[u]+cos[u][v]<dis[v] holey dis[v]=dis[u]+cos[u][v];
//n-th bar iteration calanor shomoy kono update hobey na..but jodi update hoy tobe sekhane negetive cycle achey.

//jodi n tomo bare update hoy tobe flag rekhe beriye jabo.jeta dijkstra tey possible na.

//negetive cycle na thakley n-1 th bar iteration er por e minimum cost ashbey.
 
 //complexity 0(n*e)//node * edge 
//time complexity is more than dijkstra..ejonno obohelito.

#include <iostream>
#include <vector>
#include <algorithm>
#define inf (1<<29)
#define sz 1000
using namespace std;

vector<int> adj[sz], w[sz];

int par[sz], cost[sz];

int bellmanford(int st, int en, int n)
{
    cost[st] = 0;//start er cost 0 korey nilam..
    for (int k = 1; k<n; k++)//n-1 times iterartion colbey...
    {
        for (int i = 0; i<n; i++)
            for (int j = 0; j<adj[i].size(); j++)
                if(cost[i] + w[i][j] < cost[ adj[i][j] ])//u er nijer weight+ v tey jawar cost jodi v er weight theke kom hoy...
                {
                    cost[ adj[i][j] ] = cost[i] + w[i][j];
                    par[ adj[i][j] ] = i;//adj er parent i korey dilam....
                }
    }
    //n-1 times iteration shesh...ekhn abar iteration korey dkhbooo...jodi update hoy tar maney achey cycle... 

    for (int i = 0; i<n; i++)
        for (int j = 0; j<adj[i].size(); j++)
            if(cost[i] + w[i][j] < cost[ adj[i][j] ])
            {
                cout << "Shortest Path could not be determined." << endl;
                cout << "Negative Cycle Detected!" << endl;
                return -inf;
            }
    return cost[en];//total cost ta return....
}
void init(int n)
{
    for (int i = 0; i<n; i++)
        par[i]=-1, cost[i]=inf;
}

int main()
{
    int x, y, z, n, m, st, en;
    cin >> n >> m;
    init(n);//initialize kore nichi...
    for (int i  = 0; i<m;i++ )
    {
        cin >> x >> y >> z;
        adj[x].push_back(y);//directed graph tai ...
        w[x].push_back(z);//cost ta...
    }

    cin >> st >> en;//start and end...

    x = bellmanford(st,en, n);
    if(x==-inf) return 0;//cycle acheyy...
    cout << "The minimum path cost from " << st << " to " << en <<" is " << x << endl;
    x = en;
    vector<int>res;

    while(~x)//jotokkhon -1 na hoy...-1 er ~ = 0;means false
    {
        res.push_back(x);
        x = par[x];
    }
    reverse(res.begin(),res.end());
    cout<< "The path: ";
    for (int i = 0; i<res.size(); i++)
        cout << res[i] << ",\n"[i==res.size()-1];

    return 0;
}
/**
6 10
0 1 3
0 2 -2
0 4 8
2 3 6
1 2 1
1 5 4
1 4 6
4 5 -5
3 5 -5
3 1 9
0 5
output:
The minimum path cost from 0 to 5 is -1
The path: 0,2,3,5

input:

6 10
0 1 3
0 2 -2
0 4 8
2 3 6
1 2 1
1 5 4
1 4 6
4 5 -5
3 5 -5
3 1 -9
0 5

output:
Shortest Path could not be determined.
Negative Cycle Detected!
*/