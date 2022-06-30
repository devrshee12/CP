// problem link: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution {
public:
    //min max concept
    
    int minTaps(int n, vector<int>& arr) {
        
        int min = 0;
        int max = 0;
        int ans = 0;
        while(max < n){
            
            for(int i=0;i<n+1;i++){
                if((i-arr[i]) <= min && i+arr[i]>max){
                    max = i + arr[i];
                }
            }
            if(max == min)return -1;
            ans++;
            min = max;
        }
        
        
        return ans;
        
    }
};
