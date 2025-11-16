class Solution {
public:
    long long countDistinct(long long n) {
        string s=to_string(n);
        if(s.size()==1) return n;
        long long ans=0;
        long long c=9;
        for(int i=s.size()-1;i>=1;i--){
            ans+=c;
            c*=9ll;
            
        }
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0') break;
            ans+=(s[i]-'0'-1)*1ll*(pow(9ll,s.size()-i-1));
            if(i==s.size()-2){
                ans+=s[s.size()-1]-'0';
            }
         
        }
        
        return ans;
        
    }
};