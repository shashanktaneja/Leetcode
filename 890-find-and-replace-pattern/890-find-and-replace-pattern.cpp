class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& v, string &s) {
        vector<string> ans;
        int n = v.size();
        int si = s.size();
        string tp = s;
        
        for(int i=0;i<n;i++){
            vector<char> mp(26,'0');            
            vector<int> vis(26,0);
            bool val = true;
            
            for(int j=0;j<si;j++){
                char cur = s[j];
                char req = v[i][j];
                
                if((mp[(cur-'a')]==req) || (mp[(cur-'a')]=='0' and vis[(req-'a')]==0)){
                    mp[(cur-'a')] = req;
                    vis[req-'a'] = 1;
                }
                else{
                    val = false;
                    break;
                }
            }
                        
            if(val){
                ans.push_back(v[i]);
            }
            
            s = tp;
        }
        
        
        return ans;
    }
};