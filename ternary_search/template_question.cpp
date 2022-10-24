// problem link : // https://leetcode.com/contest/weekly-contest-316/problems/minimum-cost-to-make-array-equal/

class Solution {
public:
    #define ll long long
    ll func(ll x, vector<int> arr, vector<int> cost){
        int n = arr.size();
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll add = abs(x - arr[i]) * cost[i];
            ans += add;
        }
        
        return ans;
        
    }
    long long minCost(vector<int>& arr, vector<int>& cost) {
        int n = arr.size();
        ll l = 0;
        ll r = 1000000L;
        while(l < r){
            ll m1 = l + (r - l)/3;
            ll m2 = r - (r - l)/3;
            
            ll fm1 = func(m1, arr, cost);
            ll fm2 = func(m2, arr, cost);
            
            if(fm1 > fm2){
                l = m1 + 1;
            }
            else if(fm1 < fm2){
                r = m2 - 1;
            }
            else{
                l = m1 + 1;
                r = m2 - 1;
            }
        }
        
        
        ll ans = func(l, arr, cost);
        return ans;
        
    }
};
