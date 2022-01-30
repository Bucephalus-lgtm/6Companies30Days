https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool isPos = (divisor<0 == dividend<0);
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while(a >= b){
            int q = 0;
            while(a > (b<<(q+1)) ) q++;
            ans += (1<<q);
            a = a - (b << q);
        }
        if(ans == 1<<31 and isPos) return INT_MAX;
        return isPos ? ans : -ans;
    }
};