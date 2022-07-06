// problem link : https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/


class Solution {
public:
    
    // great LIS question 
    // optimized second loop using hashing 
    //DP + HASHING
    
    int longestSubsequence(vector<int>& arr, int d) {
        
        int n = arr.size();
        
        vector<int> dp(n, 1);
        int res = 1;
        map<int, int> m;
        m[arr[0]] = 1;
        for(int i=1;i<n;i++){
            // int mx = 0;
            // for(int j=0;j<i;j++){
            //     if(arr[j]+d == arr[i] && 1 + dp[j] > dp[i]){
            //         // cout<<i<<" "<<j<<endl;
            //         dp[i] = 1 + dp[j];
            //     }
            // }
            // res = max(res, dp[i]);
            
            if(m.find(arr[i]) == m.end()){
                if(m.find(arr[i]-d) == m.end()){
                    dp[i] = 1;
                    m[arr[i]] = 1;
                }
                else{
                    dp[i] = 1 + m[arr[i]-d];
                    m[arr[i]] = 1;
                    m[arr[i]] += m[arr[i]-d];
                }
            }
            else{
                if(m.find(arr[i]-d) == m.end()){
                    dp[i] = 1;
                }
                else{
                    dp[i] = 1 + m[arr[i]-d];
                    if(1 + m[arr[i]-d] > m[arr[i]]){
                        m[arr[i]] = 1 + m[arr[i] - d];
                    }
                }
                
            }
            
            
            res = max(res, dp[i]);
            
            
        }
        
        
        // for(auto it : dp){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        
        return res;
        
        
        
    }
};
