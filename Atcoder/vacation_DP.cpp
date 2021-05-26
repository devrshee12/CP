#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
// Atcoder --> vaction problem 
void solve()
{
	ll n;
	cin>>n;
	vector<vector<ll>> dp(3,vector<ll>(n,0));
	ll a, b, c;
	cin>>a>>b>>c;
	dp[0][0] = a;
	dp[1][0] = b;
	dp[2][0] = c;
	for(ll i=1;i<=n-1;i++)
	{
		cin>>a>>b>>c;
		dp[0][i] = a + max(dp[1][i-1],dp[2][i-1]);
		dp[1][i] = b + max(dp[0][i-1],dp[2][i-1]);
		dp[2][i] = c + max(dp[1][i-1],dp[0][i-1]);
	}

	cout<<max({dp[0][n-1],dp[1][n-1],dp[2][n-1]})<<endl;








	
}





















	

	




int main()
{
	// ll t;
	// cin>>t;
	// while(t--)
	// {
		solve();


	// }

		
	
		
		
	
}
