// problem link : https://leetcode.com/problems/two-best-non-overlapping-events/

class Solution {
public:
    
    
//     int upper(vector<vector<int>> arr, int val, int t){
//         int n = arr.size();
        
//         int l = t+1;
//         int r = n-1;
        
//         while(l <= r){
//             int mid = l + (r - l)/2;
            
//             if(val >= arr[mid][0]){
//                 l = mid + 1;
//             }
//             else{
//                 r = mid - 1;
//             }
//         }
        
        
        
//         return l;
//     }
    
    
    
    
    int maxTwoEvents(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> suff(n);
        suff[n-1] = arr[n-1][2];
        for(int i=n-2;i>=0;i--){
            if(arr[i][2] > suff[i+1]){
                suff[i] = arr[i][2];
            }
            else{
                suff[i] = suff[i+1];
            }
        }
        
        
//         for(auto it : arr){
//             cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
//         }
        
//         for(auto it : suff){
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
        int res = 0;
        for(int i=0;i<n;i++){
            if(arr[i][1] >= arr[n-1][0]){
                res = max(res, arr[i][2]);    
            }
            else{
                int l = i+1;
                int r = n-1;

                while(l <= r){
                    int mid = l + (r - l)/2;

                    if(arr[i][1] >= arr[mid][0]){
                        l = mid + 1;
                    }
                    else{
                        r = mid - 1;
                    }
                }
                
                res = max(res, arr[i][2] + suff[l]);
            }
        }
        
        
        return res;
        
    }
};
