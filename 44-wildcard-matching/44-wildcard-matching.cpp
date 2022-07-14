class Solution {
public:
    bool isMatch(string &s, string &s2) {
        int n = s.size();
        int m = s2.size();
        
        bool dp[n+1][m+1];
        
        dp[0][0] = true;
        
        for(int i=1;i<=m;i++){
            dp[0][i] = (s2[i-1]=='*') ? dp[0][i-1] : false;
        }
        
        for(int i=1;i<=n;i++){
            dp[i][0] = false;
        }
                
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];  
                }
                else{
                    if(s2[j-1]=='?'){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(s2[j-1]=='*'){
                        dp[i][j] = (dp[i][j-1]|dp[i-1][j]);
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        return dp[n][m];
    }
};