class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int z=0,o=0,t=n-1;
        
        while(o<=t){
            if(v[o]==0){
                swap(v[o],v[z]);
                z++;
                o++;
            }
            else if(v[o]==1){
                o++;
            }
            else{
                swap(v[o],v[t]);
                t--;
            }
        }      
    }
};