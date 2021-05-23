#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
//minimizing coins(CSES)dynamic programming 
void solve()
{
	ll n,x;
	cin>>n>>x;
	vector<ll> dp(x+1,INT_MAX);
	dp[0] = 0;
	vector<ll> coins(n);
	for(ll i=0;i<n;i++)cin>>coins[i];

	for(ll i=1;i<=x;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(coins[j] > i) continue;
			dp[i] = min(dp[i],dp[i-coins[j]] + 1);
		}
	}
 	if(dp[x] == INT_MAX)cout<<"-1"<<endl;
	else cout<<dp[x]<<endl;

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
