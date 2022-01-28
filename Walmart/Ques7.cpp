// https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1

class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        if(N<3) return {};
        vector<int> res, leftMin(N, 0), rightMax(N, 0);
        leftMin[0] = arr[0];
        rightMax[N-1] = arr[N-1];
        for(int i=1; i<N; i++){
            leftMin[i] = min(arr[i], leftMin[i-1]);
        }
        for(int i=N-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], arr[i]);
        }
        for(int i=0; i<N; i++){
            if(arr[i] > leftMin[i] and arr[i] < rightMax[i]) {
                res.push_back(leftMin[i]);
                res.push_back(arr[i]);
                res.push_back(rightMax[i]);
                break;
            }
        }
        return res;
    }
};