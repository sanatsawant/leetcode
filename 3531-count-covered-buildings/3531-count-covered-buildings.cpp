class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& v) {
        vector<vector<int>> X(n+5,vector<int>(2,0)),Y(n+5,vector<int>(2,0));
        for(int i=1;i<n+5;i++){
            X[i][0]=1e9;
            Y[i][0]=1e9;
        }
        for(auto k:v){
            int x=k[0];
            int y=k[1];
            X[x][0]=min(y,X[x][0]);
            X[x][1]=max(y,X[x][1]);
            Y[y][0]=min(x,Y[y][0]);
            Y[y][1]=max(x,Y[y][1]);
           
        }
        int ans=0;
        for(auto k:v){
            int x=k[0];
            int y=k[1];
            int lox=Y[y][0];
            int hix=Y[y][1];
            int loy=X[x][0];
            int hiy=X[x][1];
            if(lox<x && x<hix && loy<y && y<hiy) ans++;
         
        }
        return ans;
        
    }
};