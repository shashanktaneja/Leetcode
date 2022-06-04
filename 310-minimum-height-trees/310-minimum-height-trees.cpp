class Solution {
public:    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int> > mp(n);
        vector<int> ans;
        
        if(n==1){
            ans.push_back(0);
            return ans;
        }
        
        vector<int> in(n,0);
        
        for(int i=0;i<n-1;i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
            in[edges[i][0]]++;
            in[edges[i][1]]++;
        }
        
        vector<bool> vis(n,false);
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(in[i]==1){
                q.push(i);
                vis[i] = true;
            }       
        }
        
        int cnt = n;
        
        while(cnt>2){
            int si = q.size();
            while(si--){
                int cur = q.front();
                q.pop();
                
                for(auto nbr:mp[cur]){
                    in[nbr]--;
                    if(!vis[nbr] and in[nbr]==1){
                        q.push(nbr);
                        vis[nbr] = true;
                    }
                }
                
                cnt--;
            }
        }
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
        }
        
        return ans;
    }
};