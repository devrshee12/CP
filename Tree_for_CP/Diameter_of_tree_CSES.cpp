#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>

//problem link : https://cses.fi/problemset/task/1131


//find diameter of tree

vint adj[200001];

int diameter[200001];

int downpath[200001];



void solve_downpath(int node, int par)
{
	int bestchilddownpath = 0;
	bool leaf = 1;
	for(int child : adj[node])
	{
		if(child != par)
		{
			leaf = 0;
			solve_downpath(child, node);
			bestchilddownpath = max(bestchilddownpath, downpath[child]);
		}
	}
	if(leaf)
	{
		downpath[node] = 0;
	}
	else
	{
		downpath[node] = 1 + bestchilddownpath;
	}
}


void solve(int node, int par)
{
	int ans = 0;
	vint childdownpath;
	for(int child : adj[node])
	{
		if(child != par)
		{
			solve(child, node);
			childdownpath.pb(downpath[child]);
			ans = max(ans, diameter[child]);

		}
	}

	int numofchild = childdownpath.size();
	sort(childdownpath.begin(), childdownpath.end());
	if(numofchild == 0)
	{
		diameter[node] = 0;
	}
	else if(numofchild == 1)
	{
		diameter[node] = 1 + childdownpath[0];
	}
	else
	{
		diameter[node] = 2 + childdownpath[numofchild - 1] + childdownpath[numofchild - 2];

	}

	diameter[node] = max(diameter[node], ans);

}

int main()
{

	int n;
	cin>>n;

	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);

	}

	solve_downpath(1, 0);
	solve(1, 0);
	cout<<diameter[1]<<endl;

}
