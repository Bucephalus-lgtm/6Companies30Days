// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

class Solution{

  public:
	int minDifference(int arr[], int N)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0; i<N; i++) sum += arr[i];
	    int dp[N+1][sum+1];
	    for(int j=0; j<=sum; j++) dp[0][j] = false;
        for(int i=0; i<=N; i++) dp[i][0] = true;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=sum; j++){
                if(j >= arr[i-1]){
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        vector<int> temp(sum/2);
        for(int j=0; j<=sum/2; j++) 
            if(dp[N][j]) temp.push_back(j);
        int mn = INT_MAX;
        for(auto x: temp) mn = min(mn, sum-2*x);
	    return mn;
	} 
};