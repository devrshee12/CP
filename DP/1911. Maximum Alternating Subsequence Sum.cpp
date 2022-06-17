//simple recursion 
class Solution {
public:
    
    int f(int ind, int flag, vector<int>& arr){
        
        
        if(ind < 0){
            return 0;
        }
        
        
        
        
        if(!flag){//if index is even
            int op1 = arr[ind] + f(ind - 1, !flag, arr);
            int op2 = f(ind - 1, flag, arr);
            
            return max(op1, op2);            
        }
        else{//if index is odd
            int op1 = -arr[ind] + f(ind - 1, !flag, arr);
            int op2 = f(ind - 1, flag, arr);
            return max(op1, op2);
        }
        
        
    }
    
 
        
    long long maxAlternatingSum(vector<int>& arr) {
        int n = arr.size();
        
        return f(n-1, 0, arr);
        
    }
};


// recursion with shifting of index
class Solution {
public:
    
    int f(int ind, int flag, vector<int>& arr){
        
        
        if(ind == 0){
            return 0;
        }
        
        
        
        
        if(!flag){//if index is even
            int op1 = arr[ind - 1] + f(ind - 1, !flag, arr);
            int op2 = f(ind - 1, flag, arr);
            
            return max(op1, op2);            
        }
        else{//if index is odd
            int op1 = -arr[ind-1] + f(ind - 1, !flag, arr);
            int op2 = f(ind - 1, flag, arr);
            return max(op1, op2);
        }
        
        
    }
    
 
        
    long long maxAlternatingSum(vector<int>& arr) {
        int n = arr.size();
        
        return f(n, 0, arr);
        
    }
};

// memoization 

long long maxAlternatingSum(vector<int>& arr) {
        int n = arr.size();
        
        // return f(n, 0, arr);
        vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
        
        //base case 
        dp[0][0] = 0;
        dp[0][1] = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<2;j++){
                if(!j){//if index is even
                    ll op1 = arr[i - 1] + dp[i - 1][!j];
                    ll op2 = dp[i - 1][j];

                    dp[i][j] = max(op1, op2);            
                }
                else{//if index is odd
                    ll op1 = -arr[i-1] + dp[i - 1][!j];
                    ll op2 = dp[i - 1][j];
                    dp[i][j] =  max(op1, op2);
                }
                
            }
        }
        
        return dp[n][0];
        
  
  // space optimized 
  
  
  long long maxAlternatingSum(vector<int>& arr) {
        int n = arr.size();
        
        // return f(n, 0, arr);
        vector<ll> prev(2, 0), curr(2, 0);
        
        //base case 
        prev[0] = 0;
        prev[1] = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<2;j++){
                if(!j){//if index is even
                    ll op1 = arr[i - 1] + prev[!j];
                    ll op2 = prev[j];

                    curr[j] = max(op1, op2);            
                }
                else{//if index is odd
                    ll op1 = -arr[i-1] + prev[!j];
                    ll op2 = prev[j];
                    curr[j] =  max(op1, op2);
                }
                
            }
            prev = curr;
        }
    
        return prev[0];
        
    }






