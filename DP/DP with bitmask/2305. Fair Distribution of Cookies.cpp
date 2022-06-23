// problem link : https://leetcode.com/problems/fair-distribution-of-cookies/




class Solution {
public:
    
    
    int dp[15][1000];
    // DP with bitmask GOOD question 
    
    int f(int ind, int mask, vector<int> &sum, int n, int k){
        
        if(ind == k){
            if(mask == ((1<<n)-1))return 0;
            else return 1e9;
        }
        
        if(dp[ind][mask] != -1)return dp[ind][mask];
        
        
        int ans = 1e9;
        //iterate over all permutaion and calculate valid answer according to question 
        for(int new_mask=0;new_mask < (1<<n);new_mask++){
            
            if((new_mask & mask) == 0){//this will check whether this permutation is availeble or not
                ans = min(ans, max(sum[new_mask], f(ind+1, new_mask | mask, sum, n, k)));
            }
        }
        
        
        return dp[ind][mask] = ans;
        
        
        
    }

    int distributeCookies(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> sum((1<<n), 0);
        
        // sum[i] = sum of elements present in set with mask as i
        // This is required so we can give the sum of elements of a certain 
        // mask in constant amount of time
        
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if(i&(1 << j)){
                    sum[i] += arr[j];
                }
            }
        }
        
        memset(dp, -1, sizeof dp);
        
        
        return f(0, 0, sum, n, k);
        
        
        
        
    }
};
