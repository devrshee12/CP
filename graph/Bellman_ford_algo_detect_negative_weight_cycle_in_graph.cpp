#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vint vector<int>
#define pb push_back


//bellman ford algorithm for shortest path in negative edge weight
// and also it is used to find whether the graph has negative cycle or not

// step 1 : relax all edges for N-1 times and check dis[u] + wt < dis[v] if thats true dis[v] = dis[u] + wt;

// step 2 : relax for extra one time if any dis[i] satisfy dis[u] + wt < dis[v] then its negative cycle

// step 3 : dis array is our final answer to shortest distance

struct node
{
	int u;
	int v;
	int wt;
	node(int first, int second, int weight)	
	{
		u = first;
		v = second;
		wt = weight;

	}
};


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,m;
	cin>>n>>m;

	vector<node> edges;

	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;

		edges.pb(node(u, v, wt));
	}


	int src;
	cin>>src;

	int inf = 1e7;

	vector<int> dist(n, inf);

	dist[src] = 0;
	

	for(int i=1;i<=n-1;i++)
	{
		for(auto it : edges)
		{
			if(dist[it.u] + it.wt < dist[it.v])
			{
				dist[it.v] = dist[it.u] + it.wt;

			}
		}
	}

	bool flag = false;

	for(auto it : edges)
	{
		if(dist[it.u] + it.wt < dist[it.v])
		{
			cout<<"Negative cycle";
			flag = true;
			break;
		}

	}

	if(!flag)
	{
		for(int i=0;i<n;i++)
		{
			cout<<i<<" "<<dist[i]<<endl;
		}
	}


	return 0;

	
	
		










}
