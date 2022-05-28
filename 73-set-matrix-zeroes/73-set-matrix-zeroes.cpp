class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        
        bool c=false,r=false;
        
        for(int i=0;i<m;i++){
            if(v[i][0]==0){
                c = true;
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            if(v[0][i]==0){
                r = true;
                break;
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(v[i][j]==0){
                    v[i][0] = 0;
                    v[0][j] = 0;
                }
            }
        }
        
        for(int i=1;i<m;i++){
            if(v[i][0]==0){
                for(int j=1;j<n;j++){
                    v[i][j] = 0;
                }
            }
        }
        
        for(int j=1;j<n;j++){
            if(v[0][j]==0){
                for(int i=1;i<m;i++){
                    v[i][j] = 0;
                }
            }
        }
        
        if(c){
            for(int i=0;i<m;i++){
                v[i][0]=0;
            }
        }
        
        if(r){
            for(int i=0;i<n;i++){
                v[0][i]=0;
            }
        }        
    }
};