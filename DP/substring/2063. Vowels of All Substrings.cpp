// problem link: https://leetcode.com/problems/vowels-of-all-substrings/

class Solution {
public:
    // Dynamic Programming:
    /*
    First vowel: res = 1;
    Second vowel: res = 1 + (1 + 2);
    Third vowel: res = 1 + (1 + 2) + (1 + 2 + 3);
    ...
    Nth vowel: res = 1 + (1 + 2) + (1 + 2 + 3) + ... + (1 + 2 + 3 + ... + N);
    */
    #define ll long long
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        else return false;
    }
    long long countVowels(string word) {
        int n = word.length();
        ll curr =0;
        ll ans = 0; 
        if(isVowel(word[0])){
            curr = 1;
        }
        ans += curr;
        for(int i=1;i<n;i++){
            ll temp = curr;
            if(isVowel(word[i])){
                temp += i+1;
                curr = temp;
            }
            ans += curr;
        }
        
        
        return ans;
    }
};
