class Solution {
public:
    vector<string> wordSubsets(vector<string>& v, vector<string>& v2) {
        int n = v.size();
        int m = v2.size();
        vector<string> ans;
        
        vector<int> f(26,0);
        
        for(int i=0;i<m;i++){
            vector<int> tp(26,0);
            for(int j=0;j<v2[i].size();j++){
                tp[(v2[i][j]-'a')]++;
            }
            
            for(int j=0;j<26;j++){
                f[j] = max(f[j],tp[j]);
            }
        }
        
        for(int i=0;i<n;i++){
            vector<int> tp(26,0);
            for(int j=0;j<v[i].size();j++){
                tp[(v[i][j]-'a')]++;
            }
            
            bool val = true;
            
            for(int j=0;j<26;j++){
                if(f[j]>tp[j]){
                    val = false;
                    break;
                }
            }
            
            if(val){
                ans.push_back(v[i]);
            }
        }
        
        return ans;
    }
};