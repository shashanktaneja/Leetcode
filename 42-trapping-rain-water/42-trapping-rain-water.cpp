class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        
        vector<int> l,r;
        int tp = 0;
        for(int i=0;i<n;i++){
            tp = max(tp,v[i]);
            l.push_back(tp);
        }
        
        tp = 0;
        
        for(int i=n-1;i>=0;i--){
            tp = max(tp,v[i]);
            r.push_back(tp);
        }
        
        reverse(r.begin(),r.end());
        
        for(int i=0;i<n;i++){
            int cur = min(l[i],r[i])-v[i];
            ans+=cur;
        }
        
        
        return ans;
    }
};