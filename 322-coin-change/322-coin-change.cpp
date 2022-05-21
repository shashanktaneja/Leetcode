class Solution {
public:
    int ans;
    int *dp;
    
    int coin(vector<int>& coins,int amt,int no,int n){
        dp[0] = 0;
        
        for(int i=1;i<=amt;i++){
            for(int j=0;j<n;j++){
                if(i-coins[j]>=0){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);                    
                }
            }
        }        
        
        return dp[amt];
    }
    
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();        
        dp = new int[amt+1];
        
        for(int i=1;i<=amt;i++){
            dp[i] = INT_MAX-1;
        }
        
        int ans = coin(coins,amt,0,n);
        
        if(ans==INT_MAX-1){
            ans = -1;
        }
        
        return ans;
    }
};