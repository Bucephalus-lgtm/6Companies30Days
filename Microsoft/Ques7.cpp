// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1

class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        int r = grid.size();
        int c = grid[0].size();
        if (i < 0 or i >= r or j < 0 or j >= c or grid[i][j] == 0)
            return 0;
        int count = 1;
        grid[i][j] = 0;
        count += dfs(grid, i, j + 1);
        count += dfs(grid, i, j - 1);
        count += dfs(grid, i + 1, j);
        count += dfs(grid, i - 1, j);
        count += dfs(grid, i + 1, j + 1);
        count += dfs(grid, i + 1, j - 1);
        count += dfs(grid, i - 1, j + 1);
        count += dfs(grid, i - 1, j - 1);
        return count;
    }

    // Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>> &grid)
    {
        // Code here
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j])
                    ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};