// C. Basketball Exercise
// problem link : https://codeforces.com/problemset/problem/1195/C

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



ll dp[100005][5];


ll f(ll ind, ll prev, vector<vector<ll>> &arr, ll n){
    
    
    if(ind == n){
        return 0;
    }
    
    
    
    if(dp[ind][prev + 1] != -1){
        return dp[ind][prev+1];
    }
    
    
    
    
    if(prev == -1){
        ll op1 = arr[0][ind] + f(ind + 1, 0, arr, n);
        ll op2 = arr[1][ind] + f(ind + 1, 1, arr, n);
        ll op3 = f(ind + 1, prev, arr, n);
        return dp[ind][prev+1] = max({op1, op2, op3});
    }
    else if(prev == 0){
        ll op1 = arr[1][ind] + f(ind + 1, 1, arr, n);
        ll op2 = f(ind + 1, prev, arr, n);
        return dp[ind][prev+1] = max(op1, op2);
    }
    else if(prev == 1){
        ll op1 = arr[0][ind] + f(ind + 1, 0, arr, n);
        ll op2 = f(ind + 1, prev, arr, n);
        return dp[ind][prev+1] = max(op1, op2);
    }
}












void solve()
{
    //write your code here
    ll n;
    cin>>n;
    vector<vector<ll>> arr(2, vector<ll>(n));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            // cout<<arr[i][j]<<" ";
        }
        // cout<<endl;
    }
    memset(dp, -1, sizeof dp);
    ll ans = f(0, -1, arr, n);
    cout<<ans<<endl;




    
   



    
    

}
   



int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    // int t;
    // cin>>t;
   


     
    // while(t--){
    //     solve();
    // }


    solve();
         
    
    
    
}
