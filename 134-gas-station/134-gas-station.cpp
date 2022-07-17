class Solution {
public:
    int canCompleteCircuit(vector<int>& v, vector<int>& c) {
        int n = c.size();
        int idx = -1;
        int tp = 0;
        
        for(int i=0;i<n;i++){
            v[i] = (v[i]-c[i]);
            tp+=v[i];
        }
        
        if(tp<0){
            return -1;
        }
        
        int i=0;
        int csum = 0;
        
        while(i<n){
            if(v[i]>=0){
                idx = i;
                while(i<n){
                    if(csum+v[i]<0){
                        idx = -1;
                        csum = 0;
                        break;
                    }
                    csum += v[i];
                    i++;
                }
            }
            
            i++;
        }
        
        return idx;
    }
};