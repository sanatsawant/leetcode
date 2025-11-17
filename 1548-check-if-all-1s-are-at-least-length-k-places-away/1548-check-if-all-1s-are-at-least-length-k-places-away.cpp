class Solution {
public:
    bool kLengthApart(vector<int>& v, int k) {
        int pos=-1;
        for(int i=0;i<v.size();i++){
            if(v[i]==1){
                if(pos!=-1){
                    if(i-pos-1<k) return false;
                    
                }
                pos=i;
            }
        }
        return true;
    }
};