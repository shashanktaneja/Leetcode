class Solution {
public:
    int maxProduct(vector<string>& v) {
        int n = v.size();
        int ans = 0;
        
        vector<int> tp(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<v[i].size();j++){
                int cur = v[i][j]-'a';
                tp[i] |= (1<<cur);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int tp1 = tp[i];
                int tp2 = tp[j];
                
                if((tp1&tp2)==0){
                    int cur = (v[i].size())*(v[j].size());
                    ans = max(ans,cur);
                }
            }
        }
        
        
        return ans;
    }
};