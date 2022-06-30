// problem link: https://leetcode.com/problems/video-stitching/

class Solution {
public:
    
    //min max concept 
    
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        int min = 0;
        int max = 0;
        int ans =0 ;
        while(max < time){
            for(auto it : clips){
                int l = it[0];
                int r = it[1];
                
                if(l <= min && r > max){
                    max = r;
                    
                }
            }
            if(min == max)return -1;
            
            min = max;
            ans++;
        }
        
        
        return ans;
        
    }
};
