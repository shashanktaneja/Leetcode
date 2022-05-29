class Solution {
public:
    int maxProduct(vector<string>& v) {
        int n = v.size();
        int ans = 0;
        
        vector<int> tp(n,0);
        
        for(int i=0;i<n;i++){
            // vector<int> f(26,0);
            for(int j=0;j<v[i].size();j++){
                // f[]++;
                int cur = v[i][j]-'a';
                tp[i] |= (1<<cur);
            }
            // tp.push_back(f);
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool val = true;
                int tp1 = tp[i];
                int tp2 = tp[j];
                
                while(tp1>0){
                    if((tp1&1) and (tp2&1)){
                        val = false;
                        break;
                    }
                    tp1/=2;
                    tp2/=2;
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