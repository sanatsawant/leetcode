class Solution {
public:
    
    int ans=0;
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& v, int k) {
        vector<vector<int>> g(n+1);
        vector<int> vis(n+1);
        for(auto z:edges){
            int x=z[0];
            int y=z[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        auto rec=[&](auto self,int i)->int{
            int r=0;
            vis[i]=1;
            for(auto child:g[i]){
                if(vis[child]==0){
                    int rem=self(self,child);
                    r+=rem;
                    r%=k;
                    
                }  
            }
            if((v[i]+r)%k == 0) ans++;
            return (v[i]+r)%k;
        };
        int a=rec(rec,0);
        return ans;
        
        
    }
};