// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution {
public:
    int MOD = 1e9+7;
    
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[0] > b[0];
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> v;
        for(int i=0; i<n; i++){
            v.push_back({efficiency[i], speed[i]});
        }
        sort(begin(v), end(v), compare);
        priority_queue<int, vector<int>, greater<int>> pq;
        long long totalSpeed = 0;
        long long ans = INT_MIN;
        for(auto x: v) {
            if(pq.size() == k) {
                totalSpeed -= pq.top();
                pq.pop();
            }
            pq.push(x[1]);
            totalSpeed += x[1];
            ans = max(ans, totalSpeed * x[0]);
        }
        return (long long)ans%MOD;
    }
};