class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][0]==1 || grid[m-1][n-1]==1){
            return 0;
        }
        
        int dp[m+1][n+1];
        
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        
        for(int i=1;i<m;i++){
            if(grid[i][0]==1 || dp[i-1][0]==-1){
                dp[i][0] = -1;
            }
            else{
                dp[i][0] = 1;
            }
        }
        
        for(int i=1;i<n;i++){
            if(grid[0][i]==1 || dp[0][i-1]==-1){
                dp[0][i] = -1;
            }
            else{
                dp[0][i] = 1;
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1 || (dp[i-1][j]==-1 and dp[i][j-1]==-1)){
                    dp[i][j] = -1;
                }
                else{
                    int op1 = dp[i-1][j];
                    int op2 = dp[i][j-1];
                    
                    if(op1!=-1){
                        dp[i][j] += op1;
                    }
                    if(op2!=-1){
                        dp[i][j] += op2;
                    }                    
                }
            }
        }
        
        return dp[m-1][n-1]<0 ? 0 : dp[m-1][n-1];       
    }
};