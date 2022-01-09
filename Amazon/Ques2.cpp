// https://leetcode.com/problems/longest-mountain-in-array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int count;
        int ans = 0;
        for(int i=1; i<n; i++){
            bool flag = false;
            int j = i;
            count = 1;
            while(j<n and arr[j] > arr[j-1]){
                j++;
                count++;
            }
            while(i!=j and j<n and arr[j] < arr[j-1]){
                j++;
                count++;
                flag = true;
            }
            if(i!=j and flag and count>2){
                ans = max(ans, count);
                j--;
            }
            i = j;
        }
        return ans;
    }
};