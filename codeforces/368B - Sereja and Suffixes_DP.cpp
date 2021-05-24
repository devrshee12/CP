#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
// 368B - Sereja and Suffixes
void solve()
{
	ll n,m;
	cin>>n>>m;
	vector<int> arr(n);
	vector<int> dp(n,0);
	vector<int> t(100005,0);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int temp = 0;
	for(int i=n-1;i>=0;i--)
	{
		if(t[arr[i]] == 0)
		{
			temp++;
			dp[i] = temp;
			t[arr[i]]++;
		}

		else 
		{
			dp[i] = temp;
			t[arr[i]]++;
		}
	}

	// for(int i=0;i<n;i++)
	// {
	// 	cout<<dp[i]<<endl;
	// }

	while(m--)
	{
		ll q;
		cin>>q;
		cout<<dp[q-1]<<endl;
	}











	

	

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
