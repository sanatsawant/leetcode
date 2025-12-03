class Solution{
public:
    long long calc(unordered_map<int,unordered_map<int,unordered_map<int,int>>>&mp){
        long long ans=0;

        for(auto&[x,m1]:mp){
            for(auto&[y,m2]:m1){
                long long sum=0;
                for(auto&[key,val]:m2){
                    sum+=val;
                }

                for(auto&[key,val]:m2){
                    sum-=val;
                    ans+=val*sum;
                }
            }
        }
        return ans;
    }

    int countTrapezoids(vector<vector<int>>&points){
        unordered_map<int,unordered_map<int,unordered_map<int,int>>>a,b;

        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dx=points[i][0]-points[j][0];
                int dy=points[i][1]-points[j][1];

                if(dx<0||(dx==0 && dy<0)){
                    dx=-dx;
                    dy=-dy;
                }

                int g=gcd(dx,dy);

                int sx=dx/g;
                int sy=dy/g;

                int val=sx*points[i][1]-sy*points[i][0];

                a[sx][sy][val]++;
                b[dx][dy][val]++;
            }
        }
        return calc(a)-calc(b)/2;
    }
};