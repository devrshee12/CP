#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
// #define mod 1000000007
// CSES --> MONEY SUMS DP 
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
	ll n;
	cin>>n;
	set<ll> ans;

	while(n--)
	{
		ll x;
		cin>>x;

		if(ans.size() == 0)
		{
			ans.insert(x);
			continue;
		}
		vector<ll> temp;
		for(auto it = ans.begin();it!=ans.end();it++)
		{	
			temp.pb(*it+x);

		}
		ans.insert(x);

		for(ll i=0;i<temp.size();i++)
		{
			ans.insert(temp[i]);
		}



	}

	cout<<ans.size()<<endl;
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		cout<<*it<<" ";
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
