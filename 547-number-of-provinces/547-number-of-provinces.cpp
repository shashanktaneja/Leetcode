class Solution {
public:
    int ans = 0;
    vector<vector<int>> mp;
    vector<bool> vis;
    
    void dfs(int cur){
        vis[cur] = true;
        for(auto nbr:mp[cur]){
            if(!vis[nbr]){
                dfs(nbr);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        ans = 0;
        mp.resize(n);
        vis.resize(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1){
                    mp[i].push_back(j);
                }                
            }
        }
            
        for(int i=0;i<n;i++){
            vis[i] = false;
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        }
                
        return ans;
    }
};