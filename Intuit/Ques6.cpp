// https://leetcode.com/problems/find-in-mountain-array

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0;
        int r = n-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                l = mid+1;
            } else {
                r = mid;
            }
        }
        int peak = l;
        l = 0;
        r = peak;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) < target) l = mid+1;
            else r = mid-1;
        }
        l = peak+1;
        r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) > target) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
};