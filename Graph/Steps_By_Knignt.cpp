// You could also use the offsetX and offsetY arr to make the code look small.
// BFS is used to find the shortest level. DFS might give an TLE.

bool vis[1001][1001];

int minStepToReachTarget(int kp[], int tp[], int N) {
    
    queue<pair<int, int>> q;
    memset(vis, false, sizeof vis);
    q.push(make_pair(kp[0], kp[1]));
    vis[kp[0]][kp[1]] = true;
    int level = 0;
    while(!q.empty()){
        int sz = q.size();
        for(int it = 0; it < sz; it++){
            pair<int,int> curr = q.front();
            q.pop();
            if(curr.first == tp[0] && curr.second == tp[1])return level;
            int i = curr.first, j = curr.second;
            // 8 possible directions available.
            
            if(i - 1 > 0 && j - 2 > 0 && !vis[i - 1][j - 2]){
                q.push(make_pair(i - 1, j - 2));
                vis[i - 1][j - 2] = true;
            }
                
            if(i - 2 > 0 && j - 1 > 0 && !vis[i - 2][j - 1]){
                q.push(make_pair(i - 2, j - 1));
                vis[i - 2][j - 1] = true;
            }
                
            if(i - 2 > 0 && j + 1 <= N && !vis[i - 2][j + 1]){
                q.push(make_pair(i - 2, j + 1));
                vis[i - 2][j + 1] = true;
            }
                
            if(i - 1 > 0 && j + 2 <= N && !vis[i - 1][j + 2]){
                q.push(make_pair(i - 1, j + 2));
                vis[i - 1][j + 2] = true;
            }
            
            if(i - 1 > 0 && j + 2 <= N && !vis[i - 1][j + 2]){
                q.push(make_pair(i - 1, j + 2));
                vis[i - 1][j + 2] = true;
            }
                
            if(i + 1 <= N && j + 2 <= N && !vis[i + 1][j + 2]){
                q.push(make_pair(i + 1, j + 2));
                vis[i + 1][j + 2] = true;
            }
            
            if(i + 2 <= N && j + 1 <= N && !vis[i + 2][j + 1]){
                q.push(make_pair(i + 2, j + 1));
                vis[i + 2][j + 1] = true;
            }
            
            if(i + 2 <= N && j - 1 > 0 && !vis[i + 2][j - 1]){
                q.push(make_pair(i + 2, j - 1));
                vis[i + 2][j - 1] = true;
            }
            
            if(i + 1 <= N && j - 2 > 0 && !vis[i + 1][j - 2]){
                q.push(make_pair(i + 1, j - 2));
                vis[i + 1][j - 2] = true;
            }
        }
        level++;
    }
    return level;
}
