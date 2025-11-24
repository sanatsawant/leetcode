class Solution {
public:
    using ll = long long;
    ll dp[10][2][10];
    string s;
    int len;
    ll rec(int idx,int hi,int cnt){
        if(idx==len) return cnt;
        if(dp[idx][hi][cnt]==-1){
            ll ans=0;
            int loLim=0;
            int hiLim=9;
            if(hi==1) hiLim=s[idx]-'0';

            for(int i=loLim;i<=hiLim;i++){
                ll nhi=hi;
                if(i!=s[idx]-'0') nhi=0;
                ll ncnt=cnt+(i==1);
                ans+=rec(idx+1,nhi,ncnt);
            }
            dp[idx][hi][cnt]=ans;

        }
        return dp[idx][hi][cnt];
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        s=to_string(n);
        len=s.size();
        return rec(0,1,0);


        
    }
};