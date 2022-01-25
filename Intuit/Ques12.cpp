// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    bool detectCycle_util(vector<vector<int>>& adj,vector<int>& visited,int v)
    {
        if(visited[v]==1) return true;
        if(visited[v]==2) return false;
        visited[v]=1;  
        for(int i=0;i<adj[v].size();++i)
            if(detectCycle_util(adj,visited,adj[v][i]))
                return true;      
        visited[v]=2;  
        return false;
    }
    bool detectCycle(vector<vector<int>>& adj, int n)
    {
        vector<int> visited(n,0);
        for(int i=0;i<n;++i)
            if(!visited[i])
                if(detectCycle_util(adj,visited,i))
                    return true;
        return false;
    }
    
    void dfs(vector<vector<int>>& adj, int v, vector<bool>& visited, stack<int>& st)
    {
        visited[v] = true;
        for(int i=0; i<adj[v].size(); ++i)
            if(!visited[adj[v][i]])
                dfs(adj, adj[v][i], visited, st);
        
        st.push(v);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<n;++i)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        vector<int> ans;
        if(detectCycle(adj,numCourses)) return ans;        
        stack<int> st;
        vector<bool> visited(numCourses, false);
        for(int i=0; i<numCourses; ++i)
            if(!visited[i])
                dfs(adj,i,visited,st);      
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};