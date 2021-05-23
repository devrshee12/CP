#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
//minimizing coins(CSES)dynamic programming 
void solve()
{
	ll n;
	cin>>n;
	vector<vector<int>> arr(n,vector<int>(n, 0 ));
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++)
		{
			char ch;
			cin>>ch;
			arr[i][j] = (ch == '.'?1:0);
		}
	}
	vector<vector<int>> dp(n, vector<int>(n,0));
	if(arr[n-1][n-1] == 1)dp[n-1][n-1] = 1;
	for(ll i= n-2;i>=0;i--)
	{
		if(arr[i][n-1] == 0)dp[i][n-1] = 0;
		else
		{
			dp[i][n-1] += dp[i+1][n-1];

		}
	}
	for(ll i= n-2;i>=0;i--)
	{
		if(arr[n-1][i] == 0)dp[n-1][i] = 0;
		else
		{
			dp[n-1][i] += dp[n-1][i+1];
			
		}
	}

	for(ll i=n-2;i>=0;i--)
	{
		for(ll j=n-2;j>=0;j--)
		{
			if(arr[i][j] == 0)dp[i][j] = 0;
			else
			{
				dp[i][j] += (dp[i+1][j]%mod + dp[i][j+1]%mod)%mod;
			}
		}

	}


	cout<<dp[0][0]<<endl;
	

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
