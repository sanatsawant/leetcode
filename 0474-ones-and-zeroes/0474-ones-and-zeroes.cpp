class Solution {
public:
    int dp[1000][110][110];
    int findMaxForm(vector<string>& s, int m, int n) {
        memset(dp, 0, sizeof(dp));

        auto cnt=[](string s,char x){
            return count(s.begin(),s.end(),x);
        };
        vector<pair<int,int>> v;
        for(auto x:s){
            v.push_back({cnt(x,'0'),cnt(x,'1')});
        }
        for(int i=1;i<=v.size();i++){
            auto [x,y]=v[i-1];
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k]=dp[i-1][j][k];
                    if(j-x>=0 && k-y>=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-x][k-y]+1);
                     
                }
            }
        }
        return dp[v.size()][m][n];
       
       
        
    }
};