class Solution {
public:
    int ans;
    
    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();
        int dp[2][n+1];
        
        dp[0][0] = v[0][0];
        
        for(int i=1;i<n;i++){
            dp[1][0] = dp[0][0] + v[i][0];
            for(int j=1;j<i;j++){
                dp[1][j] = v[i][j] + min(dp[0][j],dp[0][j-1]);
            }
            dp[1][i] = v[i][i] + dp[0][i-1];
            for(int j=0;j<=i;j++){
                dp[0][j] = dp[1][j];
            }
        }
        
        ans = INT_MAX;
        
        for(int i=0;i<n;i++){
            ans = min(ans,dp[0][i]);
        } 
    
        return ans;
    }
};