#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>
ll a[100005];
ll seg[4*100005];


// problem statement :

// Given an array arr[] of size N and a 2D array Q[][] consisting of queries of the following two types:

// 1 X Y: Update the array element at index X with Y.
// 2 K: Print the position of the first array element greater than or equal to K. If there is no such index, then print -1.


ll mini(ll a, ll b)
{
	if(a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}



void build(ll ind, ll low, ll high)//range maximum
{
	//build segment tree same as range maximum query;
	if(low == high)
	{
		seg[ind] = a[low];
		return;
	}

	ll mid = low + (high - low)/2;
	build(2*ind+1, low, mid);
	build(2*ind+2, mid+1, high);

	seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
}

void update(ll ind, ll low, ll high, ll i, ll val)
{

	// create update function same as we did in range maximum query
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

	seg[ind] = max(seg[2*ind + 1] , seg[2*ind + 2]);
}


int minimumindex(ll ind, ll low, ll high, ll k)
{

	// if current seg[ind] value is less than given k than  we wont be finding our required ans
	if(seg[ind] < k)
	{
		return 1e9;
	}

	// when we are on leaf node we check that our seg[ind] value is greter than or equal to given k value or not
	// if its not than we didnt find required answer
	if(low == high)
	{
		if(seg[ind] >= k)
		{
			return low;
		}

		return 1e9;
	}

	//when  we sure that our root node value is greter than given k 
	//than  we should find that which index we will find our answer
	//for that we call function first to left ans if we dont find answer
	//than we will call function to right


	ll mid = low + (high - low)/2;
	ll l = 1e9;

	if(seg[2*ind+1] >= k)
	{
		l = mini(l, minimumindex(2*ind+1, low, mid, k));
	}


	if(l == 1e9 && seg[2*ind+2] >= k)
	{
		l = mini(l, minimumindex(2*ind+2, mid+1, high, k));
	}

	return l;



}




int main()
{
	ll n,q;
	cin>>n;
	cin>>q;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}

	build(0, 0, n-1);

	while(q--)
	{
		// type-1 --> update given index to given value (type, index, value)
		// type-2 --> get index which is greater than or equal to given K  (type, k)
		ll type;
		cin>>type;
		if(type == 1)
		{
			ll index;cin>>index;
			ll val;cin>>val;
			update(0, 0, n-1, index-1, val);
		}
		else
		{
			ll k;cin>>k;
			ll temp = minimumindex(0, 0, n-1, k);
			if(temp < n)
			{
				cout<<temp<<endl;
			}
			else
			{
				cout<<"-1"<<endl;
			}
		}

	}

}
