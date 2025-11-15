class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> v(n);
        vector<int> pres(n+1);
        for(int i=1;i<=n;i++) pres[i]=pres[i-1]+(s[i-1]=='1');
        int ans=0;
        for(int i=0;i<n;i++){
            int j=i;
            int z=j-i+1 - (pres[j+1]-pres[i]);
            int one=(pres[j+1]-pres[i]);

            while(j<n){
                z=j-i+1 - (pres[j+1]-pres[i]);
                one=(pres[j+1]-pres[i]);
                //cout<<i<<' '<<z<<' '<<one<<' '<<j<<' '<<ans<<'\n';
                if(z*z == one){
                    ans++;
                    j++;
                }
                else if(z*z < one){
                    //ans++;
                    int k=ceil(sqrt(one))-z;
                    if(j+k>=n){
                        ans+=n-j;
                        break;
                    }
                    else{
                        j+=k;
                        ans+=k;

                    }
                }
                else{
                    int k=z*z-one;
                    if(j+k>=n) break;
                    else{
                        j+=k;
                      
                    }

                }

            }
            

        }
        return ans;
        
    }
};