// https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1

class Solution{
public:
    int height(int N){
        // code here
        return (-1 + sqrt(1 + 8*N))/2;
    }
};