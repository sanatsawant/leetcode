class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& v) {
        int n=v.size();
        auto cmp=[&](vector<int>&a ,vector<int>&b){
            return a[1]<b[1];
        };
        sort(v.begin(),v.end(),cmp);
        for(auto x:v) cout<<x[0]<<x[1]<<' ';
        set<int> st;
     
        for(int i=0;i<n;i++){
            int l=v[i][0];
            int r=v[i][1];
            if(st.size()==0){
                st.insert(r);
                st.insert(r-1);
            }
            else if(l>*st.rbegin()){
                st.insert(r);
                st.insert(r-1);
            }
            else if(l==*st.rbegin()){
                st.insert(r);
            }
            else if(*st.lower_bound(l)==*st.rbegin()){
                if(*st.rbegin()!=r) st.insert(r);
                else st.insert(r-1);
            }
        }
    
        return st.size();
    }
};