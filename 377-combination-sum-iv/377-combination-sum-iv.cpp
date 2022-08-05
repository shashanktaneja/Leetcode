int mod = 1e9+7;

class Solution {
public:
    int combinationSum4(vector<int>& v, int t) {
        int n = v.size();        
        long long dp[1001] = {0};
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=t;i++){
            long long cur = 0;
            for(int j=0;j<n;j++){                
                if(i-v[j]>0){
                    if(cur+dp[i-v[j]]> INT_MAX)
                        continue;
                    cur += (dp[i-v[j]]);
                }
                else if(i-v[j]==0){
                    cur = (cur+1);
                }
            }
            
            dp[i] = cur;
        }
                
        return dp[t];
    }
};