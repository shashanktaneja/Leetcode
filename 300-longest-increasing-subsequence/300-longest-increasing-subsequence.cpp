class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        int ans = 1;
        
        vector<int> tp;
        tp.push_back(v[0]);
        
        for(int i=1;i<n;i++){
            int idx = lower_bound(tp.begin(),tp.end(),v[i])-tp.begin();
            
            if(idx==tp.size()){
                tp.push_back(v[i]);
                int si = tp.size();
                ans = max(ans,si);
            }
            else{
                tp[idx] = v[i];
            }
        }
        
        
        
        return ans;
    }
};