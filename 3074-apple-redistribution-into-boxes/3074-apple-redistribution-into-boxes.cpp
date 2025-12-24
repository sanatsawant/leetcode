class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& v) {
        int sum=accumulate(apple.begin(),apple.end(),0);
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0;i<v.size();i++){
            sum-=v[i];
            if(sum<=0) return i+1;
        }
        return v.size();


        
    }
};