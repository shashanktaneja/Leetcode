class Solution {
public:
    int maxProfit(vector<int>& v, int k) {
        int n = v.size();
        int dp[n+1];
        
        dp[0] = 0;
        int diff = -v[0];
        
        for(int i=1;i<n;i++){
            dp[i] = max(dp[i-1],diff+v[i]-k);
            diff = max(diff,dp[i]-v[i]);
        }
        
        return dp[n-1];
    }
};