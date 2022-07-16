#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define vint vector<int>
#define vi vector<ll>
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vi,greater<ll>>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define endl "\n"
#define ff first
#define ss second
#define printv(f) for(auto it : f){cout<<it<<" ";}cout<<endl;
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define all(arr) arr.begin(), arr.end()
#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

//think of small cases
//make small observations   

int parent[100005];
int size[100005];

int make(int v){
    //just make node 
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if(v == parent[v])return v;
    // path compression
    return parent[v] = find(parent[v]);
}

int Union(int a, int b){
    a = find(a);//finding parent so that we can connect thier parents
    b = find(b);
    if(a != b){// this means both node 
        if(size[a] < size[b]){
            // Union will be always on a <- b
            // size(a) should be greater than size(b)
            //if not swap
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}






void solve() {
    // finding connected componets using DSU
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        make(i);
    }

    while(k--){
        int u,v;
        cin>>u>>v;
        Union(u, v);
    }

    int connected_ct = 0;
    for(int i=1;i<=n;i++){
        if(find(i) == i)connected_ct++;
    }


    
}




int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin>>t;
   
     
    while(t--){
        solve();
    }


    // solve();
         
    
    
    
}
