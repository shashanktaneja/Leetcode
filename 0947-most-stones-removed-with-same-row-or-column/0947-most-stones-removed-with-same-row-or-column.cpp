class Solution {
public:
    bool vis[1005];
    int ans;
    
    void dfs(int i,int j,int n, vector<vector<int>>& v){
        for(int cur=0;cur<n;cur++){
            if(!vis[cur] && (v[cur][0]==i || v[cur][1]==j)){
                ans++;
                vis[cur] = true;
                dfs(v[cur][0],v[cur][1],n,v);
            }
        }                
    }
    
    int removeStones(vector<vector<int>>& v) {
        int n = v.size();
        ans = 0;        
        memset(vis,false,sizeof(vis));
        
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                vis[i]=true;
                dfs(v[i][0],v[i][1],n,v);
            }
        }
        
        
        return ans;
    }
};