class Solution {
public:
    vector<int> findBall(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int> > dp(m, vector<int> (n,0));
        
        if(n==1){
            return {-1};
        }
        
        for(int j=n-1;j>=0;j--){
            if(j==0){
                if(v[m-1][j]==-1){
                    dp[m-1][j]=-1;
                }
                else{
                    if(v[m-1][j+1]==-1){
                         dp[m-1][j]=-1;
                    }
                    else{
                         dp[m-1][j]=1;
                    }                       
                }
            }
            else if(j!=n-1){
                if(v[m-1][j]==1){
                    if(v[m-1][j+1]==-1){
                        dp[m-1][j]=-1;
                    }
                    else{
                        dp[m-1][j] = j+1;
                    }
                }
                else{
                    if(v[m-1][j-1]==-1){
                        dp[m-1][j]=j-1;
                    }
                    else{
                        dp[m-1][j] = -1;
                    }
                }
            }
            else{
                if(v[m-1][j]==1){
                    dp[m-1][j]=-1;
                }
                else{
                    if(v[m-1][j-1]==1){
                         dp[m-1][j]=-1;
                    }
                    else{
                         dp[m-1][j]=n-2;
                    }                       
                }
            }
        }        
                
        for(int i=m-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(j==0){
                    if(v[i][j]==-1){
                        dp[i][j]=-1;
                    }
                    else{
                        if(v[i][j+1]==-1){
                             dp[i][j]=-1;
                        }
                        else{
                             dp[i][j]=dp[i+1][j+1];
                        }                       
                    }
                }
                else if(j!=n-1){
                    if(v[i][j]==1){
                        if(v[i][j+1]==-1){
                            dp[i][j]=-1;
                        }
                        else{
                            dp[i][j] = dp[i+1][j+1];
                        }
                    }
                    else{
                        if(v[i][j-1]==-1){
                            dp[i][j]=dp[i+1][j-1];
                        }
                        else{
                            dp[i][j] = -1;
                        }
                    }
                }
                else{
                    if(v[i][j]==1){
                        dp[i][j]=-1;
                    }
                    else{
                        if(v[i][j-1]==1){
                             dp[i][j]=-1;
                        }
                        else{
                             dp[i][j]=dp[i+1][j-1];
                        }                       
                    }
                }               
            }
        }
                
        return dp[0];
    }
};