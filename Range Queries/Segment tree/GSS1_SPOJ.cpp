#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>

// problem link : https://www.spoj.com/problems/GSS1/


struct node
{
    ll sum;
    ll pre;
    ll suff;
    ll maxsum;
};

node seg[4*50001];
ll a[50001];




void merge(ll index)
{
    seg[index].sum = seg[2*index+1].sum + seg[2*index+2].sum;
    seg[index].pre = max(seg[2*index+1].pre, seg[2*index+1].sum + seg[2*index+2].pre);
    seg[index].suff = max(seg[2*index+2].suff, seg[2*index+2].sum + seg[2*index+1].pre);
    seg[index].maxsum = max(max(seg[2*index+1].maxsum, seg[2*index+2].maxsum), seg[2*index+1].suff + seg[2*index+2].pre);

}

void build(ll ind, ll low, ll high)
{
    if(low == high)
    {
        seg[ind].sum = seg[ind].pre = seg[ind].suff = seg[ind].maxsum = a[low];
        return;
    }

    ll mid = low + (high - low)/2;
    build(2*ind+1, low, mid);
    build(2*ind+2 , mid+1, high);

    merge(ind);
}


node combination(node a, node b)
{
    node ans;
    ans.sum = a.sum + b.sum;
    ans.pre = max(a.pre, a.sum + b.pre);
    ans.suff = max(b.suff, b.sum + a.suff);
    ans.maxsum = max(max(a.maxsum, b.maxsum), a.suff + b.pre);

    return ans;

}


node query(ll ind, ll low, ll high, ll l, ll r)
{
    if(l > high || low > r)//condition for no overlap
    {
        node ans;
        ans.sum = ans.pre = ans.suff = ans.maxsum = 0;
        return ans;
    }

    if(low>=l && high<=r)//condition for compelete overlap
    {
        return seg[ind];
    }

    //partial overlap 

    ll mid = low + (high - low)/2;

    if(high <= mid)
    {
        return query(2*ind+1, low, mid, l, r);
    }
    if(l > mid)
    {
        return query(2*ind+2, mid+1, high, l, r);
    }
    
    node left = query(2*ind+1, low, mid, l, r);
    node right = query(2*ind+2, mid+1, high, l, r);

    return combination(left, right);
}




int main()
{
    ll n,q;
    cin>>n;

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    build(0, 0, n-1);
    cin>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<query(0, 0, n-1, l-1, r-1).maxsum<<endl;
    }

}
