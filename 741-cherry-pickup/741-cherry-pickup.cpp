class Solution {
public:
    int dp[50][50];
    int dp2[50][50][50];
    
    int solve(int n,vector<vector<int>> &v){
        for(int i=1;i<n;i++){
            if(v[0][i]==-1){
                dp[0][i] = -1;
            }
            else if(dp[0][i-1]==-1){
                dp[0][i] = -1;
            }
            else{
                dp[0][i] = dp[0][i-1];
                if(v[0][i]==1){
                    dp[0][i]++;
                }
            }            
        }
        
        for(int i=1;i<n;i++){
            if(v[i][0]==-1){
                dp[i][0] = -1;
            }
            else if(dp[i-1][0]==-1){
                dp[i-1][0] = -1;
            }
            else{
                dp[i][0] = dp[i-1][0];
                if(v[i][0]==1){
                    dp[i][0]++;
                }
            }            
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if((v[i][j]==-1) ||(dp[i-1][j]==-1 and dp[i][j-1]==-1)){
                    dp[i][j] = -1;
                }
                else if(dp[i-1][j]==-1){
                    dp[i][j] = dp[i][j-1];
                    if(v[i][j]==1){
                        dp[i][j]++;
                    }
                }
                else if(dp[i][j-1]==-1){
                    dp[i][j] = dp[i-1][j];
                    if(v[i][j]==1){
                        dp[i][j]++;
                    }
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    if(v[i][j]==1){
                        dp[i][j]++;
                    }
                }
            }
        }
        
        return dp[n-1][n-1];
    }
    
    int solve2(vector<vector<int>> &v,int n,int r1,int c1,int c2){        
        int r2 = r1+c1-c2;
        
        if(r1==n || c1==n || c2==n || r2==n || v[r1][c1]==-1 || v[r2][c2]==-1){
            return -999999;
        }
        
        if(dp2[r1][c1][c2]!=-1){
            return dp2[r1][c1][c2];
        }
        
        int op1 = solve2(v,n,r1+1,c1,c2);
        int op2 = solve2(v,n,r1,c1+1,c2);
        int op3 = solve2(v,n,r1+1,c1,c2+1);
        int op4 = solve2(v,n,r1,c1+1,c2+1);
        
        int ans = (v[r1][c1])+max(op1,max(op2,max(op3,op4)));
        
        if(r1!=r2 || c1!=c2){
            ans+=(v[r2][c2]);
        }
        
        return dp2[r1][c1][c2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& v) {
        int n = v.size();
        
        for(int i=0;i<50;i++){
            for(int j=0;j<50;j++){
                for(int k=0;k<50;k++){
                    dp2[i][j][k] = -1;
                }
            }
        }
        
        if(v[n-1][n-1]==1){
            dp2[n-1][n-1][n-1] = 1;
        }
        else{
            dp2[n-1][n-1][n-1] = 0;
        }
        
        int ans = solve2(v,n,0,0,0);
        
        if(ans<=0){
            return 0;
        }
        
        return ans;
    }
};