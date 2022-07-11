// problem link : https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    #define pb push_back
    
    
    //dfs question 
    // coded by me
    
    void dfs(int node, int d, vector<vector<int>> adj, vector<int> visited, vector<int> temp, vector<vector<int>> &ans){
        
        if(node == d){
            ans.pb(temp);
            return;
        }
        if(node == 0){
            temp.pb(0);
        }        
        
        for(auto it : adj[node]){
            if(visited[it] == false){
                visited[it] = true;
                temp.pb(it);
                dfs(it, d, adj, visited, temp, ans);
                visited[it] = false;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> ans;
        vector<int> visited(n+1, 0);
        vector<int> temp;
        dfs(0, n-1, adj, visited, temp, ans);
        // for(auto it : ans){
        //     it.pb(0);
        // }
        return ans;
    }
};
