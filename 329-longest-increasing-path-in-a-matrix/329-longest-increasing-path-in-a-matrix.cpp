class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
        
    int dp[201][201];
    
    int solve(int i,int j,int m,int n,vector<vector<int>>& v){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans = 1;
        
        for(int k=0;k<4;k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            
            if(nx>=0 and ny>=0 and nx<m and ny<n and v[nx][ny]>v[i][j]){
                int cur = 1+solve(i+dx[k],j+dy[k],m,n,v);
                ans = max(ans,cur);
            }
        }
            
            
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = -1;
            }
        }
        
        int ans = 1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1){
                    solve(i,j,m,n,v);                    
                }
                ans = max(ans,dp[i][j]);
            }
        }
                
        return ans;
    }
};