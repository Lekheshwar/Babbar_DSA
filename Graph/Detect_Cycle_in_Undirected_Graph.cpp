// You only have to check if the visiting note is present in the rec - st, and 
// it is not the parent of the current element. Then there is a cycle.
//
//		1		3
//	       /	       / \
//	      2        	      4--5	
//


bool help(int u, int pr, vector<bool>& vis, vector<bool>& st, vector<int> g[]){
    if(vis[u]==false){
        vis[u] = true;
        st[u] = true;
        
        for(auto it = g[u].begin(); it != g[u].end(); it++){
           if(!vis[*it]){
               if(help(*it, u,vis, st, g))
                    return true;
           }
           else{
               if(st[*it] && *it != pr)return true;
           }
        }
    }
    st[u] = false;
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
    vector<bool> vis(V+1, false);
    vector<bool> st(V+1, false);
    
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            if(help(i, i, vis, st, g))return true;
        }
    }
    return false;
}
