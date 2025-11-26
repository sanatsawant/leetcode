class Solution {
public:
    using ll=long long;
    ll M=1e9+7;
    int n,m;
    int numberOfPaths(vector<vector<int>>& v, int k) {
        n=v.size();
        m=v[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        auto check=[&](int i,int j){
            return i>=0 && j>=0 && i<n && j<m;
        };
        function<int(int,int,int)> rec=[&](int i,int j,int cnt){
            if(i==n-1 && j==m-1 && (cnt+v[i][j])%k==0){
                return 1;
            }
            if(dp[i][j][cnt]==-1){
                int d=0,r=0;
                int ncnt=(v[i][j]+cnt)%k;
                if(check(i+1,j)){
                    d=rec(i+1,j,ncnt);
                }
                if(check(i,j+1)){
                    r=rec(i,j+1,ncnt);
                }
                dp[i][j][cnt]=(d%M+r%M)%M;

            }
            return dp[i][j][cnt];
        };
        return rec(0,0,0);
        
    }
};