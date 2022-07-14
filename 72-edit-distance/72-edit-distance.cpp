class Solution {
public:
    int dp[505][505];
    
    int solve(int i,int j,string &s,string &s2){
        if(j<0){
            return i+1;
        }
        
        if(i<0){
            return j+1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==s2[j]){
            return dp[i][j] = solve(i-1,j-1,s,s2);
        }
        
        int op1 = 1+solve(i-1,j,s,s2);
        int op2 = 1+solve(i,j-1,s,s2);
        int op3 = 1+solve(i-1,j-1,s,s2);

        int ans = min(op1,min(op2,op3));
        return dp[i][j] = ans;
    }
    
    int minDistance(string &s, string &s2) {
        int n = s.size();
        int m = s2.size();
        memset(dp,-1,sizeof(dp));
        
        int ans = solve(n-1,m-1,s,s2);        
        
        return ans;
    }
};