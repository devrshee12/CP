#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// #define mod 1000000007
// CSES --> RECTANGLE CUTTING DP 
const int M=1e9+7;
long long mod(long long x){
        return ((x%M + M)%M);
    }
    
long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
void solve()
{
	ll a,b;
	cin>>a>>b;
	vector<vector<ll>> dp(a+1,vector<ll> (b+1,INT_MAX));

	for(ll i=0;i<=a;i++)
	{
		for(ll j=0;j<=b;j++)
		{
			if(i == j) dp[i][j] = 0;
			else
			{
				//vertical cut
				for(ll k=1;k<=i-1;k++)
				{
					dp[i][j] = min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
				}

				//horizontal cut
				for(ll k=1;k<=j-1;k++)
				{
					dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
				}


			}
		}
	}

	cout<<dp[a][b]<<endl;








	
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
