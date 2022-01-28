// https://leetcode.com/problems/guess-number-higher-or-lower-ii

class Solution {
public:
    int dp[201][201];
    int solve(int l, int r){
        if(l>=r) return 0;
        int ans = INT_MAX;
        if(dp[l][r] != -1) return dp[l][r];
        for(int i=l; i<=r; i++) {
            ans = min(ans, i + max(solve(l, i-1), solve(i+1, r)));
        }
        return dp[l][r] = ans;
    }
    
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof dp);
        return solve(1, n);
    }
};