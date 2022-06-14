class Solution {
public:
    int minDistance(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        int dp[n][m];        
        memset(dp,0,sizeof(dp));
        
        if(s1[0]==s2[0]){
            dp[0][0] = 1;
        }
        
        for(int i=1;i<n;i++){
            dp[i][0] = dp[i-1][0];
            if(s1[i]==s2[0]){
                dp[i][0] = 1;
            }
        }
        
        for(int i=1;i<m;i++){
            dp[0][i] = dp[0][i-1];
            if(s2[i]==s1[0]){
                dp[0][i] = 1;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(s1[i]==s2[j]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        
        int tp = dp[n-1][m-1];
        int ans = n-tp+m-tp;
        return ans;
    }
};