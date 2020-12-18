int dp[101][101];
	    
	    int helper(string s, string t, int i, int n, int j, int m){
	        //BASE case..
	        if(i == n) return m - j; // Give string has been exhausted(only insertion is allowed)
	        if(j == m) return n - i; // Target string has been exhausted(only removal allowed)
	        
	        if(dp[i][j] != -1)return dp[i][j]; // Pre computed state....
	        
	        //Compute the state
	        
		if(s[i] == t[j])return dp[i][j] = helper(s, t, i + 1, n, j+1, m); // IF both the char are same,
	        
	        // 1.INSERT
	        // 2.REMOVE
	        // 3.REPLACE      
	        
	        int a1 = 1 + helper(s, t, i, n, j + 1, m);
	        int a2 = 1 + helper(s, t, i + 1, n ,j, m);
	        int a3 = 1 + helper(s, t, i + 1, n , j + 1, m);
	        
	        return dp[i][j] = min({a1, a2, a3});
	    }
	
	
	
		int editDistance(string s, string t)
		{
		    memset(dp, -1, sizeof dp);
		    return helper(s, t, 0, s.size(), 0, t.size());
		}
