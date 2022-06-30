// problem link : https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        
        int maxi =  INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int prev = 0; prev < i; prev++){
                if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    //inherit 
                    cnt[i] = cnt[prev];
                }
                else if(arr[prev] < arr[i] && 1 + dp[prev] == dp[i]){
                    //increase the count 
                    cnt[i] += cnt[prev];
                }
            }
            
            maxi = max(maxi, dp[i]);
        }
        
        // for(auto it : dp)cout<<it<<" ";
        // cout<<endl;
        // for(auto it : cnt)cout<<it<<" ";
        // cout<<endl;
        
        
        int no_of_lis = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi)no_of_lis += cnt[i];
        }
        
        
        return no_of_lis;
        
        
        
        
    }
};
