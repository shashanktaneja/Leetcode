class Solution {
public:
    int mod = 1e9+7;
    int dp[10005][7][7];
    
    int solve(int pos,int pre,int cur,int n){
        if(pos==n-1){
            return 1;
        }
        
        if(dp[pos][pre][cur]!=-1){
            return dp[pos][pre][cur];
        }
        
        int ans = 0;
        
        for(int i=1;i<7;i++){
            if(i==pre){
                continue;
            }
            
            if(i!=cur and __gcd(i,cur)==1){
                ans = (ans+solve(pos+1,cur,i,n))%mod;
            }
        }
        
        return dp[pos][pre][cur] = ans;
    }

    int distinctSequences(int n) {
        int ans = 0;    
        memset(dp,-1,sizeof(dp));
        
        for(int i=1;i<7;i++){
            ans = (ans+solve(0,0,i,n))%mod;
        }
        
        return ans;
    }
};