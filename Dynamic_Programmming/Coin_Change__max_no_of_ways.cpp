
// TC - O(m * n) SC - O(m * n)

long long int count( int S[], int m, int n )
    {
    long long dp[m+1][n+1]; /// initialize a DP matrix
        
    for(int i = 0; i <= n; i++) dp[0][i] = 0;// 0th row with 0, as you cannot make any money with 0 coins
        
    for(int i = 0; i <= m; i++) dp[i][0] = 1; // You can make 0 Rs by choosing nothing.
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(S[i - 1] <= j)dp[i][j] = dp[i][j - S[i - 1]] + dp[i - 1][j]; // if the current coin demomination is less than the n(money)
                else dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[m][n];//last state of dp contains the answer
        
    }


****** YOU ONLY NEED TO ACCESS THE CURRENT ROW AND THE PREVIOUS STATE OF THE CURRENT CELL. SO THE SPACE COMPLEXITY CAN BE BOILED DOWN TO O(N)

// SC- O(N)

long long int count( int S[], int m, int n )
    {
        long long dp[n + 1];
        for(int i = 0; i <= n; i++)dp[i] = 0;
        dp[0] = 1;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(j >= S[i - 1])dp[j] += dp[j - S[i - 1]];
            }
        }
        
        return dp[n];//last state of dp contains the answer
        
    }
