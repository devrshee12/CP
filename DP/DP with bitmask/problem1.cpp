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

// DP WITH BITMASKING


// problem statement
// Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring 
// some cost that may vary depending on the work-job assignment. It is required to perform all 
// jobs by assigning exactly one worker to each job and exactly one job to each agent in such a
// way that the total cost of the assignment is minimized.
//input
// Number of workers and job: N
// Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.
// sample input
// 1
// 4
// 9 2 7 8
// 6 4 3 7
// 5 8 1 8
// 7 6 9 4
// output
// 13
// Constraints
// N <= 20







int dp[21][(1<<21)];

int solve(int ind, int mask, int &n, vector<vector<int>> arr){


    if(ind == n){
        return 0;
    }

    if(dp[ind][mask] != -1)return dp[ind][mask];


    int ans = INT_MAX;
    for(int j=0;j<n;j++){
        if(mask&(1<<j)){
            ans = min(ans, arr[ind][j] + solve(ind+1, (mask^(1<<j)), n, arr));
        }
    }



    return dp[ind][mask] = ans;


}



    









void solve()
{
    //write your code here
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout<<solve(0, (1<<n) - 1, n, arr)<<endl;
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
