// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

class Solution
{
public:
    bool isPossible(int n, vector<pair<int, int>> &prerequisites)
    {
        // Code here
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (auto c : prerequisites)
        {
            graph[c.second].push_back(c.first);
            indegree[c.first]++;
        }

        vector<int> toposort;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            toposort.push_back(curr);

            for (auto nbr : graph[curr])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        if (toposort.size() != n)
            return false;

        return true;
    }
};
