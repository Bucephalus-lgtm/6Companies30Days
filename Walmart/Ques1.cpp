// https://leetcode.com/problems/path-with-maximum-probability

class Solution {
public:
    double maxtempbility(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> g(n);
        for(int i=0; i<edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});   
        }
        vector<int> visited(n, 0);
        
        priority_queue<pair<double, int>> q;
        q.push({(double)1.0, start});
        
        vector<double> mx(n, (double)0.0);
        mx[start] = 1.0;
        
        while(!q.empty()) {
            auto top = q.top();
            q.pop();
            double temp = top.first;
            int node = top.second;
            if(!visited[node]) {
                visited[node]++;
                for(auto &to: g[node]) {
                    if (mx[to.first] < to.second*temp) {
                        mx[to.first] = to.second*temp;
						q.push({mx[to.first], to.first});
                    }
                }
            }
        }
        return mx[end];
    }
};