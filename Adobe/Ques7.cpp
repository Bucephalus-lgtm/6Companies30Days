// https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1

class Solution
{
public:
    int solve(vector<int> &nums, vector<vector<int>> &dp, int start, int end)
    {
        if (start > end)
            return dp[start][end] = 0;
        if (start == end)
            return dp[start][end] = nums[start];
        if (dp[start][end] != -1)
            return dp[start][end];

        int left = nums[start] + min(solve(nums, dp, start + 2, end), solve(nums, dp, start + 1, end - 1));
        int right = nums[end] + min(solve(nums, dp, start + 1, end - 1), solve(nums, dp, start, end - 2));

        return dp[start][end] = max(left, right);
    }

    int maxCoins(vector<int> &A, int n)
    {
        // Write your code here
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(A, dp, 0, n - 1);
    }
};