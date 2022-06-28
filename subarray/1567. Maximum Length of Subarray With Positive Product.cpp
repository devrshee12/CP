// problem link : https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

class Solution {
public:
    #define pb push_back
    
    
    int len(vector<int> arr){
        int n = arr.size();
        if(n == 0)return 0;
        int c = 0; 
        int s = 0;
        int e = 0;
        for(int i=0;i<n;i++){
            if(arr[i] < 0){
                
                if(c == 0){
                    s = i;
                }
                c++;
                e = i;
                
            }
        }
        
        if(c == 0){
            return n;
        }
        if(c%2 == 0)return n;
        else{
            int s1 = s;
            int s2 = n - s - 1;
            int e1 = e;
            int e2 = n - e - 1;
            return max({s1, s2, e1, e2});
            
            
        }
        
        
        
    }
   
    
    
    
    int getMaxLen(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> contain;
            
            
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                contain.pb(temp);
                temp.clear();
            }
            else{
                temp.pb(arr[i]);
            }
        }
        
        if(arr[n-1] != 0)
            contain.pb(temp);
        
            
        int mx = INT_MIN;
        for(auto it : contain){
            mx = max(mx, len(it));
        }
        
        
        return mx;
        
        
        
        
        
        
        
        
    }
};
