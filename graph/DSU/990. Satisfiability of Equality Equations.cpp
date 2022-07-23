// problem link : https://leetcode.com/problems/satisfiability-of-equality-equations/

class Solution {
public:
    //DSU
    
    #define pb push_back
    int parent[30];
    int size[30];
    
    
    void make(int v){
        parent[v] = v;
        size[v] = 1;
    }
    
    
    int find(int node){
        if(node == parent[node])return node;
        return parent[node] = find(parent[node]);
    }
    
    
    bool Union(int a, int b){
        a = find(a);
        b = find(b);
        
        if(a != b){
            
            if(size[a] < size[b]){
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
    
    
    bool equationsPossible(vector<string>& arr) {
        for(auto it : arr){
            make(it[0]-'a');
            make(it[3]-'a');
            
        }
        
        for(auto it : arr){
            if(it[1] == '='){ //doing the union of x and y as there is equality which means they must belong to same set
                Union(it[0]-'a', it[3]-'a');
            }
        }
        
        
        for(auto it : arr){
            if(it[1] == '!'){
                if(find(it[0]-'a') == find(it[3]-'a')){ // if they are having same parents we can say that we cannot make it
                    return false;
                }
            }
        }
        
        
        
        return true;
        
        
        
        
    }
};
