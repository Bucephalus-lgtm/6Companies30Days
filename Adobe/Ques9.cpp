// https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1

class Solution{
  public:
    string nextPalin(string str) { 
        //complete the function here
        int n = str.size();
        if(n<=3) return "-1";
        string temp = str.substr(0, n/2);
        string ans = "";
        if(next_permutation(begin(temp), end(temp))){
            ans += temp;
            if(n%2) ans += str[n/2];
            reverse(begin(temp), end(temp));
            ans += temp;
            return ans;
        }
        return "-1";
    }
};