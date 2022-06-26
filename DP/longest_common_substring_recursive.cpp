class Solution {
public:
    //recursive solution for longest common substring 
    
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
        
        return f(n-1, m-1, 0, s, t);
    }
};
