class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        map<char,int> mp;
        mp[s[0]]++;
        mp[s[1]]++;
        int ans=0;
        for(auto x='a';x<='z';x++){
            int l=-1,r=-1;
            for(int i=0;i<n;i++){
                if(s[i]==x){
                    if(l==-1) l=i;
                    r=i;
                } 
            }
            if(l==-1 || r==-1 || r-l<=1) continue;
            unordered_set<char> uni;
            for(int i=l+1;i<=r-1;i++){
                uni.insert(s[i]);
            }
            ans+=uni.size();
        }
        return ans;
        
    }
};