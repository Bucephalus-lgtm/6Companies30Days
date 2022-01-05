// https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1

class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string res;
        stack<int> st;
        int num = 1;
        for(int i=0; i<S.size(); i++){
            if(S[i] == 'D') st.push(num++);
            else {
                st.push(num++);
                
                while(!st.empty()){
                    res.push_back((char)(st.top()+'0'));
                    st.pop();
                }
            }
        }
        st.push(num);
        while(!st.empty()){
            res.push_back((char)(st.top()+'0'));
            st.pop();
        }
        return res;
    }
};