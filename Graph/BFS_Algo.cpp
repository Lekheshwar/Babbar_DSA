vector <int> bfs(vector<int> g[], int N) {
    if(!g)return {};
    vector<int> res;
    
    bool vis[N] = {false};
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int ft = q.front();
        q.pop();
        if(!vis[ft]){
            vis[ft] = true;
            res.push_back(ft);
            
        }
        for(auto x : g[ft]){
            if(!vis[x]){
                q.push(x);
            }
        }
    }
    return res;
}
