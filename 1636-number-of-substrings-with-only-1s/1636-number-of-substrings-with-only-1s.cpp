class Solution {
public:
    const int M=1e9+7;
    int numSub(string s) {
        int n=s.size();
        int ans=0;
        int pres=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                pres++;
                ans=(ans%M+pres%M)%M;
            }
            else pres=0;
        }
        return ans;
        
    }
};