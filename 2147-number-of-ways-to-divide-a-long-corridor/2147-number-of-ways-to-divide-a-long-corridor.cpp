class Solution {
public:
    int numberOfWays(string s) {
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='S'){
                ans++;
            }
        }
        if(ans%2==1||ans==0){
            return 0;
        }
        int c=0;
        int p=0;
        int ass=1;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='S'){
                c++;
            }
            if(c==2&&s[i]=='P'){
                p++;
            }
            if(c==3){
                c=1;
                ass=(ass*1LL*(p+1))%1000000007;
                p=0;
            }
        }
        return ass;
    }
};