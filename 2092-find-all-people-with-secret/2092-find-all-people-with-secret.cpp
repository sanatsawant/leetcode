const int N=1e5+10;
int par[N];

class Solution {

public:
    
   
    void make(int u){
        par[u]=u;
    }
    int find(int u){
        if(par[u]==u) return u;
        return par[u]=find(par[u]);
    }
    void Unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u!=v){
            if(v==0) swap(u,v);
            par[v]=u;

        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& m, int fp) {
        for(int i=0;i<N;i++){
            par[i]=-1;
      
        }
        map<int,vector<pair<int,int>>> mp;
        for(auto x:m){
            mp[x[2]].push_back({x[0],x[1]});
        }
        make(0);
        make(fp);
        Unite(0,fp);
        set<int> ans;
        ans.insert(0);
        ans.insert(fp);
        
        for(auto t:mp){
            unordered_set<int> st;
            auto v=t.second;
            for(auto [x,y]:v){
                if(par[x]==-1) make(x);
                if(par[y]==-1) make(y);
                st.insert(x);
                st.insert(y);
                Unite(x,y);
            }
            for(auto ele:st) par[ele]=find(ele);
            for(auto ele:st){
                if(par[ele]==0) ans.insert(ele);
            }
            for(auto [x,y]:v){
                if(par[x]!=0) par[x]=-1;
                if(par[y]!=0) par[y]=-1;
            }

        }
        vector<int> a;
        for(auto x:ans) a.push_back(x);
        return a;
    }
};