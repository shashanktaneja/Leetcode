class Solution {
public:
    bool isMatch(string &s, string &s2) {
        int n = s.size();
        int m = s2.size();
        
        if(n==0 and m==0){
            return true;
        }
        
        if(m==0){
            return false;
        }
        
        if(n==0){
            for(int i=0;i<m;i++){
                if(s2[i]!='*'){
                    return false;
                }
            }
            
            return true;
        }
        
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        
        if((s[0]==s2[0]) || (s2[0]=='?' || s2[0]=='*')){
            dp[0][0] = true;
        }
        
        int cnt = 0;
        if(s2[0]!='*'){
            cnt++;
        }
        
        for(int i=1;i<m;i++){
            if((s[0]==s2[i] || (s2[i]=='?')) and cnt==0){
                cnt++;
                dp[0][i] = dp[0][i-1];
            }
            else if(s2[i]=='*'){
                dp[0][i] = dp[0][i-1];
            }
        }
        
        for(int i=1;i<n;i++){
            if(s2[0]=='*'){
                dp[i][0] = true;
            }
        }
                
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(s[i]==s2[j]){
                    dp[i][j] = dp[i-1][j-1];  
                }
                else{
                    if(s2[j]=='?'){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(s2[j]=='*'){
                        dp[i][j] = (dp[i][j-1]|dp[i-1][j]);
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[n-1][m-1];
    }
};