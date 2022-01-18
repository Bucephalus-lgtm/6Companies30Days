// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<N; i++) sum += arr[i];
        if(sum%2) return 0;
        bool dp[sum/2 + 1] [N+1];
        for(int i=0; i<=sum/2; i++) dp[i][0] = false;
        for(int i=0; i<=N; i++) dp[0][i] = true;
        for(int i=1; i<=sum/2; i++){
            for(int j=1; j<=N; j++){
                if(arr[j-1] > i){
                    dp[i][j] = dp[i][j-1];
                } else {
                    dp[i][j] = dp[i][j-1] or dp[i-arr[j-1]][j-1];
                }
            }
        }
        return dp[sum/2][N];
    }
};