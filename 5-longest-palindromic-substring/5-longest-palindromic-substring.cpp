class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int ans = 1;
        int dp[n][n];
        string tp = s.substr(0,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = -1;
            }
        }
        
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        
        int a=-1,b=-1;
        
        for(int len=2;len<=n;len++){
            for(int j=0;j<=n-len;j++){
                int st = j,e=j+len-1;
                if(s[st]==s[e]){
                    if((st+1==e) || (dp[st+1][e-1]!=-1)){
                        if((st+1)==e){
                            dp[st][e] = max(dp[st][e],2);
                        }
                        else{
                            dp[st][e] = max(dp[st][e],dp[st+1][e-1]+2);
                        }
                        
                        if(dp[st][e]>ans){
                            ans = dp[st][e];
                            a=st;
                            b=e;
                        }
                    }
                }                
            }
        }
        
        if(a!=-1 and b!=-1){
            tp = s.substr(a,b-a+1);
        }        
        
        return tp;
    }
};