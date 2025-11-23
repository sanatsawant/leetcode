class Solution {
public:
    int dp[40005][3];
    int maxSumDivThree(vector<int>& v) {
        int n=v.size();
     
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j < 3; ++j) {
                dp[i][j] =-1e9;
            }
        }
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                int nr=(j-v[i-1]%3+3)%3;
                int take=v[i-1]+dp[i-1][nr];
                int nt=dp[i-1][j];
                dp[i][j]=max(take,nt);
            }
        }
        return dp[n][0];

        
    }
};