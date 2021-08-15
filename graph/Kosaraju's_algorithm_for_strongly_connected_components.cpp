#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vint vector<int>
#define pb push_back

//Kosaraju's algorithum for strongly connected components

// step 1 : sort all nodes in values of finsing time --> topological sort

// setp 2 : transpose tha graph 

// setp 3 : DFS according to finising time


void dfs(int node, stack<int> &st, vint &vis, vint adj[])//topological sort
{
	vis[node] = 1;
	for(auto it : adj[node])
	{
		if(!vis[it])
		{
			dfs(it, st, vis, adj);
		}
	}


	st.push(node);

}

void revdfs(int node, vint &vis, vint transpose[])// DFS according to finishing time
{
	cout<<node<<" ";
	vis[node] = 1;
	for(auto it : transpose[node])
	{
		if(!vis[it])
		{
			revdfs(it, vis, transpose);
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

	vector<int> adj[n];

	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;

		adj[u].pb(v);
	}

	stack<int> st;

	vector<int> vis(n, 0);

	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i, st, vis, adj);
		}
	}

	vint transpose[n];

	for(int i=0;i<n;i++)// transpose of the graph 
	{
		vis[i] = 0;

		for(auto it : adj[i])
		{
			transpose[it].pb(i);
		}
	}


	while(!st.empty())
	{
		int node = st.top();
		st.pop();

		if(!vis[node])
		{
			cout<<"SCC: ";
			revdfs(node, vis, transpose);
			cout<<endl;

		}

	}

	return 0;


	
		










}
