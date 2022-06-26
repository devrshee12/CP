class Solution {
public:
    // tabulation is used when we want to find longest common substring
    
    int f(int i, int j, int res, vector<int>& s, vector<int>& t){
        if(i == -1 || j == -1){
            return res;
        }
        
        if(s[i] == t[j]){
            res = f(i-1, j-1, res+1, s, t);
        }
        return max({res, f(i-1, j, 0, s, t), f(i, j-1, 0, s, t)});
        
        
        
        
    }
    int findLength(vector<int>& s, vector<int>& t) {
        int n = s.size();
        int m = t.size();
        
        // return f(n-1, m-1, 0, s, t);
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<=n;i++)dp[i][0] = 0;
        for(int j=0;j<=m;j++)dp[0][j] = 0;
        
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans;
        
    }
};
