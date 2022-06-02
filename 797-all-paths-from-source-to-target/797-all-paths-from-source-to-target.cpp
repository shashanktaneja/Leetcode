class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int cur,vector<int> &v,int n,vector<vector<int>>& mp){
        v.push_back(cur);
        
        if(cur==n-1){
            ans.push_back(v);
            v.pop_back();
            return;
        }
        
        for(auto nbr:mp[cur]){
            solve(nbr,v,n,mp);
        }
        
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& mp) {
        ans.clear();
        int n = mp.size();
        vector<int> v;
        
        solve(0,v,n,mp);
        
        return ans;
    }
};