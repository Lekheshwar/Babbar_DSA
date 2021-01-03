// A more optimized solution using union find also exists.



 void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis){
        vis[u] = true;
        for(auto it = adj[u].begin(); it != adj[u].end(); it++){
            if(!vis[*it])dfs(*it, adj, vis);
        }
    }
    
    
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size() < n - 1)return -1;
        
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for(auto x : c){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int cnt = 0;
        for(int i = 0; i  < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt - 1;
    }
