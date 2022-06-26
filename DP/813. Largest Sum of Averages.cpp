// problem link : https://leetcode.com/problems/largest-sum-of-averages/


class Solution {
public:
    // great dp question 
    
    

    
    
   double f(int ind, int k, vector<int> &arr, int n, vector<vector<double>> &dp){
       
      if(ind == n){
          return 0;
      }
    
        if(k == 0){
            return INT_MIN;
        }
       
       if(dp[ind][k] != -1.0000)return dp[ind][k];
       
       
       double ans = INT_MIN;
       double res = 0.00000;
       for(int i=ind;i<n;i++){
               res += (double)arr[i];
               // res /= (i-ind+1);
                
               ans = max(ans, (double)res/(i-ind+1) + f(i+1, k-1, arr, n, dp));
          
       }
       
       
       return dp[ind][k] = ans;
   }
    
    
    
    double largestSumOfAverages(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<double>> dp(105, vector<double>(105, -1));
        // memset(dp, -1.0000, sizeof dp);
        return f(0, k, arr, n, dp);
        
        
        
        
    
        
        
        
        
    }
};






