+ vector<int> adj[26];
     string res = "";
     
     void topoSort(vector<bool>& vis, int u){
         vis[u] = true;
         for(int ngh : adj[u]){
             if(!vis[ngh])
                topoSort(vis, ngh);
         }
         res = (char)('a' + u) + res;
     }
     
     
     
    string findOrder(string dict[], int N, int K) {
        
        /* Create the Graph */
        for(int i = 0; i < N - 1; i++){
            for(int j = 0; j < min(dict[i].size(), dict[i + 1].size()); j++){
                if(dict[i][j] != dict[i + 1][j]){
                    adj[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');
                    break;
                }
            }
        }
       
        vector<bool> vis(K, false);
        
        /* Perforrm simple topological sort on the gragh as it is DAG */
        for(int i = 0; i < K; i++)
            if(!vis[i])
                topoSort(vis, i);
        return  res;
    }
