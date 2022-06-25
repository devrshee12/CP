// problem link: https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {
public:
    
    // LCS variation 
    
    int f(int i, int j, string s, string t){
        if(i == 0 && j == 0){
            return 0;
        }
        if(i == 0 && j > 0){
            return j;
        }
        if(i > 0 && j == 0){
            return i;
        }
        
        
        
        if(s[i-1] == t[j-1]){
            return f(i-1, j-1, s, t);
        }
        else{
            int op1 = 1 + f(i-1, j, s, t);//delete from s 
            int op2 = 1 + f(i, j-1, s, t);//delete from t
            int op3 = 2 + f(i-1, j-1, s, t);//delete from s and t;
            return min({op1, op2, op3});
        }
        
        
    }
    
    
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        // return f(n, m, s, t);
        
        vector<int> prev(m+2, 0), curr(m+2, 0);
        
        
        //base case 
        
        // for(int i=0;i<=n;i++){
        //     prev[0] = i;
        // }
        for(int j=0;j<=m;j++){
            prev[j] = j;
        }
        
        // prev[0] = 0;
        
        for(int i=1;i<=n;i++){
            curr[0] = i; 
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    curr[j] =  prev[j-1];
                }
                else{
                    int op1 = 1 + prev[j];//delete from s 
                    int op2 = 1 + curr[j-1];//delete from t
                    int op3 = 2 + prev[j-1];//delete from s and t;
                    curr[j] =  min({op1, op2, op3});
                }
                
            }
            
            prev = curr;
        }
        
        
        return prev[m];
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};
