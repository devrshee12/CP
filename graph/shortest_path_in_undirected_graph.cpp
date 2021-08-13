#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vint vector<int>
#define pb push_back


void shortestpathforundirected(int src, int v, vector<int> adj[])//shortest distance in undirected graph
{
	vint dis(v, INT_MAX);

	queue<int> q;

	dis[src] = 0;
	q.push(src);

	while(!q.empty())
	{
		int node = q.front();
		q.pop();

		for(auto it : adj[node])
		{
			if(dis[node] + 1 < dis[it])
			{
				dis[it] = 1 + dis[node];
				q.push(it);
			}
		}
	}


	for(auto it : dis)
	{
		cout<<it<<" ";
	}

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	//write your code here
	int v,e,src;
	cin>>v>>e>>src;

	vector<int> adj[v];

	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;

		adj[u].pb(v);
		adj[v].pb(u);
	}

	

	shortestpathforundirected(src, v, adj);


	










}
