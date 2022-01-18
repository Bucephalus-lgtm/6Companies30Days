// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        if(s == 0) return {1,1};
        int l = 0;
        int r = 0;
        long long sum = 0;
        while(r<n){
            sum += arr[r];
            if(sum == s) return {l+1, r+1};
            if(sum > s) {
                while(sum > s){
                    sum -= arr[l];
                    l++;
                    if(sum == s) return {l+1, r+1};
                }
            }
            r++;
        }
        return {-1};
    }
};