class Solution {
public:
    bool val;
    vector<int> dp;
    int t,n;
    
    int solve(int cur,int mask){
        if(dp[mask]!=-1){
            return dp[mask];
        }
                
        for(int j=0;j<n;j++){
            int tp = (1<<j);            
            if((tp&mask)==0){
                int val = solve(cur+j+1,mask|tp);
                if(cur+j+1>=t || val==0){
                    return dp[mask] = 1;
                }
            }
        }     
        
        return dp[mask] = 0;
    }
    
    bool canIWin(int ma, int ma2) {
        if(ma2==0){
            return true;
        }
        
        t = ma2;
        n = ma;
        
        int sum = (ma*(ma+1))/2;        
        
        if(sum<t){
            return false;
        }
        
        dp.resize(1<<ma,-1);
        
        return solve(0,0);
    }
};