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


int minStep(int n, int coins[], int t, int dp[]){
    if(n == 0)return 0;

    if(dp[n] != -1)return dp[n];

    int ans = INT_MAX;
    for(int i=0;i<t;i++){
        if(n-coins[i] >= 0){
            int subprob = minStep(n-coins[i], coins, t, dp);
            ans = min(ans, subprob+1);
        }
    }


    return dp[n] = ans;


}

int minStep1(int n, int coins[], int t){

    int dp[n+1] = {INT_MAX};
    dp[0] = 0;
    for(int i=1;i<=n;i++){

        for(int j=0;j<t;j++){
            if(i - coins[j] >= 0){
                dp[i] = min(dp[i], dp[i - coins[j]]);
            }
        }

        dp[i] += 1;
    }
 
}


int maxSum(int arr[], int n){
    int dp[1000] = {0};
    dp[i] = a[i]>0?a[i]:0;
    int maxSoFar = dp[0];
    for(int i=1;i<n;i++){
        dp[i] = dp[i-1] + a[i];
        if(dp[i] < 0){
            dp[i] = 0;
        }
        maxSoFar = max(maxSoFar, dp[i]);
    }

    return maxSoFar;
} 


int ladderProb(int n, int k, int dp[]){
    if(n == 0)return 1;

    if(dp[n] != -1){
        return dp[n];
    }

    int ways = 0;
    for(int i=1;i<=k;i++){
        if(n - i >= 0){
            ways += ladderProb(n-i, k, dp);
        }
    }


    return ways;


}

int ladderBottom(int n, int k){
    int dp[1000] = {0};
    dp[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i - j >= 0){
                dp[i] += dp[i - j];
            }
        }
    }

    return dp[n];

}

int rodCutting(int arr[], int n){

    if(n<= 0){
        return 0;
    }

    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        int cut = i + 1;
        int currAns = arr[i] + rodCutting(arr, n - cut);
        ans = max(ans, currAns);
    }

    return ans;
}

int rodCuttingDP(int arr[], int n){

    int dp[10000] = {0};

    dp[0] = 0;

    for(int i=1;i<=n;i++){

        int ans = INT_MIN;
        for(int j=0;j<i;i++){
            int cut = j + 1; 
            int curr_ans = price[j] + dp[i - cut];

            ans = max(ans, curr_ans);
        }

        dp[i] = ans;
    }

    return dp[n];

}


int lcs(string s1, string s2, int i, int j){
    if(i == s1.length() || j == s1.length()){
        return 0;
    }

    if(s[i] == s[j]){
        return 1 + lcs(s1, s2, i+1, j+1);
    }


    int op1 = lcs(s1, s2, i+1, j);
    int op2 = lcs(s1, s2, i, j+1);


    return max(op1, op2);

}

int optimalGame(int arr[], int i, int j, vector<vector<int>> dp){
    if(i > j){
        return 0;
    }


    if(dp[i][j] != -1)return dp[i][j];
    int op1 = arr[i] + min(optimalGame(arr, i+2, j), optimalGame(arr, i+1, j-1));
    int op2 = arr[j] + min(optimalGame(arr, i, j-2), optimalGame(arr, i+1, j-1));


    return dp[i][j] = max(op1, op2);
}

int dp[1000][1000];
memset(dp, -1, sizeof dp);
int  solveMixtures(int i, int j){//MCM pattern
    if(i >= j){
        return 0;
    }

    if(dp[i][j] != -1)return dp[i][j];


    dp[i][j] = INT_MAX;
    for(int k=i;k<=j;k++){
        dp[i][j] = min(dp[i][j], solveMixtures(i, k)+solveMixtures(k+1, j) + sum(i, k)*sum(k+1, j));

    }

    return dp[i][j];
}
   


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        // cout<<"Case #"<<i<<":";
        solve();
        // cout<<endl;
         
    }
    
    
    
}
