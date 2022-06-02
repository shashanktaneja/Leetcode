class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        
        vector<vector<int>> ans(n, vector<int> (m,0));
        
        int x=0,y=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = v[x][y];
                x++;
                if(x==m){
                    x=0;
                    y++;
                }
            }
        }
        
        return ans;
    }
};