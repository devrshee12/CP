#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>
#define mod 1000000007

//problem link : https://cses.fi/problemset/task/1674

//find children count of a node
vint adj[200001];
void dfs(int node, int par, vint &ans)
{
    int sum = 0;
 
    for(auto it : adj[node])
    {
        if(it != par)
        {
            dfs(it, node, ans);
            sum += ans[it];
        }
    }
 
    ans[node] = 1 + sum;
 
 
}
 
 
int main()
{
    ll n;
    cin>>n;
    vint ans(n+1);
 
    for(ll i=2;i<n+1;i++)
    {
        int x;
        cin>>x;
        adj[x].pb(i);
        adj[i].pb(x);
 
    }
 
    dfs(1, 0, ans);
    for(ll i=1;i<n+1;i++)
    {
        cout<<(ans[i]-1)<<" ";
    }
 
 
 
}
