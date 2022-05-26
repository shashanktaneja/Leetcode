class Solution {
public:
    bool solve(int n,int sum,vector<int> &v){
        int s = 0;
        
        for(int i=0;i<n;i++){
            s+=v[i];
        }
        
        int dp[n+3][s+3];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j] = false;
            }
        }
        
        for(int i=0;i<n;i++){
            dp[i][v[i]] = true;   
            dp[i][0] = true;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                dp[i][j] = dp[i-1][j];
                if(j-v[i]>=0){
                    dp[i][j] |= dp[i-1][j-v[i]];
                }
            }
        }
        
        return dp[n-1][sum];
    }
    
    bool canPartition(vector<int>& v) {
        int n = v.size();
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum+=v[i];
        }
        
        if(sum%2!=0){
            return false;
        }
        
        bool ans = solve(n,sum/2,v);
    
        return ans;
    }
};