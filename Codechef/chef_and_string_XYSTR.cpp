#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
// XYSTR --> Chef and String (codechef)
void solve()
{
	string s;
	cin>>s;
	int ans = 0;
	int i=0;
	while(i<s.length()-1)
	{
		if(s[i] == s[i+1])
		{
			i++;
		}
		else if(s[i] != s[i+1])
		{
			ans++;
			i+=2;
		}
	}

	cout<<ans<<endl;
	
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
