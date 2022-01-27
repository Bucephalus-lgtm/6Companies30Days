https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1


class Solution{
    long long MOD = 1e9 + 7;
    public:
    //You need to complete this fucntion
    long long solve(int N, int R){
        if(R == 0) return 1;
        long long temp = power(N, R/2);
        temp = (temp*temp)%MOD;
        if(R%2) return temp*N;
        else return temp;
    }
    long long power(int N, int R)
    {
       //Your code here
        return solve(N, R) % MOD;
    }

};