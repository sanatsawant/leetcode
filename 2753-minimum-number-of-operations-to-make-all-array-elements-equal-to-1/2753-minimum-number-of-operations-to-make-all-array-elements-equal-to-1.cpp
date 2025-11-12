class Solution {
public:
    int minOperations(vector<int>& v) {
        int n=v.size();
        int mn=n+1;
        int c=count(v.begin(),v.end(),1);
        if(c) c--;
        for(int i=0;i<n;i++){
            int g=0;
            for(int j=i;j<n;j++){
                g=__gcd(g,v[j]);
                if(g==1){
                    mn=min(mn,j-i+1);
                    break;
                }
            }
        }
        return mn!=n+1?mn-1+n-1-c:-1;
        
    }
};