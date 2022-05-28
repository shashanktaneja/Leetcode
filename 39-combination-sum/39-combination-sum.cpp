class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tp;
    
    void solve(int idx,int s,int n,vector<int> &v,int t){
        if(s>=t){
            if(s==t){
                ans.push_back(tp);    
            }
            return;
        }
        
        for(int i=idx;i<n;i++){
            tp.push_back(v[i]);
            solve(i,s+v[i],n,v,t);
            tp.pop_back();
        }        
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        ans.clear();
        int n = v.size();        
        solve(0,0,n,v,t);        
        return ans;
    }
};