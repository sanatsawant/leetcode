class Solution {
public:
    bool isOneBitCharacter(vector<int>& v) {
        int n=v.size();
        int i=0;
        while(i<n-1){
            if(v[i]==0) i++;
            else if(v[i]==1) i+=2;
        }
        if(i!=n-1) return false;
        else return true;
        
    }
};