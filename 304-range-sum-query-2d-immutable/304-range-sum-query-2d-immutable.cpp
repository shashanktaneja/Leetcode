class NumMatrix {
public:
    int v[201][201];
    int m,n;
    
    NumMatrix(vector<vector<int>>& tp) {
        m = tp.size();
        n = tp[0].size();   
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum+=tp[0][i];
            v[0][i] = sum;
        }
        
        for(int i=1;i<m;i++){ 
            int s=0;    
            for(int j=0;j<n;j++){
                s+=tp[i][j];
                v[i][j] = s+v[i-1][j];
            }       
        }           
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {        
        int ans = v[r2][c2];
        if(r1-1>=0 and c1-1>=0){
            ans+=v[r1-1][c1-1];
        }
        
        if(r1-1>=0){
            ans-=v[r1-1][c2];
        }
        
        if(c1-1>=0){
            ans-=v[r2][c1-1];
        }
                
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */