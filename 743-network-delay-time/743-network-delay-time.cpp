class Solution {
public:    
    int networkDelayTime(vector<vector<int>>& v, int n, int k) {
        vector<vector<pair<int,int>>> mp(n+1);
        for(int i=0;i<v.size();i++){
            mp[v[i][0]].push_back({v[i][1],v[i][2]});
        }
        
        int ans = INT_MIN;
        queue<pair<int,int> > q;
        q.push({k,0});
        int dis[n+1];
        bool vis[n+1];
        memset(vis,false,sizeof(vis));
        vis[k] = true;
        
        for(int i=1;i<=n;i++){
            dis[i] = INT_MAX;
        }
        
        dis[k] = 0;
        
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            for(auto nbr:mp[cur.first]){
                if(cur.second+nbr.second < dis[nbr.first]){
                    vis[nbr.first] = true;
                    q.push({nbr.first,cur.second+nbr.second});
                    dis[nbr.first] = cur.second+nbr.second;
                }
            }
        }
        
        bool val = false;
        for(int i=1;i<=n;i++){
            if(vis[i]==false){
                val = true;
                break;
            }
            ans = max(ans,dis[i]);
        }
        
        if(val){
            return -1;
        }
        
        // dfs(0,n,k);
        
        return ans;
    }
};