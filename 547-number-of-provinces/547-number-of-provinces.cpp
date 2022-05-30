class Solution {
public:
    int ans = 0;
    vector<vector<int>> mp;
    
    void dfs(int cur,bool *vis){
        vis[cur] = true;
        for(auto nbr:mp[cur]){
            if(!vis[nbr]){
                dfs(nbr,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        ans = 0;
        mp.resize(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1){
                    mp[i].push_back(j);
                }                
            }
        }
        
        bool vis[205];        
        memset(vis,false,sizeof(vis));
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,vis);
            }
        }
                
        return ans;
    }
};