#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vint vector<int>
#define pb push_back

//djisktra algorithm  --> to find shortest distance in undirected weighted graph





int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	//write your code here
	int v,e,src;
	cin>>v>>e>>src;

	vector<pair<int, int>> g[v+1];//1 based indexing 

	for(int i=0;i<e;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;

		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}


	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> >> pq;//min heap

	vint dis(v+1, INT_MAX);//1 based indexing
	dis[src] = 0;
	
	pq.push(make_pair(0, src));

	while(!pq.empty())
	{
		int dist = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for(auto it : g[node])
		{
			int next = it.first;
			int nextdis = it.second;

			if(dis[node] + nextdis < dis[next])
			{
				dis[next] = dis[node] + nextdis;
				pq.push(make_pair(dis[next], next));
			}
		}
	}



	for(auto it : dis)
	{
		cout<<it<<" ";
	}



	










}
