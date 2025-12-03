class Solution {
public:
    int search(vector<int>& v, int t) {
        int n=v.size();
        int lo=0;
        int hi=n-1;
        while(hi-lo>1){
            int mid=(lo+hi)/2;
            if(v[mid]>v[hi]) lo=mid;
            else hi=mid;
        }
        cout<<lo<<' '<<hi;
        int l=0;
        int h=lo;
        while(l<=h){
            int mid=(l+h)/2;
            if(v[mid]==t) return mid;
            else if(v[mid]<t) l=mid+1;
            else h=mid-1;
        }
        l=hi;
        h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(v[mid]==t) return mid;
            else if(v[mid]<t) l=mid+1;
            else h=mid-1;
        }
        return -1;

        
    }
};