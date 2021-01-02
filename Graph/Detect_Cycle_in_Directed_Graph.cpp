bool dfs(int u, vector<bool>& vis, vector<bool>& recSt, vector<int> adj[]){
    if(vis[u] == false){
        vis[u] = true;
        recSt[u] = true;
        
        for(auto it = adj[u].begin(); it != adj[u].end(); it++){
            if(!vis[*it] && dfs(*it, vis, recSt, adj))
                return true;
            else if(recSt[*it])
                return true;
        }
    }
    recSt[u] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<bool> recSt(V, false);
    for(int i = 0; i < V; i++){
        if(dfs(i, vis, recSt, adj))
            return true;
    }
    return false;
}
