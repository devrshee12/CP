#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
//Book shop(CSES)dynamic programming(0/1 knapsack) 
// int dp[1005][100005];
void solve()
{
	ll n,x;
	cin>>n>>x; 
	vector<int> prices(n+1);
	vector<int> pages(n+1);
	for(ll i=1;i<=n;i++)
	{
		cin>>prices[i];
	}
	for(ll i=1;i<=n;i++)
	{
		cin>>pages[i];
	}
	vector<vector<int>> dp(n+1,vector<int> (x+1 , 0));
	// for(ll i=0;i<n+1;i++)
	// {
	// 	for(ll j=0;j<n+1;j++)
	// 	{
	// 		if(i == 0 || j == 0)
	// 			dp[i][j] = 0;
	// 	}
	// }

	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=x;j++)
		{
			if(prices[i] > j)
			{ 
				dp[i][j] = dp[i-1][j];
			}
			else 
			{
				dp[i][j] = max(pages[i]+dp[i-1][j-prices[i]] , dp[i-1][j]);
			}
		}
	}

	cout<<dp[n][x]<<endl;

	

}



int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		solve();


	}

		
	
		
		
	
}
