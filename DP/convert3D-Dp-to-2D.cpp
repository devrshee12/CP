// problem link : https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

class Solution {
public:
    //reduce 3D DP to 2D DP
    vector<int> nums, multi;
    int n, m;
    int f(int left, int ind, vector<vector<int>> &dp){
        if(ind == m)return 0;
        
        if(dp[left][ind] != -1)return dp[left][ind];
        
        int mul = multi[ind];
        int right = n - 1 - ind + left;
        
        int op1 = mul*nums[left] + f(left + 1, ind + 1, dp);
        int op2 = mul*nums[right] + f(left, ind + 1, dp);
        
        
        return dp[left][ind] = max(op1, op2);
    
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        this->nums = nums;
        multi = multipliers;
        n = nums.size();
        m = multipliers.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        return f(0, 0, dp);
    }
};
