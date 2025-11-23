class Solution {
public:
    int maxSumDivThree(vector<int>& v) {
        int n=v.size();
        int a=1e9,b=1e9,c=1e9,d=1e9;
        int ans=0;
        for(auto x:v){
            ans+=x;
            if(x%3==1){
                if(x<=a){
                    b=a;
                    a=x;
                }
                else if(x<=b) b=x;
            }
            else if(x%3==2){
                if(x<=c){
                    d=c;
                    c=x;
                }
                else if(x<=d) d=x;
            }
        }

        if(ans%3==1){
            int k=0;
            if(a!=-1) k=ans-a;
            if(d!=-1) k=max(k,ans-c-d);
            return k;
        }
        else if(ans%3==2){
            int k=0;
            if(c!=-1) k=ans-c;
            if(b!=-1) k=max(k,ans-a-b);
            return k;
        }
        return ans;
        
    }
};