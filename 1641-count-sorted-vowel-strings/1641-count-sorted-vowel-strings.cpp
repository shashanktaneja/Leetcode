class Solution {
public:
    int dp[60][10];
    
    int solve(int n,char cur){
        if(n==0){
            return 1;
        }
        
        if(dp[n][(cur-'a')]!=-1){       
            return dp[n][(cur-'a')];
        }
        
        int ans = 0;
        
        for(char ch = cur;ch<='e';ch++){
            ans += solve(n-1,ch);
        }
        
        return dp[n][(cur-'a')] = ans;
    }
    
    int countVowelStrings(int n) {
        for(int i=0;i<=n;i++){
            for(int j=0;j<=5;j++){
                dp[i][j] = -1;
            }
        }
        
        int ans = solve(n,'a');   
        
        return ans;
    }
};