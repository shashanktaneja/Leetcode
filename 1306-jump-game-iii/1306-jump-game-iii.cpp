class Solution {
public:
    bool canReach(vector<int>& v, int s) {
        int n = v.size();
        queue<int> q;
        q.push(s);
        vector<int> vis(n,0);
        vis[s] = 1;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            if(v[cur]==0){
                return true;
            }
            
            if(cur+v[cur]<n and (vis[cur+v[cur]]==0)){
                vis[cur+v[cur]] = 1;
                q.push(cur+v[cur]);
            }
            
            if(cur-v[cur]>=0 and (vis[cur-v[cur]]==0)){
                vis[cur-v[cur]] = 1;
                q.push(cur-v[cur]);
            }            
        }        
        
        return false;
    }
};