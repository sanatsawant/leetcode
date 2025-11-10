class Solution {
public:
    int minOperations(vector<int>& v) {
        int n=v.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && v[i]<st.top()){
                st.pop();
            }
            if(v[i]!=0 && st.empty()) ans++;
            else if(!st.empty() && st.top()<v[i]) ans++;
            st.push(v[i]);
        }
     
        return ans;
        
    }
};