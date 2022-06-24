// 1947. Maximum Compatibility Score Sum
// problem link : https://leetcode.com/problems/maximum-compatibility-score-sum

class Solution {
public:
    
    //dp with bitmask
    
    
    
    
    int dp[10][(1<<8)];
    
    int f(int ind, int mask, vector<vector<int>>& students, vector<vector<int>>& mentors, int n, int m){
        
        
        if(ind == n){
            if((mask&((1<<n)-1)) == 0)return 0;
            else return INT_MIN;
        }
        
        
        if(dp[ind][mask] != -1)return dp[ind][mask];
        
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if((mask&(1<<i))){
                int total = 0;
                for(int j=0;j<m;j++){
                    if(students[ind][j] == mentors[i][j])total++;
                }
                // cout<<total<<endl;
                ans = max(ans, total + f(ind+1, (mask^(1<<i)), students, mentors, n, m));
            }
        }
        
        
        return dp[ind][mask] = ans;
        
    }
    
    
    
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size();
        int m = students[0].size();
        memset(dp, -1, sizeof dp);
        return f(0, (1<<n)-1, students, mentors, n, m);
        
        
        
    
        
    }
};
