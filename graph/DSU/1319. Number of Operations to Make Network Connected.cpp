// problme link = https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// good DSU question 


class Solution {
public:
    
    
    void make(int v, vector<int> &parent, vector<int> &size){
        parent[v] = v;
        size[v] = 1;
    }
    
    
    int find(int v, vector<int> &parent){
        if(parent[v] == v)return v;
        //path compresssion
        return parent[v] = find(parent[v], parent);
    }
    
    bool Union(int a, int b, vector<int> &parent, vector<int> &size){
        a = find(a, parent);
        b = find(b, parent);
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
    
    
    
    int makeConnected(int n, vector<vector<int>>& edges) {
        
        
        vector<int> parent(n);
        vector<int> size(n);
        for(int i=0;i<n;i++){
            make(i, parent, size);
        }
        
        
        int c = 0;
        vector<int> visited(n, false);
        for(auto it : edges){
            int a = it[0];
            int b = it[1];
            visited[a] = true;
            visited[b] = true;
            bool t = Union(a, b, parent, size);
            if(!t){
                c++;    
            }
        }
        
        int ct = 0;
        
        for(int i=0;i<n;i++){
            if(parent[i] == i)ct++;
        }
        
        int re = 0;
        for(int i=0;i<n;i++){
            if(visited[i] == false)re++;
        }
        
        
        re += abs(re - ct) - 1;
        
        
        // cout<<c<<" "<<re<<" "<<ct<<endl;
        
        if(c >= re){
            return re;
        }
        else{
            return -1;
        }
        
        
        
    }
};
