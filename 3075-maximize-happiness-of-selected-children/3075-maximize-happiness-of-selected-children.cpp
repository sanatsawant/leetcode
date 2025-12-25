class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        long long ans=0;
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0;i<k;i++){
            ans+=max(0,v[i]-i);
        }
        return ans;
        
    }
};