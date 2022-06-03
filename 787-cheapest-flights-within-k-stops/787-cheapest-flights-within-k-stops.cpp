class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& v, int src, int dst, int k) {
        int ans = INT_MAX;
        map<int,vector<pair<int,int>>> mp;
        map<int,int> mp2;
        
        for(int i=0;i<n;i++){
            mp2[i] = INT_MAX;
        }
        
        for(int i=0;i<v.size();i++){
            mp[v[i][0]].push_back({v[i][1],v[i][2]});
        }
        
        queue<pair<int,pair<int,int> >> q;
        q.push({src,{0,0}});
        mp2[src] = 0;
        
        while(!q.empty()){
            int cur = q.front().first;
            int dist = q.front().second.first;
            int tp = q.front().second.second;
            
            // cout<<cur<<endl;
            
            q.pop();
            
            if(cur==dst){
                ans = min(ans,dist);
            }
            
            if(tp<=k){
                for(auto nbr:mp[cur]){
                    if(dist+nbr.second<mp2[nbr.first]){
                        q.push({nbr.first,{dist+nbr.second,tp+1}});
                        mp2[nbr.first] = dist+nbr.second;
                    }                    
                }
            }            
        }
        
        if(ans==INT_MAX){
            return -1;
        }
        
        return ans;
    }
};