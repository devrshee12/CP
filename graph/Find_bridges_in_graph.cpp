#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vint vector<int>
#define pb push_back


//find bridges in the graph

void dfs(int node, int parent, vector<int> &vis, vint &tin, vint &low, int &timer, vint adj[])
{
	vis[node] = 1;
	tin[node] = low[node] = timer++;

	for(auto it : adj[node])
	{
		if(it == parent)continue;

		if(!vis[it])
		{
			dfs(it, node, vis, tin, low, timer, adj);
			low[node] = min(low[node], low[it]);
			if(low[it] > tin[node])
			{
				cout<<node<<" "<<it<<endl;
			}
		}
		else
		{
			low[node] = min(low[node], tin[it]);
		}

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

	int timer = 0;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i, -1, vis, tin, low, timer, adj);
		}
	}

	return 0;










}
