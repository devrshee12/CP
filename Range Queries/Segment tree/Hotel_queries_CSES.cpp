#include <bits/stdc++.h>
using namespace std;
// problem link : https://cses.fi/problemset/task/1143

 
struct Vertex{
  int value;
  int index;
};
const int MAXN=200011;
Vertex seg[4*MAXN];
#define INF -1e9+7;
 
// This generates a segment tree which can give me
// the maximum element in a range as well as the index of that element.
 
void build(int a[], int v, int tl, int tr){
 
    if(tl==tr){
        seg[v].value=a[tl];
        seg[v].index=tl+1;
        return;
    }
    int mid = (tl+tr)/2;
    build(a,2*v,tl,mid);
    build(a,2*v+1,mid+1,tr);
    if(seg[2*v].value >= seg[2*v+1].value){
       seg[v]=seg[2*v];
    }
    else{
       seg[v]=seg[2*v+1];
    }
}
 
int query(int v, int tl, int tr, int num){
 
     if(seg[v].value < num)
        return 0;
   
    if(tl==tr){
 
        seg[v].value = seg[v].value - num;
        return seg[v].index;
    }
 
 
   int mid = (tl+tr)/2;
 
   if(seg[2*v].value >= num){
      int idx = query(2*v,tl,mid,num);
      if(seg[2*v].value >= seg[2*v+1].value){
        seg[v] = seg[2*v];
      }
      else{
        seg[v]=seg[2*v+1];
      }
      return idx;
   }
   else{
      int idx= query(2*v+1,mid+1,tr,num);
       if(seg[2*v].value >= seg[2*v+1].value){
         seg[v]=seg[2*v];
      }
      else{
       seg[v]=seg[2*v+1];
      }
 
      return idx;
   }
 
   
 
}

int main(){
 
    int n,m;
    cin >> n >> m;
    int h[n],r[m];
    for(int i=0;i<n;i++)cin >> h[i];
    for(int i=0;i<m;i++)cin >> r[i];
    build(h,1,0,n-1);
 
    for(int i=0;i<m;i++)
    cout << query(1,0,n-1,r[i]) << " ";
 
}
