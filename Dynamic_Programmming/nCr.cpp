int nCr(int n, int r){
        if(r > n)return 0;
        
        vector<long> dp;
        long mod = 1000000007;
        
        for(int i = 0; i <= n; i++){
            vector<long> temp(i+1, 0);
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i)temp[j] = 1;
                else
                    temp[j] = (dp[j - 1] + dp[j]) % mod;
            }
            dp = temp;
        }
        return dp[r];
    }
