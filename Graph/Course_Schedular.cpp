vector<int> graph[100005];
    int inDeg[100005];
    
    void makeGraph(vector<vector<int>>& pre){
        for(auto edge : pre){
            graph[edge[1]].push_back(edge[0]);
            inDeg[edge[0]]++;
        }
    }
   
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        memset(inDeg, 0, sizeof inDeg);
        makeGraph(prerequisites);
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDeg[i] == 0)q.push(i);
        }
        
        int cnt = 0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cnt++;
            for(int adj : graph[curr]){
                inDeg[adj]--;
                if(!inDeg[adj])q.push(adj);
            }
        }
        
        
        return cnt == numCourses;
    }
