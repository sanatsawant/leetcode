class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        unordered_set<int> st;
        int n=v.size();
        int m=v[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(st.count(j)) continue;
                if(v[i-1][j]<v[i][j]) break;
                else if(v[i-1][j]>v[i][j]){
                    st.insert(j);
                    i=0;
                    break;
                }
            }
        }
        return st.size();

    
       
        
    }
};