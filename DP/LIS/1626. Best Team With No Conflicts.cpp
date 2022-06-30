// problem link : https://leetcode.com/problems/best-team-with-no-conflicts/

class Solution {
public:
    
    // maximum sum of longest increasing subsequence (here O(n^2))
    // great lis question 
    
    
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int n = ages.size();
        
        vector<int> dp(n);
        vector<pair<int, int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i].first = ages[i];
            arr[i].second = scores[i];
        }
        
        sort(arr.begin(), arr.end());
        
        // for(auto it : arr){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        
        
        int mx = INT_MIN;
        for(int i = 0; i < n ; i++ ){
            dp[i] = arr[i].second;
            for(int prev = 0; prev < i ; prev++){
                if(arr[prev].second <= arr[i].second && arr[i].second + dp[prev] > dp[i]){
                    dp[i] = arr[i].second + dp[prev];
                }
            }
            
            mx = max(mx, dp[i]);
        }
        
        
        return mx;
        
    }
};
