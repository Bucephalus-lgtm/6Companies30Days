// https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        map<string, int> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        map<string, int>::iterator it;
        int mx = 0;
        string res;
        for(it = mp.begin(); it!=mp.end(); it++){
            if(mx < it->second){
                mx = it->second;
                res = it->first;
            }
        }
        
        return {res, to_string(mx)};
    }
};