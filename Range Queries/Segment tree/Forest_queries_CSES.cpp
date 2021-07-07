#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>

// problem link : https://cses.fi/problemset/task/1652/
bool grid[1001][1001];
int dp[1001][1001];
 
void build_dp(int n, int m)
{
	dp[0][0] = dp[1][0] = dp[0][1] = 0;
 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j] = grid[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
}
 
int getdp(int n, int m)
{
	return dp[n][m];
}
 
 
int query(int x1, int y1, int x2, int y2)
{
	return getdp(x2, y2) - getdp(x2, y1-1) - getdp(x1-1, y2) + getdp(x1-1, y1-1);
}
 
 
int main()
{
	int n,q;
	cin>>n>>q;
 
 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char x;
			cin>>x;
			if(x == '*')
			{
				grid[i][j] = 1;
			}
			else
			{
				grid[i][j] = 0;
			}
		}
	}
	build_dp(n, n);
 
	while(q--)
	{
		int x1,y1;cin>>x1>>y1;
		int x2,y2;cin>>x2>>y2;
 
		cout<<query(x1, y1, x2, y2)<<endl;
	}
}
