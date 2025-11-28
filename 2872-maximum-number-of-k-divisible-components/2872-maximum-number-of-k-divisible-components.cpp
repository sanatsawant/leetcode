class Solution {
public:
    
    int ans=0;
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& v, int k) {
        vector<vector<int>> g(n+1);
        vector<int> vis(n+1);
        vector<int> cnt(n+1);
        for(auto z:edges){
            int x=z[0];
            int y=z[1];
            g[x].push_back(y);
            g[y].push_back(x);
            cnt[y]++;
            cnt[x]++;
        }
        cnt[0]++;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(cnt[i]==1) q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            cout<<x<<' '<<v[x]<<'\n';
            q.pop();
            if(v[x]%k==0) ans++;
            if(cnt[x]>=1){
                for(auto child:g[x]){
                    if(cnt[child]>=1){
                        v[child]+=v[x]%k;
                        if(cnt[child]<=2) q.push(child);
                        cnt[child]--;
                        cnt[x]--;

                    }
                    
                }

            }
            
        }
        return ans;
        
        
        
    }
};