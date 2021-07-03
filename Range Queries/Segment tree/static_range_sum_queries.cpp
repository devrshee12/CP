#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>
int a[100005],seg[4*100004];

//problem link : https://cses.fi/problemset/task/1646

//using segment tree
//we can do this using prefix sum

void build(int ind, int low, int high)
{
	//leaf node
	if(low == high)
	{
		seg[ind] = a[low];
		return;
	}

	int mid = (low+high) >> 1;
	build(2*ind + 1, low, mid);
	build(2*ind + 2, mid+1, high);
	seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];//sumation segment tree;

}

int range(int ind, int low, int high, int l, int r)
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
	int mid = (low+high) >> 1;
	int left = range(2*ind + 1, low, mid,l,r);
	int right = range(2*ind + 2, mid+1, high, l, r);

	return left+right;

}


int main()
{
	int n;
	cin>>n;
	int q;
	cin>>q;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	build(0,0,n-1);

	// for(int i=0;i<15;i++)
	// {
	// 	cout<<seg[i]<<endl;
	// }

	while(q--)
	{
		int l,r;
		cin>>l>>r;
		
		cout<<range(0,0,n-1,l-1,r-1)<<endl;
	}

}
