#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>
ll a[200005],seg[4*200005];

//problem link :https://cses.fi/problemset/task/1650

void build(ll ind, ll low, ll high)
{
	if(low == high)
	{
		seg[ind] = a[low];
		return;
	}

	ll mid = low + (high - low)/2;
	build(2*ind+1, low, mid);
	build(2*ind+2, mid+1, high);
	seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
} 


int xorquery(ll ind, ll low, ll high, ll l, ll r)
{
	if(l > high || low > r)//condition for no overlap
	{
		return 0;
	}

	if(low>=l && high<=r)//condition for compelete overlap
	{
		return seg[ind];
	}

	//partial overlap 

	ll mid = low + (high - low)/2;
	ll left = xorquery(2*ind+1, low, mid, l, r);
	ll right = xorquery(2*ind+2, mid+1, high, l, r);

	return left ^ right;
}


int main()
{
	ll n,q;
	cin>>n>>q;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	build(0, 0, n-1);
	while(q--)
	{
		ll l,r;
		cin>>l>>r;//1 base indexing

		cout<<xorquery(0, 0, n-1, l-1, r-1)<<endl;
	}
}
