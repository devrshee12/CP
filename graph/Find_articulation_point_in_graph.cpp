#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vint vector<int>
#define pb push_back


//find articulation point in the graph
void dfs(int node, int parent, vector<int> &vis, vint &tin, vint &low, int &timer, vint adj[], vint &isarticulation)
{
	vis[node] = 1;
	tin[node] = low[node] = timer;
	timer++;

	int child = 0;// for source node 
	for(auto it : adj[node])
	{
		if(it == parent)
		{
			continue;
		}


		if(!vis[it])
		{
			dfs(it, node, vis, tin, low, timer, adj, isarticulation);

			low[node] = min(low[node], low[it]);
			child++;
			if(low[it] >= tin[node] && parent != -1)
			{
				isarticulation[node] = 1;

			}

		}
		else
		{
			low[node] = min(low[node], tin[it]);

		}
		
	}
	
	if(parent == -1 && child > 1)//only case for source
	{
		isarticulation[node] = 1;
		
	}
	
}




int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	int n,m;
	cin>>n>>m;

	vector<int> adj[n+1];

	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;

		adj[u].pb(v);
		adj[v].pb(u);
	}

	vector<int> tin(n+1, -1);
	vector<int> low(n+1, -1);
	vector<int> vis(n+1, 0);
	vector<int> isarticulation(n+1, 0);

	int timer = 0;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i, -1, vis, tin, low, timer, adj, isarticulation);
		}
	}

	for(int i=1;i<=n;i++)
	{
		if(isarticulation[i])
		{
			cout<<i<<" ";
		}
	}

	return 0;










}
