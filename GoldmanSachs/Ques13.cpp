// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

class Solution{
public:
    string solve(string s, int& i){
        string res = "";
        int num = 0;
        for(; i<s.size(); i++){
            char c = s[i];
            if(isalpha(c)) res += c;
            else if(isdigit(c)) num = num*10 + c - '0';
            else if(c == ']') return res;
            else {
                string temp = solve(s, ++i);
                while(num--) res += temp;
                num = 0;
            }
        }
        return res;
    }
    
    
    string decodedString(string s){
        // code here
        int i = 0;
        return solve(s, i);
    }
};