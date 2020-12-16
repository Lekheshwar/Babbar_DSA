// Complexity : Space : O(n) , time : O(n* n)
cpp_int findCatalan(int n) {
    vector<cpp_int> dp(n + 2);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}


// Complexity : Space : O(1) , time : O(n)
// use binomial coeff

cpp_int findCatalan(int n) {
    cpp_int cat = 1;
    for(cpp_int i = 1; i <= n ;i++){
        cat *= (4 * i - 2);
        cat /= (i + 1);
    }
    return cat;
}
