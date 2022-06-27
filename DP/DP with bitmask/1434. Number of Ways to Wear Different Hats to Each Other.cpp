// problem link: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/


class Solution {
public:
    #define mod 1000000007
    #define ll long long
    #define pb push_back
    
    //hard DP with bitmask 
    
    int dp[45][(1<<11)-1];
    
    ll f(int ind, int mask, vector<vector<int>>& hats, int n, map<int, vector<int>> &m){
        
        
        if(ind == 41){
            if((mask&((1<<n) - 1)) == 0)return 1;
            else return 0;
        }
        
        
        if(dp[ind][mask] != -1)return dp[ind][mask];
        
        
        if(m.find(ind) != m.end()){
            // cout<<"ind: "<<ind<<endl;
            
            ll ans = 0; 
            bool flag = false;
            ans =  (int)((ans%mod + f(ind+1, mask, hats, n, m)%mod)%mod);
            
            for(auto it : m[ind]){
                
                
                if(mask&(1<<it)){
                    flag = true;
                    // cout<<"it :"<<it<<endl;
                    ll pick = (int)(f(ind + 1, (mask^(1<<it)), hats, n, m)%mod);
                    
                    // cout<<ind<<" "<<it<<" "<<pick<<" "<<notPick<<" "<<pick+notPick<<endl;
                    // int tempmask = ;
                    ans = (ans%mod + (pick%mod))%mod;
                    
                }
                
            }
            
            if(flag == false){
                return dp[ind][mask] = (int)f(ind + 1, mask, hats, n, m)%mod;
            }
            else return dp[ind][mask] = (int)ans%mod;
                
            
            
            // return ans;
        }
        
        return dp[ind][mask] = (int)f(ind+1, mask, hats, n, m)%mod;
            

    
        
        
    
        
        
        
        
       
        
    }
    
    
    
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        int mask = ((1<<10) - 1);
        map<int, vector<int>> t;
        for(int i=0;i<n;i++){
            for(auto it : hats[i]){
                t[it].pb(i);
            }
        }
        memset(dp, -1, sizeof dp);
        
        // for(auto it : t){
        //     cout<<it.first<<"->";
        //     for(auto i : it.second){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        
        // return 0;
        return f(1, mask, hats, n, t);
        
        
    }
};
