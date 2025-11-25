class Solution {
public:
    int maxBalancedSubarray(vector<int>& v) {
        int n=v.size();
        vector<int> diff(n+1);
        for(int i=1;i<n+1;i++){
            diff[i]=diff[i-1] + (v[i-1]&1?1:-1);
        }
        map<pair<int,int>,int> mp;
    
        int x=0;
        int ans=0;
        for(int i=0;i<n;i++){
            x^=v[i];
            if(x==0){
                if(diff[i+1]==0) ans=max(ans,i+1);

            }
            if(mp.count({x,diff[i+1]})){
                ans=max(ans,i-mp[{x,diff[i+1]}]);
            }
            else{
                mp[{x,diff[i+1]}]=i;
            }
        }
        return ans;
        
    }
};