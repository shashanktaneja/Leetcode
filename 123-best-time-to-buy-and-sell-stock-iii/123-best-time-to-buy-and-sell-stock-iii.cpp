class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int dp[3][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=2;i++){
            int maxdiff = -v[0];
            for(int j=1;j<n;j++){
                dp[i][j] = max(dp[i][j-1], maxdiff+v[j]);
                maxdiff = max(maxdiff,(dp[i-1][j]-v[j]));
            }
        }
        
        return dp[2][n-1];
    }
};