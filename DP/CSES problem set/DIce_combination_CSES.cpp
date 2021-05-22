#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
//construct n by dice(CSES)dynamic programming 
void solve()
{
	ll n;
	cin>>n;
	vector<ll> dp(n+1,0);
	dp[0] = dp[1] = 1;
	for(ll i=2;i<=n;i++)
	{
		for(int j=1;j<=6;j++)
		{
			if(j > i) continue;
			dp[i] = (dp[i]%mod + dp[i-j]%mod)%mod;
		}
	}


	cout<<dp[n]%mod<<endl;

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
