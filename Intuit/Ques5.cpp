// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if(nums.empty() || m==0) return 0;
        int l = 0, r = 0;
        for(auto num : nums) {
            l = max(l, num);
            r += num; 
        }
        if(m == nums.size()) return l;
        if(m == 1) return r; 
        while(l < r) {
            int mid = l + (r-l)/2;
            int temp = 0, curr = 1;
            for(auto n : nums) {
                if(temp + n > mid) { 
                    curr++; 
                    temp = 0;
                }
                temp += n;
            } 
            if(curr > m) 
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};