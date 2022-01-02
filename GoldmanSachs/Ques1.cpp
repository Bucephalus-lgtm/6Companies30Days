// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        
        int n = string_list.size();
        
        unordered_map<string, vector<string>> mp;
        
        for(int i=0; i<n; i++){
            string str = string_list[i];
            sort(str.begin(), str.end());
            mp[str].push_back(string_list[i]);
        }
        
        vector<vector<string>> res(mp.size());
        
        int index = 0;
        
        for(auto x: mp){
            auto y = x.second;
            for(auto c: y){
                res[index].push_back(c);
            }
            index++;
        }
        
        return res;
    }
};