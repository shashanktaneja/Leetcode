class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        
        if(n==1){
            return 0;
        }
        
        int maxdiff = max(-v[0],-v[1]);
        
        if(v[1]>v[0]){
            dp[1] = v[1]-v[0];
        }
        
        for(int i=2;i<n;i++){
            dp[i] = dp[i-1];
            dp[i] = max(dp[i],maxdiff+v[i]);            
            maxdiff = max(maxdiff,dp[i-2]-v[i]);
        }
        
        return dp[n-1];
    }
};