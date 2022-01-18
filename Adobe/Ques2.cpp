// https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n<=2) return n;
        vector<unordered_map<int, int>> dp(n);
        int max_length = 2;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int diff = A[j] - A[i];
                if(dp[i].find(diff) != dp[i].end()){
                    dp[j][diff] = dp[i][diff] + 1;
                } else {
                    dp[j][diff] = 2;
                }
                max_length = max(max_length, dp[j][diff]);
            }
        }
        return max_length;
    }
};