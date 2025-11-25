class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        string ans="0";
        long long sum=0;
        for(auto x:s){
            if(x!='0'){
                ans+=x;
                sum+=x-'0';
            }
        }
        return stoi(ans)*1ll*sum;
        
    }
};