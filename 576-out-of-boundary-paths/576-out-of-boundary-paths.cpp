class Solution {
public:
    int mod = 1e9+7;
    int dp[51][51][51];
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    int solve2(int m, int n, int k, int i, int j){
        if(i<0 || j<0 || i==m || j==n){
            return 1;
        }
                    
        if(k==0){
            return 0;
        }
        
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        
        int ans = 0;
        
        for(int a=0;a<4;a++){
            int nx = i+dx[a];
            int ny = j+dy[a];
            ans = (ans + solve2(m,n,k-1,nx,ny))%mod;
        }
        return dp[i][j][k] = ans;
    }
    
    int findPaths(int m, int n, int k, int i, int j) {
        memset(dp,-1,sizeof(dp));
        int ans = solve2(m,n,k,i,j);        
        return ans;
    }
};