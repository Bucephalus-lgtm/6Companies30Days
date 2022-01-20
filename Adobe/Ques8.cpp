// https://practice.geeksforgeeks.org/problems/implement-atoi/1

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int num = 0;
        int neg = 1;
        int i = 0;
        if(str[0] == '-') {
            neg = -1;
            i++;
        }
        for(; i<str.size(); i++){
            char c = str[i];
            if(!isdigit(c)) return -1;
            num = num*10 + c - '0';
        }
        
        return num*neg;
    }
};