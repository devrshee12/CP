#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vint vector<int>
#define pb push_back


void toposort(int node, stack<int> &st, vint &vis, vector<pair<int, int>> adj[])
{
	vis[node] = 1;

	for(auto it : adj[node])
	{
		if(!vis[it.first])
		{
			toposort(it.first, st, vis, adj);
		}
	}

	st.push(node);


}

void shortestpathindirected(int src, int n, vector<pair<int, int>> adj[])
{
	vint vis(n, 0);
	stack<int> st;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			toposort(i, st, vis, adj);
		}
	}

	vint dis(n, 1e9);

	dis[src] = 0;
	while(!st.empty())
	{
		int node = st.top();
		st.pop();

		if(dis[node] != 1e9)
		{
			for(auto it : adj[node])
			{
				if(dis[node] + it.second < dis[it.first])
				{
					dis[it.first] = dis[node] + it.second;
				}
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		(dis[i] == 1e9) ? cout<<"INF " : cout<<dis[i]<<" ";
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

	vector<pair<int, int>> adj[v];

	for(int i=0;i<e;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;

		adj[u].pb({v, w});
	}

	shortestpathindirected(src, v, adj);
	










}
