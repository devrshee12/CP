// problem link : https://leetcode.com/problems/stone-game-vii/

class Solution {
public:
    
    // nice DP question 
    // but it is giving TLE in leetcode but my solution is of O(n^2) and n ranges 1000
    
    //DP + PREFIX SUM
    
    
    int dp[1001][1001][2];
    int f(int i, int j, int turn, vector<int> arr, vector<int> pre){
        //base case 
        if(i == j){
            return 0;
        }
        
        
        if(dp[i][j][turn] != -1)return dp[i][j][turn];
            
        
        if(turn == 1){//alice turn
            
            // op1 -> alice removes first element of intervel
            // op2 -> alice removes last element of intervel
            
            // 1 -> i + 1 to j
            // 2 -> i to j - 1
            int op1 = pre[j] - pre[i] + f(i + 1, j, !turn, arr, pre);
            int op2 = ((i != 0) ? pre[j-1] - pre[i-1] : pre[j-1]) + f(i, j-1, !turn, arr, pre);
            
            return dp[i][j][turn] = max(op1, op2);
            
        }
        else{//bob turn
            int op1 = -(pre[j] - pre[i]) + f(i + 1, j, !turn, arr, pre);
            int op2 = ((i != 0) ? -(pre[j-1] - pre[i-1]) : -(pre[j-1])) + f(i, j-1, !turn, arr, pre);
            
            return dp[i][j][turn] = min(op1, op2);
            
        }
        
        
        
        
    }
    
    
    
    int stoneGameVII(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> pre(n + 1, 0);
        pre[0] = arr[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + arr[i];
        }
        
        // for(auto it : pre){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
//         memset(dp, -1, sizeof dp);
        
//         return f(0, n-1, 1, arr, pre);
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(3, 0)));
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                for(int turn=0;turn<=1;turn++){
                    if(i == j){
                        dp[i][j][turn] = 0;
                        continue;
                    }
                    if(turn == 1){//alice turn
            
                        // op1 -> alice removes first element of intervel
                        // op2 -> alice removes last element of intervel

                        // 1 -> i + 1 to j
                        // 2 -> i to j - 1
                        int op1 = pre[j] - pre[i] + dp[i + 1][j][!turn];
                        int op2 = ((i != 0) ? pre[j-1] - pre[i-1] : pre[j-1]) + dp[i][j-1][!turn];

                        dp[i][j][turn] = max(op1, op2);

                    }
                    else{//bob turn
                        int op1 = -(pre[j] - pre[i]) + dp[i + 1][j][!turn];
                        int op2 = ((i != 0) ? -(pre[j-1] - pre[i-1]) : -(pre[j-1])) + dp[i][j-1][!turn];

                        dp[i][j][turn] = min(op1, op2);

                    }
                    
                }    
            
            }
        }
        
        
        return dp[0][n-1][1];
    
        
        
        
    }
};
