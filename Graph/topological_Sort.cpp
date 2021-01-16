/*
  Topological sort is similar to DFS, the only difference is you are suppose to add the current vertex to the stack after visiting all its neighbours. 
  TC - O(V + E)   same as DFS
  SC - O(V)  for stack.
*/

#include<bits/stdc++.h>
using namespace std;

void topologicalSort(int u, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st){
    vis[u] = true;
    
    for(int padosi : adj[u]){
        if(!vis[padosi])
            topologicalSort(padosi, adj, vis, st);
    }
    st.push(u);
}

int main(){
    vector<vector<int>> adj(6, vector<int>());
    adj[2] = {3};
    adj[3] = {1};
    adj[4] = {0, 1};
    adj[5] = {2, 0};
    
    /*
        5 ---> 0 <--- 4
        |             |
        |             |
        V             V
        2 ---> 3 <--- 1
    */
    
    vector<bool> vis(6, false);
    stack<int> st;
    for(int i = 0; i < 6; i++){
        if(!vis[i])
            topologicalSort(i, adj, vis, st);
    }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
