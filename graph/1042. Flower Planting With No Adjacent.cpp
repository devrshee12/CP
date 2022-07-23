// problem link : https://leetcode.com/problems/flower-planting-with-no-adjacent/


class Solution {
public:
    // DFS great question 
    
    #define pb push_back
    void dfs(int node, vector<int> &visited, vector<int> adj[]){
            
        int mx = 0;
        vector<int> t(5, 0);
        for(auto it : adj[node]){
            // mx = max(visited[it], mx);
            t[visited[it]] = 1;
        }
        for(int i=1;i<=4;i++){
            if(t[i] == 0){
                visited[node] = i;
                break;
            }
        }
        
        
        for(auto it : adj[node]){
            if(visited[it] == 0){
                dfs(it, visited, adj);
            }
        }
        
        
    }
    
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> visited(n+1, 0);
        vector<int> adj[n+1];
        for(auto it : paths){
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
        }
        
        
        for(int i=1;i<=n;i++){
            if(visited[i] == 0){
                dfs(i, visited, adj);
            }
        }
        
        vector<int> ans;
        for(int i=1;i<=n;i++){
            ans.pb(visited[i]);
        }
        
        
        return ans;
        
        
        
    }
};
