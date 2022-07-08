typedef long long int ll;

class Solution {
public:
    ll ans;
    int m,n;
    ll dp[101][101][21];
    
    ll solve2(int i,int ne,int pre,vector<int> &v,vector<vector<int>>& ct,int t){
        if(i==m){
            if(ne==t){
                return 0;
            }
            return INT_MAX;
        }
        
        if(ne>t){
            return INT_MAX;
        }
        
        if(dp[i][ne][pre]!=-1){
            return dp[i][ne][pre];
        }
        
        ll ans = INT_MAX;
        
        if(v[i]!=0){
            if(v[i]==pre){
                ans = solve2(i+1,ne,v[i],v,ct,t);
            }
            else{
                ans = solve2(i+1,ne+1,v[i],v,ct,t);
            }
        }
        else{
            for(int j=0;j<n;j++){
                int col = j+1;
                if(col==pre){
                    ans = min(ans,ct[i][j] + solve2(i+1,ne,col,v,ct,t));
                }
                else{
                    ans = min(ans,ct[i][j] + solve2(i+1,ne+1,col,v,ct,t));
                }
            }
        }
        
        return dp[i][ne][pre] = ans;
    }
    
    int minCost(vector<int>& v, vector<vector<int>>& ct, int M, int N, int t) {
        ans = INT_MAX;
        m = M, n = N;        
        memset(dp,-1,sizeof(dp));
        
        ans = solve2(0,0,0,v,ct,t);
        
        if(ans>=INT_MAX){
            return -1;
        }
        
        return ans;
    }
};