// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/

class Solution
{

public:
    int minDifference(int arr[], int N)
    {
        // Your code goes here
        int sum = accumulate(arr, arr + N, 0LL);
        bool dp[N + 1][sum + 1];
        vector<int> v(sum / 2);
        int mn = INT_MAX;
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        for (int i = 0; i <= sum / 2; i++)
        {
            if (dp[N][i])
                v.push_back(i);
        }

        for (int i = 0; i < v.size(); i++)
        {
            mn = min(mn, sum - 2 * v[i]);
        }

        return mn;
    }
};