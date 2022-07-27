// problem link : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/


class Solution {
public:
    #define pb push_back
    // djiktra good question 
    
    vector<int> djiktra(int src, vector<pair<int, int>> adj[], int n){
        
        
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int wt = it.second;
                int adjNode = it.first;
                
                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        
        return dist;
        
    }
    
    
    
    
    
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int, int>> adj[n];
        for(auto it : edges){
            adj[it[0]].pb({it[1], it[2]});
            adj[it[1]].pb({it[0], it[2]});
        }
        
        map<int, int> m;
        
        for(int i=0;i<n;i++){
            
            vector<int> res = djiktra(i, adj, n);
            int c =0 ;
            for(auto it : res){
                if(it <= distanceThreshold){
                    c++;
                }
            }
            m[i] = c;
            
        }
        
        // vector<int> res = djiktra()
        
        
        int mi = INT_MAX;
        for(auto it : m){
            mi = min(mi, it.second);
        }
        
        int ans = 0;
        for(auto it : m){
            if(it.second == mi){
                ans = it.first;
            }
        }
            
        
        return ans;
        
    }
};
