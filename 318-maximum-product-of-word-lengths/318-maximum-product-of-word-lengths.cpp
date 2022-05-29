class Solution {
public:
    int maxProduct(vector<string>& v) {
        int n = v.size();
        int ans = 0;
        
        vector<vector<int>> tp;
        
        for(int i=0;i<n;i++){
            vector<int> f(26,0);
            for(int j=0;j<v[i].size();j++){
                f[v[i][j]-'a']++;
            }
            tp.push_back(f);
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool val = true;
                
                for(int k=0;k<26;k++){
                    if(tp[i][k]>0 and tp[j][k]>0){
                        val = false;
                        break;
                    }
                }
                
                if(val){
                    int cur = (v[i].size())*(v[j].size());
                    ans = max(ans,cur);
                }
            }
        }
        
        
        return ans;
    }
};