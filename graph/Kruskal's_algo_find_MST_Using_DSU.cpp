#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vint vector<int>
#define pb push_back


//kruskal's algorithm to find MST in given graph using Disjoint set union 
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

bool comp(node a, node b)
{
	return a.wt < b.wt;
}


int findpar(int u, vint &parent)
{
	if(u == parent[u])
	{
		return u;
	}

	return parent[u] = findpar(parent[u], parent);
}


void unionn(int u, int v, vint &parent, vint &rank)
{
	u = findpar(u, parent);
	v = findpar(v, parent);

	if(rank[u] < rank[v])
	{
		parent[u] = v;
	}
	else if(rank[v] < rank[u])
	{	
		parent[v] = u;
	}
	else
	{
		parent[v] = u;
		rank[u]++;

		// or
		// parent[u] = v;
		// rank[v]++;
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

	vector<node> edges;
	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		edges.pb(node(u, v, wt));

	}

	sort(edges.begin(), edges.end(), comp);

	vint parent(n);

	for(int i=0;i<n;i++)
	{
		parent[i] = i;
	}

	vint rank(n, 0);
	int cost = 0;
	vector<pair<int, int>> mst;

	for(auto it : edges)
	{
		if(findpar(it.v, parent) != findpar(it.u, parent))
		{
			cost += it.wt;
			mst.pb({it.u, it.v});
			unionn(it.u, it.v, parent, rank);
		}
	}


	cout<<cost<<endl;

	for(auto it : mst)
	{
		cout<<it.first<<" - "<<it.second<<endl;
	}

	


	
		










}
