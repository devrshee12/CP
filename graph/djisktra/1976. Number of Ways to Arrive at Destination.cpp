// problem link : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/


class Solution {
public:
    //djiktra nice question 
    
    
    #define pb push_back
    #define ll long long
    int countPaths(int n, vector<vector<int>>& roads) {
        ll mod = (1e9 + 7);
        vector<ll> ways(n+1, 0);
        ll maxi = 1e18;
        vector<ll> dist(n+1, maxi);
        
        dist[0] = 0;
        ways[0] = 1;
            
        vector<pair<ll, ll>> adj[n+1];
        
        for(auto it : roads){
            adj[it[0]].pb({it[1], it[2]});
            adj[it[1]].pb({it[0], it[2]});
        }
        
        
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            ll node = pq.top().second;
            ll dis = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                ll wt = it.second;
                ll adjNode = it.first;
                
                if(wt + dis < dist[adjNode]){
                    dist[adjNode] = wt + dis;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if(wt + dis == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode]%mod + ways[node]%mod)%mod;
                }
                
            }
            
        }
        
        
        return (int)ways[n-1];
        
        
        
    }
};
