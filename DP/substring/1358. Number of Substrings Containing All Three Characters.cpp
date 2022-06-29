// problem link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
class Solution {
public:
    
    //variable size sliding window 
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        map<char, int> m;
        int ans = 0;
        while(j < n){
            m[s[j]]++;
            
            while(m['a'] > 0 && m['b'] > 0 && m['c'] > 0){
                m[s[i]]--;
                i++;
                // cout<<(n-j)<<endl;
                ans += (n-j);
            }
            j++;
        }
        
        
        return ans;
        
        
        
        
    }
};
