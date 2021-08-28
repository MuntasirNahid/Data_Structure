//SHAFAETblog theke  shikha....
#include <iostream>
#include <vector>
#define sz 1000
using namespace std;

vector<int> adj[sz];
int d[sz], low[sz], time;
bool arti_point[sz], visited[sz];

void find_articulation_point(int u, int par)
{
    low[u] = d[u] = ++time;//discovery time ar low ke time++ diye assign korey nilam...
    visited[u] = true;//u ke visited korey dilam...
    int child = 0, v;
    for (int i = 0; i<adj[u].size(); i++)//u er adjacent gula niye kahini..
    {
        v = adj[u][i];
        if(v == par)//u er v tomo adjacent ta parent hoye geley continue;
            continue;
        if(visited[ v ])//agei visited...maney backedge asey..
            low[u] = min(low[u], d[v]);//u er min ar backedge er discovery time er moddhe min ...
        else
        {
            find_articulation_point(v,u);//ebar v ke u ar u k parent korey dilam...
            low[u] = min( low[u], low[v]);//u and v ert low er moddhe min...
            if(d[u] <= low[v] && par!=-1)//root na...
                arti_point[u] = true;
            child++;//jst root er jonno eita..
        }

        if(child > 1 && par==-1)//root er khetree....child >1 hoitey hobey...
            arti_point[u] = true;
    }
}


int main()
{
    int n, m, x, y, cnt;

    cin >> n >> m;

    for (int i = 0; i<m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    find_articulation_point(0,-1);//1st a root pathalam...jar parent =-1;

    cout << "Node\td[i]\tlow[i]" << endl;
    for (int i = 0; i<n; i++)
        cout << i << "\t  \t" << d[i] << "\t  \t" << low[i] << endl;
    cnt = 0;
    for (int i = 0; i<n; i++)
        if(arti_point[i]) cnt++;
    cout << "Articulation Point = " << cnt << endl;//articulatio  point er shongkha...


    cout << "Articulation Point List:" << endl;
    for (int i = 0; i<n; i++)
        if(arti_point[i])
            cout << i << endl;

    return 0;
}
/**
7 7
0 1
0 2
2 3
3 4
3 5
5 6
6 2
*/
