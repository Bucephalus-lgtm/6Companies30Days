// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1/

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int, vector<int>, greater<int>> pq;
	    for(int i=0; i<n; i++){
	        pq.push(arr[i]);
	        if(pq.size() > k) pq.pop();
	    }
	    
	    vector<int> ans;
	    
	    while(!pq.empty()){
	        ans.push_back(pq.top());
	        pq.pop();
	    }
	    
	    sort(begin(ans), end(ans), greater<int>());
	    return ans;
	}

};