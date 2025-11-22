class Solution {
public:
    int minimumOperations(vector<int>& v) {
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=min(v[i]%3,3-v[i]%3);
        }
        return ans;
        
    }
};