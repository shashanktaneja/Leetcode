class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tp;
    
    bool val(vector<int> &tp){
        for(int i=0;i<ans.size();i++){
            if(tp==ans[i]){
                return false;
            }
        }
        
        return true;
    }
    
    void solve(int s,int n,vector<int> &v,int t){
        if(s>=t){
            if(s==t){
                vector<int> tp2 = tp;
                sort(tp2.begin(),tp2.end());
                if(val(tp2)){
                    ans.push_back(tp2);                    
                }
            }
            return;
        }
        
        for(int i=0;i<n;i++){
            tp.push_back(v[i]);
            solve(s+v[i],n,v,t);
            tp.pop_back();
        }        
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        ans.clear();
        int n = v.size();
        
        solve(0,n,v,t);
        
        return ans;
    }
};