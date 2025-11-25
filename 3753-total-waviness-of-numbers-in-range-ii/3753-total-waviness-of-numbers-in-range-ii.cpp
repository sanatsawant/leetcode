class Solution {
public:
    using ll=long long;
    ll dp[16][2][10][10][16][4];
    int len;
    ll rec(string s,int idx,int hi,int p1,int p2,int cnt,int flag){
        //cout<<p1<<' '<<p2<<'\n';
        if(idx==s.size()) return cnt;
        if(dp[idx][hi][p1][p2][cnt][flag]==-1){
            int loLim=0;
            int hiLim=9;
            if(hi==1) hiLim=s[idx]-'0';
            ll ans=0;
            for(int i=loLim;i<=hiLim;i++){
                int nhi=hi;
                if(i!=s[idx]-'0') nhi=0;
                int ncnt=cnt;
                int np1=p2;
                int np2=i;
                
                if(flag>=2){
                    if(p1>p2 && p2<i) ncnt++;
                    else if(p1<p2 && p2>i) ncnt++;
                }
               
                int nflag=flag;
                if(flag==0 && i==0) nflag=0;
                else if(flag!=2) nflag++;
                ans+=rec(s,idx+1,nhi,np1,np2,ncnt,nflag);

                

            }
            dp[idx][hi][p1][p2][cnt][flag]=ans;

        }
        return dp[idx][hi][p1][p2][cnt][flag];

    }
    
        
    long long totalWaviness(long long n1, long long n2) {
        n1--;
        string L=to_string(n1);
        string R=to_string(n2);

        memset(dp,-1,sizeof(dp));
        ll r=rec(R,0,1,0,0,0,0);
        memset(dp,-1,sizeof(dp));
        ll l=rec(L,0,1,0,0,0,0);
        return r-l;


    
        
    }
};