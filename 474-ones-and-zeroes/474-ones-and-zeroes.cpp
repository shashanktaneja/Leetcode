class Solution {
public:
    int dp[601][101][101];
    
    int solve(vector<pair<int,int>> &v,int idx,int m,int n){
        if(m<0 || n<0){
            return -1;
        }
        
        if(idx==v.size()){
            return 0;
        }
        
        if(dp[idx][m][n]!=-1){
            return dp[idx][m][n];
        }
        
        int op1 = 1+solve(v,idx+1,m-v[idx].first,n-v[idx].second);
        int op2 = solve(v,idx+1,m,n);  
        
        return dp[idx][m][n] = max(op1,op2);
    }
    
    int findMaxForm(vector<string>& v, int m, int n) {
        for(int i=0;i<v.size();i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        
        vector<pair<int,int>> tp;
        
        for(int i=0;i<v.size();i++){
            int z=0,o=0;        
            for(int k=0;k<v[i].size();k++){
                if(v[i][k]=='0'){
                    z++;
                }
                else{
                    o++;
                }
            }            
            tp.push_back({z,o});
        }
        
        int ans = solve(tp,0,m,n);    
        
        return ans;
    }
};