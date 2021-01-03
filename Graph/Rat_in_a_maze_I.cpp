// Instead of using vis matrix. Just make m[i][j] = 0, in the starting and 
// m[i][j]= 1 when returning from the util function.


bool vis[MAX][MAX];

void util(int m[MAX][MAX], vector<string>& res, int i, int j, int n, string path){
    
    if(i == n - 1 && j == n - 1 && m[n - 1][n -1] == 1){
        res.push_back(path);
        return;
    }
    vis[i][j] = true;
    
    // go down
    if(i + 1 < n && !vis[i + 1][j] && m[i + 1][j] == 1){
        util(m,res,i+1, j, n, path + 'D');
    }
    
    // go  left
    if(j - 1 >= 0 && !vis[i][j - 1] && m[i][j - 1] == 1){
        util(m,res,i, j - 1, n, path + 'L');
    }
    
    // go right
    if(j + 1 < n && !vis[i][j + 1] && m[i][j + 1] == 1){
        util(m,res,i, j+1, n, path + 'R');
    }
    
    // go up
    if(i - 1 >= 0 && !vis[i - 1][j] && m[i - 1][j] == 1){
        util(m,res,i-1, j, n, path + 'U');
    }
    vis[i][j] = false;
}



vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> res;
    if(m[0][0] == 0)return res;
    memset(vis, false, sizeof vis);
    util(m, res, 0, 0, n, "");
    return res;
}
