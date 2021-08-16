#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vint vector<int>
#define pb push_back


//prim's algorithm to find MST in given graph

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,m;
	cin>>n>>m;

	vector<pair<int, int>> adj[n];

	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;

		adj[u].pb(make_pair(v, wt));
		adj[v].pb(make_pair(u, wt));

	}	

		int parent[n];	
		int key[n];

		bool mstset[n];

		for(int i=0;i<n;i++)
		{
			key[i] = INT_MAX;
			mstset[i] = false;
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		key[0] = 0;
		parent[0] = -1;
		pq.push({0, 0});// {key, index}

		while(!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();

			mstset[u] = true;

			for(auto it : adj[u])
			{
				int v = it.first;
				int weight = it.second;

				if(mstset[v] == false && weight < key[v])
				{
					parent[v] = u;
					key[v] = weight;
					pq.push({key[v], v});
				}
			}
		}

		for(int i=1;i<n;i++)
		{
			cout<<parent[i]<<" - "<<i<<"\n";
		}


		return 0;



	
		










}
