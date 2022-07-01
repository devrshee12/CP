// problem link: https://leetcode.com/problems/partition-array-for-maximum-sum/


class Solution {
public:
    
    //front partition --> very important
    
    
    
    #define ll long long
    ll dp[505];
    ll f(int ind, int k, vector<int> &arr, int n){
        
        
        if(ind == n){
            return 0;
        }
        
        
        if(dp[ind] != -1)return dp[ind];
        
        ll res = INT_MIN;
        int mx = INT_MIN;
        int len = 0;
        for(int i=ind;i<min(n, ind+k);i++){
            len++;
            mx = max(mx, arr[i]);
            ll cost = len*mx + f(i + 1, k, arr, n);
            res = max(res, cost);
        }
        
        
        
        
        return dp[ind] = res;
        
        
    }
    
    
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // memset(dp, -1, sizeof dp);
        // return (int)f(0, k, arr, n);
        
        vector<int> dp(n+1, 0);
        
        for(int ind = n-1; ind >= 0; ind--){
            ll res = INT_MIN;
            int mx = INT_MIN;
            int len = 0;
            for(int i=ind;i<min(n, ind+k);i++){
                len++;
                mx = max(mx, arr[i]);
                ll cost = len*mx + dp[i + 1];
                res = max(res, cost);
            }
            
            
            dp[ind] = (int)res;
            
        }
        
        
        return dp[0];
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};
