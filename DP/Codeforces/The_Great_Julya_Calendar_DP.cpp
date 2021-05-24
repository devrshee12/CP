#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
vector<int> digit(ll n)
{
	vector<int> ans;
	int temp = 0;
	while(n)
	{
		temp = n%10;
		if(temp != 0)
			ans.push_back(temp);
		n /= 10;
	}

	return ans;
}
void solve()
{
	ll n;
	cin>>n;
	if(n==0)
	{
		cout<<"0"<<endl;
		return;
	}
	else if(n<10)
	{
		cout<<"1"<<endl;
		return;
	}
	else{
		vector<int> dp(n+1);
		dp[0] = 0;
		for(int i=1;i<=9;i++)
		{
			dp[i] = 1;
		}

		for(int i=10;i<=n;i++)
		{
			vector<int> t = digit(i);
			int mi = INT_MAX;
			for(int j=0;j<t.size();j++)
			{

				mi = min(dp[i-t[j]],mi);
			}	

			dp[i] = mi + 1;
		}
		// for(int i=0;i<=n;i++)
		// {
		// 	cout<<dp[i]<<endl;
		// }

		cout<<dp[n]<<endl;
		return;



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
