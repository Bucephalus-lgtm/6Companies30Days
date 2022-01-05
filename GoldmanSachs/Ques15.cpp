// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums[i] = (nums[i])%k;
        }
        
        int temp[k] = {0};
        for(int i=0; i<n; i++){ 
            temp[nums[i]]++; 
        }
        if(temp[0]>0 and temp[0]%2) return false;
        for(int i=1; i<k; i++){
            if(temp[i] != temp[k-i]) return false;
        }
        return true;
    }
};