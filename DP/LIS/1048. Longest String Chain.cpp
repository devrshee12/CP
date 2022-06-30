// problem link : https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
    
    
    
    bool check(string s, string t){
        
        
        
        // cout<<s<<" "<<t<<endl;
        
        
        int len1 = s.length();//small 
        int len2 = t.length();//big
        
        // cout<<len1<<" "<<len2<<endl;
        
        if(len2 - len1 != 1)return false;
        
        int i = 0;
        int j = 0;
        
        while(i < len1 && j < len2){
            
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        
        // cout<<i<<" "<<j<<endl;
        
        if(i != len1)return false;
        return true;
        
        
    }
    
    static bool comp(string &a, string &b){
        if(a.length() < b.length())return true;
        else return false;
    }
    
    int longestStrChain(vector<string>& arr) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp);
        // for(auto it : arr)cout<<it<<" ";
        // cout<<endl;
        vector<int> dp(n, 1);
        
        
        
        int mx = 1;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(check(arr[prev], arr[i]) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }
            mx = max(mx, dp[i]);
            // cout<<dp[i]<<" ";
        }
        // cout<<endl;
        
        
        
        
        
        return mx;
        
        
    }
};
