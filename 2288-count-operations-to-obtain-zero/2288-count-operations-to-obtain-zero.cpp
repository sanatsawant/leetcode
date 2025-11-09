class Solution {
public:
    int countOperations(int n1, int n2) {
        int ans=0;
        int x=max(n1,n2),y=min(n1,n2);
        while(x && y){
            ans+=x/y;
            x-=(x/y * y);
            swap(x,y);
        }
        return ans;
        
        
    }
};