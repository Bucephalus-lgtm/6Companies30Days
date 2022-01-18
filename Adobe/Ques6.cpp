// https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1

class Solution
{
    public:
    void backtrack(int n , int open, int close, string temp, vector<string>&res){
        if(open == n and close == n){
            res.push_back(temp);
            return;
        }
        if(open < n) backtrack(n, open+1, close, temp+"(", res);
        if(close < open) backtrack(n, open, close+1, temp + ")", res);
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        vector<string> ans;
        string temp;
        int open = 0;
        int close = 0;
        backtrack(n, open, close, temp, ans);
        return ans;
    }
};