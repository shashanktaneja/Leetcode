class Solution {
public:
    int dp[105][105];
    int n,m,N;
    
    int solve(int i,int j,int k,string &s1,string &s2,string &s3){
        if(k==N){
            return true;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(i<n and j<m and s1[i]==s3[k] and s2[j]==s3[k]){
            return dp[i][j] = solve(i+1,j,k+1,s1,s2,s3)|solve(i,j+1,k+1,s1,s2,s3);
        }
        
        if(i<n and s1[i]==s3[k]){
            return dp[i][j] = solve(i+1,j,k+1,s1,s2,s3);
        }
        
        if(j<m and s2[j]==s3[k]){
            return dp[i][j] = solve(i,j+1,k+1,s1,s2,s3);
        }
        
        return dp[i][j] = false;
    }
    
    bool isInterleave(string &s1, string &s2, string &s3) {
        n = s1.size();
        m = s2.size();
        N = s3.size();
        
        if(N!=(m+n)){
            return false;
        }
        
        memset(dp,-1,sizeof(dp));
        
        int ans = solve(0,0,0,s1,s2,s3);
        
        return ans;
    }
};