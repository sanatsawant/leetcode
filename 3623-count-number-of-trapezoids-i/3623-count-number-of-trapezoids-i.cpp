class Solution {
public:
    using ll=long long;
    ll M=1e9+7;
    int N=1e5+10;
    int powm(int a, int b) {
        if (b == 0) return 1;
        ll res = powm(a, b / 2); 
        res = (res * res) % M;  
        if (b & 1) {           
            res = (res * a) % M;
        }
        return res;
    }

    int countTrapezoids(vector<vector<int>>& v) {
        map<ll,ll> mp;
        for(auto t:v){
            int x=t[0];
            int y=t[1];
            mp[y]++;
        }
        int ans=0;
        ll s=0;
        for(auto [x,y]:mp){
           if(y>1){
                ll k=((y*(y-1))%M * powm(2,M-2))%M;
                if(s!=0){
                    ans=(ans + (k*s)%M)%M;
                }
                s=(s+k)%M;
           }
        }
        return ans;

        
    }
};