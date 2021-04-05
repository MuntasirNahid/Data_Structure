/*
What is a Spanning Tree?
Given an undirected and connected graph , a spanning tree of the graph  is a tree that spans  (that is, it includes every vertex of ) and is a subgraph of  (every edge in the tree belongs to )

What is a Minimum Spanning Tree?
The cost of the spanning tree is the sum of the weights of all the edges in the tree. There can be many spanning trees. Minimum spanning tree is the spanning tree where the cost is minimum among all the spanning trees. There also can be many minimum spanning trees.
*/


//emon ekti subgraph jekhane main graph er shobgula node thakbey kinto kono cycle thakbey na.

//jei edge gula nibo oi edge gular sum joto hobey erceye komano ar possible hobey na..
//2 types of spanning tree is available.
//1)prims and 2)kruskal
//prims--> (expand the tree) 1 ta root theke shuru korey oitakey expand kortey thakey..
//kruskal-->(grows in forest .Then construct the tree) forest create hoy erpor egula jora lagtey lagtey ekta tree tey porinoto hoy..

//ultimatelty duitar result e same.

//cycle create hotey parbena
//priority queue tey insert kore kore (adjacent gula cycle hobena emon gula)pop(kaj sheshe).
//already connected gula ke connect kora jabey na

//every node er sathey connected node(adj node)jeta cycle create korey na(age thekey priority queue tey nai) oita priority queue tey add

//kruskal-->

//Kruskal er khtrey priority queue use kortey hobey not necessary.sort korey nilei hobey edge gula..tahole runtime priority queue er use kora lagtese na.

// sorted edge er adj node gulakey niye nibo(cycle hoyna emon)..taholey forest create hobey.

//already connected holey add korar dorkar nai



//prims--->
#include<iostream>
#include<vector>
#include<queue>
#define sz 1000
using namespace std;

vector<int>adj[sz], cost[sz];

priority_queue <  pair<int, pair<int, int> >,
               vector< pair<int, pair<int, int> > >,
               greater< pair<int, pair<int, int> > >
               > pq;//ascending order e sorted

int par[sz];
bool col[sz];

int find_par(int n)
{
	if (par[n] == n) //still untouched..
		return n;
	return par[n] = find_par(par[n]);
}

int mst_prims(int st)
{
	int p, q, w, total = 0, u, v;
	for (int i = 0; i < adj[st].size(); i++)
	{
		p = min(st, adj[st][i]); //kono node and eitar adj node er moddhe jeita min oitakey ekta var e nilam
		q = max(st, adj[st][i]);
		pq.push({cost[st][i], {p, q} });
	}
	col[st] = 1; //jetar adjacent gulakey niye nibo sheitakey amra color korey dibo.
	vector< pair<int, pair<int, int> > > ans;

	while (!pq.empty())
	{
		w = pq.top().first;
		p = pq.top().second.first;
		q = pq.top().second.second;
		pq.pop();

		u = find_par(p);//p er grand parent k ber korey niye ashbey.
		v = find_par(q);//q er grand parent k er korety niye ashbey.
		if (u != v) //grand parent same na that means ekoi component e nai
		{
			par[u] = v;//ektar grand parent k arektar grand parent korey dichi
			ans.push_back({ w, {p, q} });
			total += w;
			if (col[p] && col[q]) continue; //duiai colored(visited) holey continue korey dilam
			st = col[p] ? q : p; //p colored maney p er adj gula niye newa hoisey..st=ekhn kontakey traverse korbo
			col[st] = 1;
			for (int i = 0; i < adj[st].size(); i++)
			{
				p = min(st, adj[st][i]);
				q = max(st, adj[st][i]);
				pq.push({cost[st][i], {p, q} });
			}
		}

	}

	cout << "Edge List in MST (Prims):\n";

	for (auto &x : ans )
	{
		w = x.first;
		p = x.second.first;
		q = x.second.second;
		cout << "(" << p << "," << q << ") -> " << w << endl;
	}

	return total;
}


void mst_init(int n)
{
	for (int i = 0; i <= n; i++)
		par[i] = i, col[i] = 0;
}

int main()
{
	int n, m, x, y, z;

	cin >> n >> m;

	mst_init(n);

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		adj[x].push_back(y);
		adj[y].push_back(x);
		cost[x].push_back(z);
		cost[y].push_back(z);
	}
	z = mst_prims(1);
	cout << "Total Weight = " << z  << endl;

	return 0;
}




//kruskal-->
#include<iostream>
#include<vector>
#include<queue>
#define sz 1000
using namespace std;

vector<int>adj[sz], cost[sz];

priority_queue <  pair<int, pair<int, int> >,
               vector< pair<int, pair<int, int> > >,
               greater< pair<int, pair<int, int> > >
               > pq;

int par[sz];

int find_par(int n)
{
	if (par[n] == n)
		return n;
	return par[n] = find_par(par[n]);
}

int mst_kruskal(int n)
{
	int p, q, w, total = 0, u, v;
	for (int st = 0; st < n; st++)
		for (int i = 0; i < adj[st].size(); i++)
		{
			p = min(st, adj[st][i]);
			q = max(st, adj[st][i]);
			pq.push({cost[st][i], {p, q} });
		}

	vector< pair<int, pair<int, int> > > ans;

	while (!pq.empty())
	{
		w = pq.top().first;
		p = pq.top().second.first;
		q = pq.top().second.second;
		pq.pop();

		u = find_par(p);
		v = find_par(q);
		if (u != v)
		{
			par[u] = v;
			ans.push_back({ w, {p, q} });
			total += w;
		}

	}

	cout << "Edge List in MST (Kruskals):\n";

	for (auto &x : ans )
	{
		w = x.first;
		p = x.second.first;
		q = x.second.second;
		cout << "(" << p << "," << q << ") -> " << w << endl;
	}

	return total;
}


void mst_init(int n)
{
	for (int i = 0; i <= n; i++)
		par[i] = i;
}

int main()
{
	int n, m, x, y, z;

	cin >> n >> m;

	mst_init(n);

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		adj[x].push_back(y);
		adj[y].push_back(x);
		cost[x].push_back(z);
		cost[y].push_back(z);
	}
	z = mst_kruskal(n);
	cout << "Total Weight = " << z  << endl;

	return 0;
}


/**
6 9
1 2 2
1 5 1
1 4 1
2 3 3
2 5 2
3 5 1
3 6 5
4 6 2
5 6 3
*/
