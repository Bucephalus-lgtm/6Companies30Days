// https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string temp1 = str1 + str2;
        string temp2 = str2 + str1;
        if(temp1 == temp2){
            int str1_size = str1.size();
            int str2_size = str2.size();
            int length = gcd(str1_size, str2_size);
            return temp1.substr(0, length);
        } 
        return "";
    }
};