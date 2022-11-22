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



// problem link : https://www.spoj.com/problems/PR003004/

int cnt(string &r, int n, bool tight){
    if(tight == 0){
        return (pow(10, n) + 0.1);
    }
    if(n == 0){
        return 1;
    }

    int numbers =0 ;
    int ub = (r[r.size() - n] - '0');
    for(int dig=0;dig<=ub;dig++){
        numbers += cnt(r, n-1, tight & (dig == ub));
    }


    return numbers;
}


int f(string &r, int n, bool tight){
    if(n == 0){
        return 0;
    }

    itn ub = tight ? (r[r.size() - n] - '0') ? 9;
    for(int dig=0;dig <= ub; dig++ ){
        total += (dig * cnt(r, n-1, tight&(dig == ub)));
        total += f(r, n - 1, tight&(dig == ub));
    }


    return total;
}



void solve(){

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
