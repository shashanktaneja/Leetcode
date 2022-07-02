class Solution {
public:
    int maxProfit(int k, vector<int>& v) {
        int n = v.size();
        int dp[k+1][n+1];
        memset(dp,0,sizeof(dp));
        
        if(n==0){
            return 0;
        }
        
        for(int i=1;i<=k;i++){
            int maxdiff = -v[0];
            for(int j=1;j<n;j++){
                dp[i][j] = max(dp[i][j-1],maxdiff+v[j]);
                maxdiff = max(maxdiff,dp[i-1][j]-v[j]);
            }
        }
        
        return dp[k][n-1];
    }
};