#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>

int seg[4*100005],lazy[4*100005];

// lazy propogation in segment tree
// use case : range update queries 
// if we dont use lazy propogation range update queies casts nlogn
// using  lazy propogation we can do that in logn only



void build(int ind, int low, int high)
{
	if(low == high)
	{
		seg[ind] = a[ind];
		return;
	}

	int mid = low + (high- low)/2;
	build(2*ind+1, low, mid);
	build(2*ind+2, mid+1, high);

	seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];

}

void update(int ind, int low, int high, int l, int r, int val)
{
	//i am reaching a node in segment tree with index and a range low - high
	//so i will make sure if there are any updates remainning, we will make sure we do
	//that first and than propogate it downwords

	//number of nodes for which the updates will be remaining will be (high-low + 1)
	if(lazy[ind] != 0)
	{
		seg[ind] += (high-low+1)*lazy[ind];

		//once updated current index, that means update done for current node;
		//so lets propogate the update downwords to its chindren, so that someone else
		//goes to them he can update them afterwords

		//low != high meand it's not the leaf node and it has nodes downwords
		if(low != high)
		{
			lazy[2*ind+1] = lazy[ind];
			lazy[2*ind+2] = lazy[ind];
		}

		//once propogated , i can say updates are done, lets make it 0;
		lazy[ind] = 0;
	}

	//no overlap
	//low high l r OR l r low high
	if(l > high || low >r)
	{
		return;
	}

	//complete overlap
	//l low high r;
	if(low>=l && high<=r)
	{
		seg[ind] += val*(high-low+1);

		if(low != high)
		{
			lazy[2*ind + 1] += val;
			lazy[2*ind + 2] += val;
		}
		return;
	}

	//partial overlap
	int mid = low + (high - low)/2;
	update(2*ind+1, low, mid, l, r, val);
	update(2*ind+2, mid+1, high, l, r, val);


	//while come back i will add bottom nodes as the nodes would have been updated
	seg[ind] = seg[2*ind+1] + seg[2*ind+2];




}

int rangesum(int ind, int low, int high, int l, int r)
{
	//i am reaching a node in segment tree with index and a range low - high
	//so i will make sure if there are any updates remainning, we will make sure we do
	//that first and than propogate it downwords

	//number of nodes for which the updates will be remaining will be (high-low + 1)
	if(lazy[ind] != 0)
	{
		seg[ind] += (high-low+1)*lazy[ind];

		//once updated current index, that means update done for current node;
		//so lets propogate the update downwords to its chindren, so that someone else
		//goes to them he can update them afterwords

		//low != high meand it's not the leaf node and it has nodes downwords
		if(low != high)
		{
			lazy[2*ind+1] = lazy[ind];
			lazy[2*ind+2] = lazy[ind];
		}

		//once propogated , i can say updates are done, lets make it 0;
		lazy[ind] = 0;
	}

	//no overlap 
	if(l > high || low > r)
	{
		return 0;//for rangesum queries
	}	

	//complete overlap

	if(l>=low && high<=r)
	{
		return seg[ind];
	}

	//partial overlap 

	int mid = low + (high-low)/2;
	int left = rangesum(2*ind+1, low, mid, l, r);
	int right = rangesum(2*ind+2, mid+1, high, l, r);

	return left+right;

}
