// problem link : https://leetcode.com/problems/largest-divisible-subset/
class Solution {
public:
    
    #define pb push_back
    
    
    // bool check(int i, int j, vector<int> &arr){
    //     if((arr[i]%arr[j] == 0) || (arr[j]%arr[i] == 0))return true;
    //     else return false;
    // }
    
    
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        sort(arr.begin(), arr.end());
        int mx = 1;
        int last_index = 0;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev = 0; prev < i; prev++){
                if(((arr[i]%arr[prev] == 0) || (arr[prev]%arr[i] == 0)) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > mx){
                mx = dp[i];
                last_index = i;
            }
            
        }
        
//         cout<<mx<<endl;
        
        
//         for(auto it : dp){
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
        vector<int> lis;
        lis.pb(arr[last_index]);
        
        while(hash[last_index] != last_index){
            last_index = hash[last_index];
            lis.pb(arr[last_index]);
        }
        
        
        reverse(lis.begin(), lis.end());
        
        
        return lis;
        
        
      
        
        
        
        
    }
};
