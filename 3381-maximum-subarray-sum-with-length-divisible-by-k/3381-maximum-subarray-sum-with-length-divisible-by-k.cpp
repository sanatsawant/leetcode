class Solution {
public:
    using ll=long long;
    long long maxSubarraySum(vector<int>& v, int kc) {
        int n=v.size();
        vector<ll> pres(n+1);
        for(int i=1;i<n+1;i++) pres[i]=pres[i-1]+v[i-1];
        ll mx=-1e15;
        ll s=0;
        for(int k=0;k<kc;k++){
            s=0;
            for(int i=k;i<n;i+=kc){
                int l=i;
                int r=l+kc-1;
                if(r>=n) break;
                s+=pres[r+1]-pres[l];
                mx=max(s,mx);
                if(s<0) s=0;
                
            }
        }
        
        return mx;

        
    }
};