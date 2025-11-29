class Solution {
public:
    using ll=long long;
    const int M=1e9+7;

    int powm(int a, int b) {
        if (b == 0) return 1;
        ll res = powm(a, b / 2); 
        res = (res * res) % M; 
        if (b & 1) {           
            res = (res * a) % M;
        }
        return res;
    }
    int countEffective(vector<int>& v) {
        int n=v.size();
        ll orall=0;
        
        vector<int> cnt(1<<20);
        for(auto x:v){
            orall|=x;
            cnt[x]++;
        }
        int h=(int)log2(orall) +1;
        for(int i=0;i<h;i++){
            for(int j=0;j<1<<h;j++){
               if(j & (1<<i)) cnt[j]+=cnt[j ^ (1<<i)];
            }
        }

        long long ans=0;
     
        for(int mask=0;mask<=orall-1;mask++){
            if((mask & orall) == mask){
                
                int z=__builtin_popcount(mask ^ orall);
                int ele=powm(2,cnt[mask]);
                //cout<<mask<<' '<<z<<' '<<ele<<'\n';
                if(z%2==1){
                    ans=(ans+ele)%M;
                }
                else{
                    ans=(ans-ele+M)%M;
                }

            }

        }
        return ans;


        
    }
};