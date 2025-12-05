class Solution {
public:
    int countPartitions(vector<int>& v) {
        int n=v.size();
        int sum=accumulate(v.begin(),v.end(),0);
        int ans=0;
        int s=0;
        for(int i=0;i<n-1;i++){
            s+=v[i];
            if((sum-s)%2==s%2) ans++;
        }
        return ans;
        
    }
};