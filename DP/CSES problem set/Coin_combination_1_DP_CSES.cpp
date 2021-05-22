#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
//construct n by dice(CSES)dynamic programming 
void solve()
{
	ll n,x;
	cin>>n>>x;
	vector<ll> dp(x+1,0);
	dp[0] = 1;
	vector<ll> coins(n);
	for(ll i=0;i<n;i++)cin>>coins[i];

	for(ll i=1;i<=x;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(coins[j] > i) continue;
			dp[i] = (dp[i]%mod + dp[i-coins[j]]%mod)%mod;
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
