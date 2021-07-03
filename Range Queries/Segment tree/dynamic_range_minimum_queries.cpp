#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>
ll a[200005],seg[4*200005];

//problem link : https://cses.fi/problemset/task/1649

//using segment tree


void build(ll ind, ll low, ll high)
{
	//leaf node
	if(low == high)
	{
		seg[ind] = a[low];
		return;
	}

	ll mid = low + (high - low)/2;
	build(2*ind + 1, low, mid);
	build(2*ind + 2, mid+1, high);
	seg[ind] = min(seg[2*ind + 1] , seg[2*ind + 2]);
}

void update(ll ind, ll low, ll high, ll i, ll val)
{
	if(low == high)
	{
		seg[ind] = val;
		a[i] = val;
		return;
	}

	ll mid = low + (high-low)/2;
	if(i<=mid)
	{
		update(2*ind + 1, low, mid, i, val);
	}
	else
	{
		update(2*ind + 2, mid+1, high, i, val);
	}

	seg[ind] = min(seg[2*ind + 1] , seg[2*ind + 2]);
}	

ll range(ll ind, ll low, ll high, ll l, ll r)
{
	//compelete overlap
	if(low >= l && high <= r){
		return seg[ind];
	}
	// no overlap
	else if(l > high || low > r)
	{
		return INT_MAX;
	}
	//for partial ovelap
	ll mid = low + (high - low)/2;
	ll left = range(2*ind + 1, low, mid,l,r);
	ll right = range(2*ind + 2, mid+1, high, l, r);

	return min(left, right);

}


int main()
{
	ll n;
	cin>>n;
	ll q;
	cin>>q;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}

	build(0,0,n-1);

	// for(int i=0;i<15;i++)
	// {
	// 	cout<<seg[i]<<endl;
	// }

	while(q--)
	{
		int type;
		cin>>type;

		if(type == 1)
		{
			ll i,val;
			cin>>i>>val;
			update(0, 0, n-1, i-1, val);
		}
		else
		{
			ll l,r;
			cin>>l>>r;
			cout<<range(0, 0, n-1, l-1, r-1)<<endl;
		}
	}

}
