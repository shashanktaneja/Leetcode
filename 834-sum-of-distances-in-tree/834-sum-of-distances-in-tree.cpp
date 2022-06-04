class Solution {
public:
    vector<vector<int>> mp;
    int tp;
    vector<int> ans;
    vector<int> cnt;
    vector<bool> vis;
        
    int dfs(int cur,int temp){
        int ans = 1;
        vis[cur] = true;
        tp += temp;
        
        for(auto nbr:mp[cur]){
            if(!vis[nbr]){
                ans += dfs(nbr,temp+1);
            }
        } 
        
        cnt[cur] = ans;
        return ans;
    }
    
    void dfs2(int cur,int &n){
        vis[cur] = true;
        for(auto nbr:mp[cur]){
            if(!vis[nbr]){
                ans[nbr] = ans[cur]+(n-cnt[nbr])-(cnt[nbr]);
                dfs2(nbr,n);
            }
        } 
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& v) {
        mp.resize(n);
        ans.resize(n,-1);
        cnt.resize(n,0);
        vis.resize(n,false);
        tp = 0;
        
        for(int i=0;i<v.size();i++){
            mp[v[i][0]].push_back(v[i][1]);
            mp[v[i][1]].push_back(v[i][0]);
        }
        
        dfs(0,0);
        
        for(int i=0;i<n;i++){
            vis[i] = false;
        }
                
        ans[0] = tp;                
        dfs2(0,n);        
        
        return ans;
    }
};