class Solution {
public:
    int numMatchingSubseq(string &s, vector<string>& v) {
        int n = s.size();
        int ans = 0;
        
        vector<vector<int>> tp(26);
        
        for(int i=0;i<n;i++){
            tp[(s[i]-'a')].push_back(i);
        }
        
        for(int i=0;i<v.size();i++){
            bool val = true;
            int lt = -1;
            
            for(int j=0;j<v[i].size();j++){
                char cur = v[i][j];
                int pos = (cur-'a');
                int idx = -1;
                int s=0,e=(tp[pos].size());
                e--;
                
                if(e<0 || lt>=tp[pos][e]){
                    val = false;
                    break;
                }
                
                while(s<=e){
                    int mid = (s+e)/2;
                    if(tp[pos][mid]<=lt){
                        s = mid+1;
                    }
                    else{
                        idx = tp[pos][mid];
                        e = mid-1;
                    }                    
                }
                
                lt = idx;
            }
            
            if(val){
                ans++;
            }
        }
                
        return ans;
    }
};