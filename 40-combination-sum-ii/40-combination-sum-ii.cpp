class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tp;
    
    void solve(int i,int n,int s,int t,vector<int> &v){
        if(s==t){
            ans.push_back(tp);    
            return;
        }
        
        if(s>t || i==n){
            return;
        }
        
        for(int j=i;j<n;j++){
            if(j!=i and v[j]==v[j-1]){
                continue;
            }
            
            tp.push_back(v[j]);
            solve(j+1,n,s+v[j],t,v);
            tp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
        int n = v.size();
        ans.clear();        
        sort(v.begin(),v.end());        
        solve(0,n,0,t,v);        
        return ans;
    }
};