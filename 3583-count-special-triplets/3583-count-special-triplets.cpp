class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD = 1e9+7;
        unordered_map<int, int> left, right;
        for(int num : nums) {
            right[num]++;
        }
        long long ans = 0;
        for(int j=0; j<nums.size(); j++){
            int x = nums[j];
            right[x]--;
            if(j >= 1) {
                long long i = left[2*x];
                long long k = right[2*x];
                ans = (ans + (i*k) % MOD) % MOD;
            }
            left[x]++;
        }
        return ans;
    }
};