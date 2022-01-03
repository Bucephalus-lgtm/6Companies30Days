// https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull dp[n+1];
	    dp[0] = 1;
	    
	    int j=0, k=0, l=0;
	    ull next_multiple_of_2 = 2;
	    ull next_multiple_of_3 = 3;
	    ull next_multiple_of_5 = 5;
	    ull ans = 1;
	    
	    for(int i=1; i<n; i++){
	        ans = min({next_multiple_of_2, next_multiple_of_3, next_multiple_of_5});
	        dp[i] = ans;
	        if(ans == next_multiple_of_2) next_multiple_of_2 = dp[++j]*2;
	        if(ans == next_multiple_of_3) next_multiple_of_3 = dp[++k]*3;
	        if(ans == next_multiple_of_5)next_multiple_of_5 = dp[++l]*5;
	    }
	    
	    return ans;
	    
	}
};
