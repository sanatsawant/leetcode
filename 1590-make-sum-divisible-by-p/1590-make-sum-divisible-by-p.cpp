class Solution {
public:
    using ll=long long;
    int minSubarray(vector<int>& v, int p) {
        int n=v.size();
        unordered_map<int,int> mp;
        ll r=accumulate(v.begin(),v.end(),0ll);
        r%=p;
        if(r==0) return 0;
        ll s=0;
        int ans=1e9;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            s=(s+v[i]%p)%p;
            if(mp.count((s-r+p)%p)) ans=min(ans,i-mp[(s-r+p)%p]);
            mp[s]=i;
        }
        return (ans<n?ans:-1);
    }
};