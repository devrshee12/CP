// problem link : https://leetcode.com/problems/palindrome-partitioning-ii/


class Solution {
public:
    
    //front partition 
    
    
    int dp[2001];
    bool isPalindrome(int i, int j, string s){
        
        while(i < j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        
        
        return true;
        
    }
    
    
    
    int f(int i, string s, int n){
        
        
        if(i == n || isPalindrome(i, n, s))return 0;
        
        
        
        if(dp[i] != -1)return dp[i];
        
        
        int mini = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i, j, s)){
                // cout<<i<<" "<<j<<endl;
                int cost = 1 + f(j + 1, s, n);
                mini = min(mini, cost);
            }
        }
        
        
        
        return dp[i] = mini;
        
    }
    
    int minCut(string s) {
        int n = s.length();
        if(isPalindrome(0, n, s))return 0;
        memset(dp, -1, sizeof dp);
        return f(0, s, n) - 1;
        
        
        //base case 
        
//         vector<int> dp(n+1, 0);
    
//         dp[n] = 0;
//         for(int i=n-1;i>=0;i--){
//             int mini = INT_MAX;
//             for(int j=i;j<n;j++){
//                 if(isPalindrome(i, j, s)){
//                     // cout<<i<<" "<<j<<endl;
//                     mini = min(mini, 1 + dp[j + 1]);
//                 }
//             }
            
//             dp[i] = mini;
            
//         }
        
        
//         return dp[0] - 1;

        
        
    }
};
