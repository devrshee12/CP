#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>
ll a[100005];
ll seg[4*100005];

//problem link : https://www.geeksforgeeks.org/queries-to-count-array-elements-from-a-given-range-having-a-single-set-bit-2/

// problem statement :

// Given an array arr[] consisting of N integers and a 2D array Q[][] consisting of queries of the following two types:

// 1 L R: Print the count of numbers from the range [L, R] having only a single set bit.
// 2 X V: Update the array element at Xth index with V.


bool check(ll n)// the number which is power of 2 that only has 1 bit set
{
	if(n == 0)
	{
		return 0;
	}
	return !( n & (n-1));
}


void build(ll ind, ll low, ll high)
{
	
	if(low == high)
	{
		seg[ind] = check(a[low]);
		return;
	}

	ll mid = low + (high - low)/2;
	build(2*ind+1, low, mid);
	build(2*ind+2, mid+1, high);

	seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

void update(ll ind, ll low, ll high, ll i, ll val)
{

	
	if(low == high)
	{
		if(low == i)
		{
			a[i] = val;

			seg[ind] = check(val);
		} 
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

	seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}


int rangesum(ll ind, ll low, ll high, ll l, ll r)
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
	ll left = rangesum(2*ind+1, low, mid, l, r);
	ll right = rangesum(2*ind+2, mid+1, high, l, r);

	return left+right;
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
		ll type;
		cin>>type;
		if(type == 1)
		{
			ll l,r;
			cin>>l>>r;
			cout<<rangesum(0, 0, n-1, l-1, r-1)<<endl;
		}
		else
		{
			ll index;cin>>index;
			ll val;cin>>val;
			update(0, 0, n-1, index-1, val);
		}
	}	
}
