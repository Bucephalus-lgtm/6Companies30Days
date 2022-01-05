// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        for(int i=0; i<n; i++){
            if(mp[arr[i]] > 1) {
                ans[0] = arr[i];
                break;
            }
        }
        for(int i=1; i<=n; i++){
            if(!mp.count(i)) {
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
};
