class Solution {
public:
    using ll=long long;
    long long getDescentPeriods(vector<int>& v) {
        ll ans=0;
        int n=v.size();
        ll c=1;
        for(int i=1;i<n;i++){
            ans+=c;
            if(v[i-1]-v[i]==1){
                c++;
                
            }
            else{
                c=1;
            }
        }
        ans+=c;
        return ans;

        
    }
};