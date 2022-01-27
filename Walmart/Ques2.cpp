// https://leetcode.com/problems/stone-game

class Solution {
public:
    int dp[501][501];
    int solve(vector<int> piles, int l, int r){
        if(l>r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        return  dp[l][r] = max(piles[l] - solve(piles, l+1, r), piles[r] - solve(piles, l, r-1));
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof dp);
        return solve(piles, 0, n-1) > 0;
    }
};