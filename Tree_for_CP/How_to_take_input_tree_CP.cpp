#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>
// TREE ALGO FOR CP
vint adj[100005];//global adjacency list for taking input
int subtree[100005];//global every index is for subtree count for the index node
int lev[100005];//global array where every index represent level of node
void bfs()
{
	queue<pair<int, int>> q;
	q.push({1,0});

	while(q.empty() == false)
	{
		auto it = q.front();
		q.pop();

		int node = it.first;
		int par = it.second;

		cout<<node<<" ";

		for(auto it : adj[node])
		{
			if(it != par)
			{
				q.push({it,node});
			}
		}
	}

	//TC = O(N)
	//SC = O(width)
}
int height;
void dfs(int node, int parent, int level = 1)//dfs with level of tree,height of tree, subtree count of the tree
{
	cout<<node<<" ";
	height = max(level,height);
	lev[node] = level;
	int sum = 0;
	for(auto it : adj[node])
	{
		if(it != parent)
		{
			dfs(it,node,level+1);
			sum += subtree[it];
		}
	}

	subtree[node] = 1 + sum;
	//TC O(N)

}





int main()
{
	int n;
	cin>>n;//taking input of number of nodes

	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;//taking input of edges
		adj[u].pb(v);
		adj[v].pb(u);
	}
	// bfs();
	// cout<<endl;
	dfs(1,0);
	// cout<<endl;
	// cout<<"levels : "<<" ";
	// for(int i=1;i<=9;i++)
	// {
	// 	cout<<lev[i]<<" ";
	// }
	// cout<<endl;
	// cout<<"subtree count : "<<" ";
	for(int i=1;i<=9;i++)
	{
		cout<<subtree[i]<<" ";
	}



}
