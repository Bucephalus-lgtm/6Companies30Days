// https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/

class Solution{
public:
    map<string, pair<int, string>> dp;
    string matrixChainOrder(int p[], int n){
        // code here
        return solve(p, 0, n - 1).second;
    }
    
    pair<int, string> solve(int p[], int l, int r) {
        if(l + 1 == r) return {0, "" + string(1, l + 'A')};
        string key = to_string(l) + ";" + to_string(r);
        if(dp.count(key)) return dp[key];
        
        int currMin = INT_MAX;
        string temp;
        for(int k = l + 1; k < r; k++) {
            auto p1 = solve(p, l, k), p2 = solve(p, k, r);
            if(p1.first + p2.first + p[l] * p[k] * p[r] < currMin) {
                currMin = p1.first + p2.first + p[l] * p[k] * p[r];
                temp = p1.second + p2.second;
            }
        }
        return dp[key] = {currMin, "(" + temp + ")"};
    }
};