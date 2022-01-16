// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

class Solution
{

public:
    bool vis[100000];
    bool check(int node, vector<int> adj[], int d)
    {
        if (node == d)
            return 1;
        if (vis[node])
            return 0;
        vis[node] = 1;
        for (int e : adj[node])
            if (check(e, adj, d))
                return 1;
        return 0;
    }
    // Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        // Code here
        memset(vis, 0, V);
        vis[c] = 1;
        for (int e : adj[c])
            if (e != d && check(e, adj, d))
                return 0;
        return 1;
    }
};