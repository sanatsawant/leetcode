class Solution {
public:
    int findFinalValue(vector<int>& v, int ori) {
        set<int> st;
        for(int i=0;i<v.size();i++){
            if(v[i]%ori == 0){
                int k=v[i]/ori;
                if((k&(k-1))==0){
                    st.insert(log2(k));
                }
            }
        }
        int l=0;
        for(auto x:st){
            cout<<x;
            if(x==l) l++;
            else break;

        }
        return ori*(1<<l);

        
    }
};