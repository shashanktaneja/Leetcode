class NumMatrix {
public:
    vector<vector<int>> v;
    int m,n;
    
    NumMatrix(vector<vector<int>>& tp) {
        v.clear();
        m = tp.size();
        n = tp[0].size();
        
        
        for(int i=0;i<m;i++){
            vector<int> temp;
            int s=0;
            for(int j=0;j<n;j++){
                s+=tp[i][j];
                temp.push_back(s);
            }       
            v.push_back(temp);
        }           
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {        
        int ans = 0;
        
        for(int i=r1;i<=r2;i++){
            ans+=v[i][c2];
            if(c1-1>=0){
                ans-=v[i][c1-1];
            }
        }
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */