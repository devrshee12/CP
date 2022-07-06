// problem link : https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/



class Solution {
public:
    #define ff first
    #define ss second
    #define pb push_back
    
    // great double sliding window problem 
    
    int giveInterval(vector<int> arr, int start, int end, int k){
        
        
        int i = start;
        int j = start;
    
        int sum = 0;
        int mx = 0;
        
        while(j <= end){
            sum += arr[j];
            if(j - i + 1 < k){
                j++;
            }
            else if(j - i + 1 == k){
                mx = max(mx, sum);
                sum -= arr[i];
                i++;
                j++;
            }
            
        }
        
        
        
        return mx;
        
        
    }
    
    
    
    
    
    int maxSumTwoNoOverlap(vector<int>& arr, int firstLen, int secondLen) {
            
        int n = arr.size();
        
        
        int i=0;
        int j=0;
        int ans = 0;
        int sum = 0;
        while(j < n){
            sum += arr[j];
            if(j - i + 1 < firstLen)j++;
            else if(j - i + 1 == firstLen){
                int res = sum;
                    
                int left = giveInterval(arr, 0, i-1, secondLen);
                int right = giveInterval(arr, j+1, n-1, secondLen);
                
                res += max(left, right);
                
                ans = max(ans, res);
                sum -= arr[i];
                i++;
                j++;
            }
                
            
            
            
        }

        
        return ans;
        
        
    }
};
