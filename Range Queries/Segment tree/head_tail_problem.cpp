#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>
ll a[200005],seg[4*200005];

//problem : you have been given array in which 1 represent HEAD and
// 0 represent TAIL and you also have been given 2 types of queries
// 1 -> point update in which you have to flip the index e.g if you have 1 on index 2 ans you have been given this query so you change 1 to 0;
// 2 -> you have been given L and R you have to find how many HEADS in that range


//test case(1 base indexing)

//input :
// 9 3
// 0 1 1 0 0 1 1 0 0
// 2 2 6
// 1 4
// 2 2 7

// output : 
// 3
// 5




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
	seg[ind] = seg[2*ind+1] + seg[2*ind + 2];
}

void update(ll ind, ll low, ll high, ll i)
{
	if(low == high)
	{
		seg[ind] = !seg[ind];
		a[i] = !a[i];
		return;
	}

	ll mid = low + (high-low)/2;
	if(i<=mid)
	{
		update(2*ind + 1, low, mid, i);
	}
	else
	{
		update(2*ind + 2, mid+1, high, i);
	}

	seg[ind] = seg[2*ind+1] + seg[2*ind+2];
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
		return 0;
	}
	//for partial ovelap
	ll mid = low + (high - low)/2;
	ll left = range(2*ind + 1, low, mid,l,r);
	ll right = range(2*ind + 2, mid+1, high, l, r);

	return left+right;

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
	// ll q;
	// cin>>q;
	while(q--)
	{
		int type;
		cin>>type;

		if(type == 1)
		{
			ll i;
			cin>>i;
			update(0, 0, n-1, i-1);
		}
		else
		{
			ll l,r;
			cin>>l>>r;
			cout<<range(0, 0, n-1, l-1, r-1)<<endl;
		}
	}

}
