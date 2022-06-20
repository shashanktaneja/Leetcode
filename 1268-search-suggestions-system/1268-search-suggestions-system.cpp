class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& v, string &t) {
        int n = v.size();
        int m = t.size();
        vector<vector<string>> ans;
        sort(v.begin(),v.end());
        
        int i=0;
        string cur = "";
        
        for(int l=1;l<=m;l++){
            cur += t[l-1];
            vector<string> tp;
            while(i<n){
                if(v[i].substr(0,l)!=cur){
                    i++;
                }
                else{
                    break;
                }
            }
            
            if(i<n){
                tp.push_back(v[i]);
                if(i+1<n and v[i+1].substr(0,l)==cur){
                    tp.push_back(v[i+1]);
                    if(i+2<n and v[i+2].substr(0,l)==cur){
                        tp.push_back(v[i+2]);
                    }
                }
            }
            
            ans.push_back(tp);
        }
        
        
        return ans;
    }
};