#include<bits/stdc++.h>
using namespace std;
#define sz 1000
int adj[sz][sz];
void PrintMatrix(int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << adj[i][j] << " \n"[j == n - 1];


}
int main()
{
	int n, m, x, y, i, j, w; //n=node,m=edge,w=cost;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> x >> y >> w;
		adj[x][y] = w; //majher cost =w
		adj[y][x] = w;
	}
	cout << "The Adjacency Matrix are given below:" << endl;
	PrintMatrix(n);
	return 0;
}
/*
6 8
5 2 6
1 3 9
4 0 1
3 4 8
0 2 9
5 0 1
0 1 5
0 3 2
*/