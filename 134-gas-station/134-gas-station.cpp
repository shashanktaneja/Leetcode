class Solution {
public:
    int canCompleteCircuit(vector<int>& v, vector<int>& c) {
        int n = c.size();
        int idx = -1;
        
        for(int i=0;i<n;i++){
            v[i] = (v[i]-c[i]);
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
        
        if(idx==-1){
            return -1;
        }
        
        csum = 0;
        
        for(int i=idx;i<n;i++){
            if(csum+v[i]<0){
                return -1;
            }
            csum += v[i];
        }
        
        for(int i=0;i<idx;i++){
            if(csum+v[i]<0){
                return -1;
            }
            csum += v[i];
        }
        
        return idx;
    }
};