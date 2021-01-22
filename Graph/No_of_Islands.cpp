+int vis[501][501];
    
    void dfs(vector<vector<char>>& g, int i, int j, int n, int m){
        vis[i][j] = true;
        if(j + 1 < m && (g[i][j + 1] -'0') && !vis[i][j + 1])dfs(g, i, j + 1, n, m); // right
        if(i + 1 < n && (g[i + 1][j] - '0') && !vis[i + 1][j])dfs(g, i + 1,j, n, m); // down
        if(i + 1 < n && j + 1 < m && (g[i + 1][j + 1] - '0') && !vis[i + 1][j + 1])dfs(g, i + 1, j + 1, n , m); // right - down diagonal
        if(i + 1 < n && j - 1 >= 0 && (g[i + 1][j - 1] - '0') && !vis[i + 1][j - 1])dfs(g, i + 1, j - 1, n, m); // left  - down diagonal
        if(j - 1 >= 0 && (g[i][j - 1] -'0') && !vis[i][j - 1])dfs(g, i, j - 1, n, m); // left
        if(i - 1 >= 0 && (g[i - 1][j] - '0') && !vis[i - 1][j])dfs(g, i - 1,j, n, m); // top
        if(i - 1 >= 0 && j - 1 >= 0 && (g[i - 1][j - 1] - '0') && !vis[i - 1][j - 1])dfs(g, i - 1, j - 1, n , m); // left - up diag
        if(i - 1 >= 0 && j + 1 < m && (g[i - 1][j + 1] - '0') && !vis[i - 1][j + 1])dfs(g, i - 1, j + 1, n, m); // right up diag
    }

    int numIslands(vector<vector<char>>& grid) {
        memset(vis, false, sizeof vis);
        int cnt = 0, n = grid.size(), m = grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if((grid[i][j] - '0') && !vis[i][j])dfs(grid, i, j, n, m), cnt++;
            }
        }
        return cnt;
    }
