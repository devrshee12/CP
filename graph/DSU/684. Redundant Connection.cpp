class Solution {
public:
    #define pb push_back
    
    //DSU GOOD QUESTION
    
    
    int parent[1005];
    int size[1005];

    void make(int v){
        //just make node 
        parent[v] = v;
        size[v] = 1;
    }

    int find(int v){
        if(v == parent[v])return v;
        // path compression
        return parent[v] = find(parent[v]);
    }

    bool Union(int a, int b){
        a = find(a);//finding parent so that we can connect thier parents
        b = find(b);
        if(a != b){// this means both node 
            if(size[a] < size[b]){
                // Union will be always on a <- b
                // size(a) should be greater than size(b)
                //if not swap
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
            
            return true;
        }
        else{
            return false;
        }
    }

    
    
    
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int mx = INT_MIN;
        for(auto it : edges){
            mx = max({mx, it[0], it[1]});
        }
        
        int n = mx;
        for(int i=1;i<=n;i++){
            make(i);
        }
        
        vector<int> ans;
        for(auto it : edges){
            bool t = Union(it[0], it[1]);
            if(t == false){
                ans.clear();
                ans.pb(it[0]);
                ans.pb(it[1]);
            }
        }
        
        
        return ans;
        
        
        
    }
};
