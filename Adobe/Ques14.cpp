// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          vector<pair<int, int>> v;
          for(int i=0; i<k; i++){
              for(int j=0;  j<n; j++){
                  v.push_back({KSortedArray[i][j], i});
              }
          }
          sort(begin(v), end(v));
          unordered_map<int, int> mp;
          int left = 0;
          int right = 0;
          vector<int> res;
          int lists = 0;
          while(right<k*n){
              if(mp[v[right].second]++ == 0){
                  lists++;
              }
              while(lists == k){
                  if(res.empty() or ((v[right].first - v[left].first) < (res[1]-res[0]))){
                      res = {v[left].first, v[right].first};
                  }
                  if(mp[v[left].second]-- == 1){
                      lists--;
                  }
                  left++;
              }
              right++;
          }
        //   for(auto x: res) cout << x << endl;
          return make_pair(res[0], res[1]);
    }
};