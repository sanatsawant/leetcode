class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        unordered_set<int> st;
        for(int i=1;i<=n;i++){
            int c=i*i;
            for(auto x:st){
                if(st.count(c-x)) ans++;
            }
            st.insert(c);
        }
        return ans;
    }
};