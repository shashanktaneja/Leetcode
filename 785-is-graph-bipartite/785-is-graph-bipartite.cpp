class Solution {
public:
    bool dfs(int si,int cur,vector<vector<int>>& v, vector<bool> &vis, vector<int> &gp){
        vis[cur] = true;
        bool ans = true;
        gp[cur] = si;
        
        for(auto nbr:v[cur]){
            if(!vis[nbr]){
                ans &= dfs(1-si,nbr,v,vis,gp);
                if(ans==false){
                    break;
                }
            }
            else{
                if(gp[nbr]==si){
                    return false;
                }
            }
        }
        
        return ans;
    }
    
    bool isBipartite(vector<vector<int>>& v) {
        bool ans = true;
        int n = v.size();
        vector<bool> vis(n,false);
        vector<int> gp(n);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bool tp = dfs(0,i,v,vis,gp);
                ans &= tp;
                if(ans==false){
                    break;
                }
            }
        }
        
        return ans;
    }
};