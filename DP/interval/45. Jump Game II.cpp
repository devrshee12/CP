// problem link : https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    
    // min max concept
    int jump(vector<int>& arr) {
        int n = arr.size();
        int min = 0;
        int max = 0;
        int ans = 0;
        
        
        while(max < n-1){
            for(int i=0;i<n;i++){
                int l = i;
                int r = i + arr[i];
                if(l <= min && r > max){
                    max = r;
                }
            }
            
            min = max;
            ans++;
        }
        
        
        return ans;
    }
};
