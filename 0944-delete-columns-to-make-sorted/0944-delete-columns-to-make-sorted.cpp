class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        int n=v.size();
        int m=v[0].size();
        int c=0;
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                if(v[i-1][j]>v[i][j]){
                    c++;
                    break;
                }
            }
        }
        return c;
        
    }
};