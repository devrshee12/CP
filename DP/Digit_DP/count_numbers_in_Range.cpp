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
#define printm(m)for(auto it : m){cout<<it.ff<<" "<<it.ss<<endl;}cout<<endl;
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
//make observations
//think in reverse direction

int dp[1001][181][2];
int f(string &s, int n, int x, bool tight){
    if(x < 0){
        return 0;
    }
    if(n == 0){
        return 0;
    }

    if(dp[n][x][tight] != -1){
        return dp[n][x][tight];
    }

    int ans = 0;
    int upper_bound = tight ? (s[s.length() - n] - '0' : 9);
    for(int dig = 0; dig <= ub; dig++ ){
        ans += f(s, n - 1, x - dig, (tight&(dig == ub)));
    }



    return dp[n][x][tight] = ans;
}




void solve(){
    // solve this problem of digit DP

    // you are given L and R and you have to count the number 
    // whose digit sum is equal to X 
    // range of L and R is 10^18

    string l,r;
    cin>>l>>r;
    int right = solve(r, r.size(), x, 1);
    int left = solve(l-1, l.size(), x, 1);
    
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
        // cout<<"for test case : "<<t<<endl;
        solve();
    }
    // solve();
} 
