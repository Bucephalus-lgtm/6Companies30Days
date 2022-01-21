// https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        vector<int> v;
        unordered_set<int> s;
        for(int i=0; i<M; i++) s.insert(B[i]);
        for(int i=0; i<N; i++){
            if(s.find(A[i]) != s.end()){
                auto it = lower_bound(begin(v), end(v), A[i]);
                if(it == v.end()){
                    v.push_back(A[i]);
                } else {
                    *it = A[i];
                }
            }
        }
        return N+M-2*v.size();
    }
};