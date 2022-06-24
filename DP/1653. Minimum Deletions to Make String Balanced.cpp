// problem link : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

class Solution {
public:
    
    //normal dp but had to recognize second parameter
    
    int dp[100005][3];
    int f(int ind, int prev, string &s, int n){
       
        //base case
        if(ind == n)return 0;
        
        if(dp[ind][prev] != -1)return dp[ind][prev];
        
        if(prev == 2){
            int op1 = 1 + f(ind+1, prev, s, n);
            int op2 = f(ind + 1, (s[ind]=='a')?1:0, s, n);
            return dp[ind][prev] = min(op1, op2);
        }
        else if(prev == 1){//if prev element is 'a'
            int op1 = 1 + f(ind+1, prev, s, n);
            int op2 = f(ind + 1, (s[ind]=='a')?1:0, s, n);
            return dp[ind][prev] = min(op1, op2);
        }
        else{//if prev element is 'b'
            if(s[ind] == 'a'){
                return dp[ind][prev] = 1 + f(ind + 1, prev, s, n);
            }
            else{
                return dp[ind][prev] = f(ind + 1, 0, s, n);
            }
            
        }
        
        
        
        
        
        
        
    }
    int minimumDeletions(string s) {
        int n = s.length();
        memset(dp, -1, sizeof dp);
        return f(0, 2, s, n);
        
    }
};
