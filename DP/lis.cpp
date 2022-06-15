#include<bits/stdc++.h>
int f(int ind, int prev_ind, int arr[], int n){
    
    if(ind == n){
        return 0;
    }
    
    
    int len = 0;
    if(prev_ind ==  -1 || arr[ind] > arr[prev_ind]){
        len = 1 + f(ind+1, ind, arr, n);
    }
    len = max(len, f(ind+1, prev_ind, arr, n));
    
}





int longestIncreasingSubsequence(int arr[], int n)
{
    
//     vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
//     return f(0, -1, arr, n);
    
    //base case 
//     for(int i=0;i<=n;i++){
//         dp[n][i] = 0;
//     }
    
    
//     for(int ind=n-1;ind>=0;ind--){
//         for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
//              int len = 0;
//             if(prev_ind ==  -1 || arr[ind] > arr[prev_ind]){
//                 len = 1 + dp[ind+1][ind+1];
//             }
//             len = max(len, dp[ind+1][prev_ind+1]);
            
//             dp[ind][prev_ind+1] = len;
            
//         }
//     }
                      
//     return dp[0][-1+1];
    
    
    
    //we need to know this method in order to print LIS
    
//       vector<int> dp(n, 1);
//        for(int i=1;i<n;i++){
//            int mx = 0;
//            for(int j=0;j<i;j++){
//                if(arr[i] > arr[j]){
//                    mx = max(mx, dp[j]);
//                }
//            }
           
//            dp[i] = 1 + mx;
//        }
    
// //     for(auto it : dp){
// //         cout<<it<<" ";
// //     }
//     cout<<endl;
//     int res = *max_element(dp.begin(), dp.end());
//     return res;
    
    
    
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int prev = 0;prev<i;prev++){
            if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    
    for(auto it : dp)cout<<it<<" ";
    cout<<endl;
    for(auto it : hash)cout<<it<<" ";
    cout<<endl;
    
    vector<int> lis;
    cout<<"last index : "<<lastIndex<<endl;
    lis.push_back(arr[lastIndex]);
    
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        lis.push_back(arr[lastIndex]);
    }
    
    reverse(lis.begin(), lis.end());
    for(auto it : lis){
        cout<<it<<" ";
    }
    cout<<endl;
    return lis.size();
  
  
  // o(nlogn)
  vector<int> temp;
    temp.push_back(arr[0]);
    int ans = 1;
    for(int i=1;i<n;i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            ans++;
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    
    return ans;
    
    
    
    
    
    
    
    
    
    
    
    
}
