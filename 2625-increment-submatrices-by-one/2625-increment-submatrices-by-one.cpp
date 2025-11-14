class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& v) {
        vector<vector<int>> pres(n,vector<int>(n,0));

        for(auto x:v){
            pres[x[0]][x[1]]++;
            if(x[2]+1<n) pres[x[2]+1][x[1]]--;
            if(x[3]+1<n) pres[x[0]][x[3]+1]--;
            if(x[2]+1<n && x[3]+1<n) pres[x[2]+1][x[3]+1]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pres[i][j]+=(i>0?pres[i-1][j]:0) + (j>0?pres[i][j-1]:0) - (i>0&&j>0?pres[i-1][j-1]:0);
            }
        }
        // for(auto i:pres){
        //     for(auto x:i){
        //         cout<<x<<' ';
        //     }
        //     cout<<"\n";
        // }
        return pres;
        
    }
};