// problem link : https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
public:
    
    int f(int i, int j, vector<vector<int>>& arr, int n, int m){
        
        
        if(i == n-1){
            if(j + 1 < m && arr[i][j] == 1 && arr[i][j+1] == 1){
                return j + 1;
            }
            else if(j - 1 >= 0 && arr[i][j] == -1 && arr[i][j-1] == -1){
                return j-1;
            }
            else{
                return -1;
            }
        }
        
        
        
        
        if(arr[i][j] == 1){
            if(i + 1 < n && j + 1 < m && arr[i][j+1] == 1){
                return f(i + 1, j + 1, arr, n, m);
            }
            else{
                // cout<<i<<" "<<j<<" "<<arr[i][j]<<" "<<arr[i][j+1]<<endl;
                return -1;
            }
        }
        else{
            if(i+1 < n && j - 1 >= 0 && arr[i][j-1] == -1){
                return f(i+1, j-1, arr, n, m);
            }
            else{
                // cout<<i<<" "<<j<<" "<<arr[i][j]<<" "<<arr[i][j-1]<<endl;
                return -1;
            }
            
        }
        
    }
    
    
    
    
    
    vector<int> findBall(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        // int first = f(0, 3, arr, n, m);
        
        vector<int> ans(m, -1);
        
        for(int j=0;j<m;j++){
            ans[j] = f(0, j, arr, n, m);
        }
        
        
        return ans;
        // cout<<first<<endl;
        // return {0, 1, 2};
            
            
            
            
    }
};
