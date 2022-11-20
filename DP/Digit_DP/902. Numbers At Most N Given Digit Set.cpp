// leetcode : https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

class Solution {
public:
    int dp[12][5][5];
    int solve(vector<int> &v, int pos, int tight, int st, string &s){
        if(pos == s.size())return 1;

        if(dp[pos][tight][st] != -1)return dp[pos][tight][st];


        int ans = 0;

        // if value is not started yet we have two choice we can leave the current digit
        // or start from here 

        if(st == 0){
            int en = tight ? (s[pos] - '0') : 9;
            ans = solve(v, pos + 1, 0, 0, s); // leave current digit;
            for(int i=0;i<v.size();i++){
                if(v[i] > en)continue;
                ans += solve(v, pos + 1, tight&(en == v[i]), 1, s);
            }

        }
        else{
            int en = tight ? (s[pos] - '0') : 9;
            for(int i=0;i<v.size();i++){
                if(v[i] > en)continue;
                ans += solve(v, pos + 1, tight&(en == v[i]), st, s);
            }
        }


        return dp[pos][tight][st] = ans;
    }

    
    int atMostNGivenDigitSet(vector<string>& dig, int n) {
        string s = to_string(n);
        vector<int> v(dig.size(), 0);
        for(int i=0;i<dig.size();i++){
            v[i] = dig[i][0] - '0';
        }

        memset(dp, -1, sizeof dp);
        return solve(v, 0, 1, 0, s) - 1;

        
        
    }
};
