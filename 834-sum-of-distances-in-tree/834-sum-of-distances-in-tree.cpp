class Solution {
public:
    map<int,vector<int>> mp;
    int tp;
    
    int dfs(int cur,int temp, vector<int> &cnt, vector<bool> &vis){
        int ans = 1;
        vis[cur] = true;
        tp += temp;
        
        for(auto nbr:mp[cur]){
            if(!vis[nbr]){
                ans += dfs(nbr,temp+1,cnt,vis);
            }
        } 
        
        cnt[cur] = ans;
        return ans;
    }
    
    void dfs2(int cur, vector<int> &cnt, vector<bool> &vis, vector<int> &ans,int n){
        vis[cur] = true;
        for(auto nbr:mp[cur]){
            if(!vis[nbr]){
                ans[nbr] = ans[cur]+(n-cnt[nbr])-(cnt[nbr]);
                dfs2(nbr,cnt,vis,ans,n);
            }
        } 
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& v) {
        vector<int> ans(n,-1);
        mp.clear();
        vector<int> cnt(n,0);
        vector<bool> vis(n,false);
        tp = 0;
        
        for(int i=0;i<v.size();i++){
            mp[v[i][0]].push_back(v[i][1]);
            mp[v[i][1]].push_back(v[i][0]);
        }
        
        dfs(0,0,cnt,vis);
        
        for(int i=0;i<n;i++){
            vis[i] = false;
        }
                
        ans[0] = tp;                
        dfs2(0,cnt,vis,ans,n);        
        
        return ans;
    }
};