//     


void dfs(vector<vector<int>>& img, int x, int y, int nc, int oc, int n, int m){
        img[x][y] = nc;
        
        // up
        if(x - 1 >= 0 && img[x - 1][y] == oc)
            dfs(img, x - 1, y, nc, oc, n, m);
        
        // right
        if(y + 1 < m && img[x][y + 1] == oc)
            dfs(img, x, y + 1, nc, oc, n, m);
        
        // down
        if(x + 1 < n && img[x + 1][y] == oc)
            dfs(img, x + 1, y, nc, oc, n, m);
        
        // left
        if(y - 1 >= 0 && img[x][y - 1] == oc)
            dfs(img, x, y - 1, nc, oc, n, m);
        
        return;
    }
    
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
	 // if the new color is equall to the old color. Then it may go into a infinte loop.
        if(newColor == image[sr][sc])return image;
        
        dfs(image, sr, sc, newColor, image[sr][sc], image.size(), image[0].size());
        
        return image;

    }
