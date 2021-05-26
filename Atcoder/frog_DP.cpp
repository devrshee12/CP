#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
// Atcoder --> frog problem (k == 2 for frog 1 ans k for frog 2)
void solve()
{
	ll n,k;
	cin>>n>>k;
	vector<int> arr(n);
	vector<int> dp(n,INT_MAX);
 	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		
	}

	dp[0] = 0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i - j < 0)break;
			dp[i] = min(dp[i],dp[i-j] + abs(arr[i] - arr[i-j]));

		}
	}

	cout<<dp[n-1]<<endl;








	
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
