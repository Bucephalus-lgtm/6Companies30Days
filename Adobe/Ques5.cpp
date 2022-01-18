// https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1

class Solution{
    public:
    long long int numOfWays(int n, int x)
    {
        // code here
        long long dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = dp[1] = 1;
        int maxWay = pow(n, 1.0/x);

        for(int i=2; i<=maxWay; i++){
            int result = pow(i, x);
            for(int j=n; j>=result; j--){
                dp[j] += dp[j-result];
            }
        }
        return dp[n];
    }
};