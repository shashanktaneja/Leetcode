class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int cur,vector<int> &v,int n,vector<vector<int>>& mp){
        if(cur==n-1){
            ans.push_back(v);
            return;
        }
        
        for(auto nbr:mp[cur]){
            v.push_back(nbr);
            solve(nbr,v,n,mp);
            v.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& mp) {
        ans.clear();
        int n = mp.size();
        vector<int> v;
        v.push_back(0);
        
        solve(0,v,n,mp);
        
        return ans;
    }
};