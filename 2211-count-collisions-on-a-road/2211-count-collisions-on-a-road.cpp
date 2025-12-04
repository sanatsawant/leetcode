class Solution {
public:
    int countCollisions(string s) {
        int  n = s.size();
        int ans = 0;
        for(int i = 0;i<n ; i++){
            if(s[i]!='S') ans++;
        }
        for(int i =0;i<n;i++) {
            if(s[i]=='L') ans--;
            else break;
        }
        for(int i =n-1;i>=0;i--){
            if(s[i]=='R') ans--;
            else break;
        }
        return ans;
    }
};