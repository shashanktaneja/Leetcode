class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int z=0,o=0,t=0;
        
        for(int i=0;i<n;i++){
            if(v[i]==0){
                z++;
            }
            else if(v[i]==1){
                o++;
            }
            else{
                t++;
            }
        }
        
        int i=0;
        while(z>0){
            v[i] = 0;
            z--;
            i++;
        }
        
        while(o>0){
            v[i] = 1;
            o--;
            i++;
        }
        
        while(t>0){
            v[i] = 2;
            t--;
            i++;
        }        
    }
};