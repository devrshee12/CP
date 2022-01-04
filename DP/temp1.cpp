#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vint vector<int>
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ff first
#define ss second
#define printv(f) for(auto it : f){cout<<it<<" ";}cout<<endl;
#define all(arr) arr.begin(), arr.end()




int func(vint arr, int ind, int n){

    
    // cout<<"ind :"<<ind<<endl;
    // cout<<"size : "<<n<<endl;


    
    if(ind == n - 1){
        return 0;
    }
    

   
    int op1 = ind+1<n ? abs(arr[ind+1] - arr[ind]) + func(arr, ind+1, n) : INT_MAX;
    int op2 = ind+2<n ? abs(arr[ind+2] - arr[ind]) + func(arr, ind+2, n) : INT_MAX;

    // cout<<"op1 : "<<op1<<endl;
    // cout<<"op2 : "<<op2<<endl;
    
    return min(op1, op2);
    
    
}


int vacation(int ind, int prev, vector<vector<int>> dp){

    if(ind == n){
        return 0;
    }



    if(dp[ind][prev] != -1){
        return dp[ind][prev];
    }

    int cost = INT_MIN;
    if(prev == 0){
        cost = max(cost, a[0] + vacation(ind+1), 1, dp);
        cost = max(cost, b[1] + vacation(ind+1), 2, dp);
        cost = max(cost, c[2] + vacation(ind+1), 3, dp);

    }
    else if(prev == 1){
        cost = max(cost, b[1] + vacation(ind+1), 2, dp);
        cost = max(cost, c[2] + vacation(ind+1), 3, dp);

    }
    else if(prev == 2){
        cost = max(cost, a[0] + vacation(ind+1), 0, dp);
        cost = max(cost, c[2] + vacation(ind+1), 3, dp);

    }
    else if(prev == 3){
        cost = max(cost, a[0] + vacation(ind+1), 1, dp);
        cost = max(cost, b[1] + vacation(ind+1), 2, dp);

    }



    return dp[ind][prev] = cost;
}



int knapsack1(int ind, int w, vector<vector<int>> dp){
    if(ind == n){
        return 0;
    }

    if(dp[ind][w] != -1)return dp[ind][w];

    int cost = INT_MIN;

    if(wt[ind] <= w){
        cost = max(cost, val[ind] + knapsack1(ind+1, w - wt[ind]));
    }

    cost = max(cost, knapsack1(ind+1, w));


    return dp[ind][w] = cost;
}




int seqDivision(int arr[], int ind, int n, int k, int sum, vector<vector<int>> dp ){

    if(ind == n){
        if(sum%k == 0)return 1;
        else return 0;
    }

    if(dp[ind][sum] != -1)return dp[ind][sum];

    return dp[ind][sum] = seqDivision(arr, ind+1, n, k, (sum+arr[ind])%k, dp) + seqDivision(arr, ind+1, n, k, (sum)%k, dp);
}



int coinChange(int ind, int target){
    if(ind == n){
        if(target == 0)return 1;
        else return 0;

    }

    if(dp[ind][target] != -1)return dp[ind][target];

    //if we pick 
    int cnt = 0;
    if(arr[ind] <= target)
        cnt += coinChange(ind, target - arr[ind]);

    cnt += coinChange(ind+1, target);


    return dp[ind][target] = cnt;

}


int minCoins(int ind, int sum){
    if(ind == n){

        if(sum == 0)return 0;
        else return INT_MAX;


    }

    if(dp[ind][sum] != -1)return dp[ind][sum];

    int ans = INT_MAX;
    if(arr[ind] <= sum){
        ans = min(ans, 1 + minCoins(ind, sum - arr[ind]));
    }

    ans = min(ans, minCoins(ind+1, sum));

    return dp[ind][sum] = ans;
}



int dp[100005][5];
int paintHouse(int ind, int prev, vector<vector<int>> arr, int n){
    if(ind == n){
        return 0;
    }

    if(dp[ind][prev] != -1)return dp[ind][prev];



    int ans = INT_MAX;

    if(prev == 0){
        ans = min(ans, arr[ind][0] + paintHouse(ind+1, 1, arr, n));
        ans = min(ans, arr[ind][1] + paintHouse(ind+1, 2, arr, n));
        ans = min(ans, arr[ind][2] + paintHouse(ind+1, 3, arr, n));
    }

    if(prev == 1){

        ans = min(ans, arr[ind][1] + paintHouse(ind+1, 2, arr, n));
        ans = min(ans, arr[ind][2] + paintHouse(ind+1, 3, arr, n));

    }
    if(prev == 2){
        ans = min(ans, arr[ind][0] + paintHouse(ind+1, 1, arr, n));
        ans = min(ans, arr[ind][2] + paintHouse(ind+1, 3, arr, n));

    }

    if(prev == 3){
        ans = min(ans, arr[ind][0] + paintHouse(ind+1, 1, arr, n));
        ans = min(ans, arr[ind][1] + paintHouse(ind+1, 2, arr, n));

    }



    return dp[ind][prev] = ans;








}

void solve()
{
    //write your code here
    int n;
    cin>>n;

    vector<vector<int>> arr(n, vector<int>(3));

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }

    }

    memset(dp, -1, sizeof dp);


    cout<<paintHouse(0, 0, arr, n);


    
    
    
    
    
    
    
    
    
}

   


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    
    // int t;
    // cin>>t;
    
    // for(int i=1;i<=t;i++)
    // {
        // cout<<"Case #"<<i<<":";
        solve();
        // cout<<endl;
         
    // }
    
    
    
} 
