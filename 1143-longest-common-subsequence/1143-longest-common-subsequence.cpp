class Solution {
public:
    int longestCommonSubsequence(string s, string s2) {
        int m = s.size();
        int n = s2.size();
        
        int dp[m+2][n+2];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=m;i++){
            if(s[i-1]==s2[0]){
                dp[i][1] = 1;
            }
            else{
                dp[i][1] = dp[i-1][1];
            }
        }
        
        for(int i=1;i<=n;i++){
            if(s2[i-1]==s[0]){
                dp[1][i] = 1;
            }
            else{
                dp[1][i] = dp[1][i-1];
            }
        }
        
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                if(s[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        
        return dp[m][n];
    }
};