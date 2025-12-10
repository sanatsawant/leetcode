class Solution {
public:
    int MOD = 1e9+7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        if(n  == 0) return 0;
        int count = 0;
        for(int i=1; i<n; i++){
            if(complexity[0] >= complexity[i]) return 0;
        }
        long long fact = 1;
        for(int i=1; i<n; i++){
            fact = (fact * i) % MOD;
        }
        return fact;
    }
};
