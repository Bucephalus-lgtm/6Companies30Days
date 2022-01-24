// https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

class Solution
{
    public:
    
    void solve(string str, int n, string& ans, int k, int index){
        if(k == 0) return;
        char maxChar = str[index];
        for(int i=index+1; i<n; i++)
            if(maxChar < str[i]) maxChar = str[i];
        if(maxChar != str[index]) k--;    
        for(int i=n-1; i>=index; i--){
            if(str[i] == maxChar){
                swap(str[i], str[index]);
                if(ans < str) ans = str;
                solve(str, n, ans, k, index+1);
                swap(str[i], str[index]);
            }
        }    
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
       int n = str.size();
       int index = 0;
       solve(str, n, ans, k, index);
       return ans;
    }
};