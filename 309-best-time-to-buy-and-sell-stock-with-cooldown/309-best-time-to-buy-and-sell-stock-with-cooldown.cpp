class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<n;i++){
            dp[i] = dp[i-1];
            for(int j=0;j<i;j++){
                if(v[i]>v[j]){
                    if(j<2){
                        dp[i] = max(dp[i],v[i]-v[j]);
                    }
                    else{
                        dp[i] = max(dp[i],v[i]-v[j]+dp[j-2]);
                    }                    
                }
            }
        }
        
        return dp[n-1];
    }
};