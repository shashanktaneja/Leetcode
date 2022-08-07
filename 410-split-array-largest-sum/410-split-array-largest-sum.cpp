class Solution {
public:
    int splitArray(vector<int>& v, int m) {
        int n = v.size();
        int dp[1001][51];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j] = INT_MAX;
            }
        }
        
        dp[0][0] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int cur = 0;
                for(int k=i;k>0;k--){
                    cur += v[k-1];
                    dp[i][j] = min(dp[i][j],max(cur,dp[k-1][j-1]));
                }
            }
        }
        
        return dp[n][m];
    }
};