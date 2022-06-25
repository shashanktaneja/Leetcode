class Solution {
public:
    bool val(vector<int> &v){
        int n = v.size();
        int i=0;
        while(i<n-1){
            if(v[i]<=v[i+1]){
                i++;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
    
    bool checkPossibility(vector<int>& v) {
        int n = v.size();
        int i=0;
        
        if(val(v)){
            return true;
        }
        
        while(i<n-1){
            if(v[i]<=v[i+1]){
                i++;
                continue;
            }
            
            int tp = v[i];
            v[i] = v[i+1];
            if(val(v)){
                return true;
            }
            else{
                v[i] = tp;
                v[i+1] = v[i];
                if(val(v)){
                    return true;
                }
            }
            break;
        }        
        
        
        return false;        
    }
};