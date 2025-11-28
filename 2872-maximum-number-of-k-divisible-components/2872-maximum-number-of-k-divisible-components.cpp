class Solution {
public:
    vector<int> g[30005];
    int vis[30005];
    int ans=0;
    int rec(int i,int k,vector<int>&v){
        int r=0;
        vis[i]=1;
        for(auto child:g[i]){
            if(vis[child]==0){
                int rem=rec(child,k,v);
                if(rem==0) ans++;
                else{
                    r+=rem;
                    r%=k;
                } 
            }  
        }
      
        return (v[i]+r)%k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        memset(vis,0,sizeof(vis));
        for(auto z:edges){
            int x=z[0];
            int y=z[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int a=rec(0,k,values);
        return ans+1;
        
        
    }
};