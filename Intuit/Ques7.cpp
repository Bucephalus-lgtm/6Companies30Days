// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    bool isPossible(vector<int>& weights, int mid, int days){
        int d = 1;
        int sum = 0;
        for(auto x: weights){
            sum += x;
            if(sum > mid){
                d++;
                sum = x;
            }
        }
        return d <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int mx = 0;
        for(auto x: weights){
            mx = max(mx, x);
            sum += x;
        }
        int l = mx;
        int r = sum;
        int ans;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isPossible(weights, mid, days)){
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};