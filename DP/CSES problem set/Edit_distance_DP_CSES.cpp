#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// #define mod 1000000007
// CSES --> EDIT DISTANCE DP 
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
	string s1;
	cin>>s1;
	string s2;
	cin>>s2;
	vector<vector<ll>> dp(s1.size()+1,vector<ll>(s2.size()+1,0));

	dp[0][0] = 0;
	for(ll i=1;i<=s1.size();i++)
	{
		dp[i][0] = i;
	}

	for(ll i=1;i<=s2.size();i++)
	{
		dp[0][i] = i;
	}

	for(ll i=1;i<=s1.size();i++)
	{
		for(ll j=1;j<=s2.size();j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = 1+min(min(dp[i-1][j-1],dp[i][j-1]), dp[i-1][j]);
			}
		}
	}

	cout<<dp[s1.size()][s2.size()]<<endl;






	
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
