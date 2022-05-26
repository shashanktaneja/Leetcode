class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        set<int> r,c;
        int m = v.size();
        int n = v[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        
        for(auto cur:r){
            for(int i=0;i<n;i++){
                v[cur][i] = 0;
            }
        }
        
        for(auto cur:c){
            for(int i=0;i<m;i++){
                v[i][cur] = 0;
            }
        }
        
    }
};