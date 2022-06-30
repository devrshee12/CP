// problem link : https://leetcode.com/problems/maximum-length-of-pair-chain/



class Solution {
public:
    int findLongestChain(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int mx = 1;
        
        vector<int> dp(n, 1);
        for(int i=0;i<n;i++){
            int r = arr[i][0];
            for(int prev = 0; prev < i; prev++){
                int l = arr[prev][1];
                if(l < r && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }
            
            mx = max(mx, dp[i]);
        }
        
        
        return mx;
        
        
        
    }
};
