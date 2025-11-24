class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& v) {
        int n=v.size();
        vector<bool> ans(n,false);
        int x=0;
        int p=1;
        for(int i=0;i<n;i++){
            x+=v[i];
            if(x%5==0) ans[i]=true;
            x*=2;
            x%=5;
        }
    
        return ans;
        
        
    }
};