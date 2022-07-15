class Solution {
public:
    bool isMatch(string &s, string &p) {
        int n = s.size();
        int m = p.size();
        
        bool dp[n+2][m+2];
        dp[0][0] = true;
        
        for(int i=1;i<=n;i++){
            dp[i][0] = false;
        }
        
        for(int i=1;i<=m;i++){
            if(i>1 and p[i-1]=='*'){
                dp[0][i] = dp[0][i-2];
            }
            else{
                dp[0][i] = false;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((s[i-1]==p[j-1]) || (p[j-1]=='.')){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i][j-2];      //empty
                    
                    if((p[j-2]=='.' || p[j-2]==s[i-1])){
                        dp[i][j] |= dp[i-1][j];
                    }
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];
    }
};