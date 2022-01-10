// https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/

class Solution
{
public:
    string colName(long long int n)
    {
        // your code here
        string res = "";
        while (n--)
        {
            int r = n % 26;
            res = string(1, r + 'A') + res;
            n /= 26;
        }
        return res;
    }
};