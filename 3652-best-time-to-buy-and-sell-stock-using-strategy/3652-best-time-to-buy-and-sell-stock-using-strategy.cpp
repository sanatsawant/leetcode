class Solution {
public:
    long long maxProfit(vector<int>& p, vector<int>& s, int k) {
        int n=p.size();
        vector<long long> pres(n+1,0);
        vector<long long> q(n+1,0);
        long long ans=-1e18;
        for(int i=1;i<n+1;i++){
            pres[i]=pres[i-1]+p[i-1]*s[i-1];
            q[i]=q[i-1]+p[i-1];
        }
        for(int i=0;i<n;i++){
            int l=i;
            int r=l+k-1;
            if(r>=n) continue;
           
            long long sum=pres[n]-(pres[r+1]-pres[l])+(q[r+1]-q[r+1-k/2]);
           
            ans=max(ans, sum);
            
            
            
        }
        //cout<<ans;
        return max(pres[n],ans);
        
    }
};