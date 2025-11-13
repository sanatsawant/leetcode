class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int len=0;
        int pres=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') len++;
            else{
                if(len){
                    pres+=len;
                    ans+=pres;
                    len=0;
                }
                
            }
        }
        return ans;
        
    }
};