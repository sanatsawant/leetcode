class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int ans=0;
        if(k%2==0) return -1;
        string n=string(to_string(k).size(),'1');
        long long a=stoi(n);
        ans=to_string(k).size();
        unordered_set<int> st;
        for(int i=0;i<1e5;i++){
            a%=k;
            if(a==0) return ans;
            else if(st.count(a)) return -1;
            st.insert(a);
            a*=10;
            a+=1;
            ans++;
        }
        return -1;
        
    }
};