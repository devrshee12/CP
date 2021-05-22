#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
//coin combination 2(CSES)dynamic programming 
void solve()
{
	ll n,x;
	cin>>n>>x;
	vector<ll> dp(x+1,0);
	dp[0] = 1;
	vector<ll> coins(n);
	for(ll i=0;i<n;i++)cin>>coins[i];

	for(ll i=0;i<=n;i++)
	{
		for(int j=1;j<=x;j++)
		{
			if(coins[i] > j) continue;
			dp[j] = (dp[j]%mod + dp[j-coins[i]]%mod)%mod;
		}
	}
 

	cout<<dp[x]%mod<<endl;

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
