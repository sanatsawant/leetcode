class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> pen(n+1,0);
        vector<int> prepen(n+1,0);
        vector<int> sufpen(n+1,0);
        
        for(int i=1;i<n+1;i++){  
            if(customers[i-1]=='N'){
                prepen[i]=prepen[i-1]+1;
            }
            else prepen[i]=prepen[i-1];
        }
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){
                sufpen[i]=sufpen[i+1]+1;
            }
            else sufpen[i]=sufpen[i+1];
            
                
        }
        
        for(int i=0;i<n+1;i++){
            pen[i]=prepen[i]+sufpen[i];
        }
        int mini=n;
        for(int i=0;i<n+1;i++){
            mini=min(mini,pen[i]);
        }
        int i;
        for(i=0;i<n+1;i++){
            if(pen[i]==mini)return i;
        }
        return 1;
        
    }
};