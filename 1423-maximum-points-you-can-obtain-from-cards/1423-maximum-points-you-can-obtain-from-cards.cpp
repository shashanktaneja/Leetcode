class Solution {
public:    
    int maxScore(vector<int>& v, int k) {
        int n = v.size();      
        vector<int> pre,suff;
        int s=0;
        for(int i=0;i<n;i++){
            s+=v[i];
            pre.push_back(s);
        }
        
        s = 0;
        for(int i=n-1;i>=0;i--){
            s+=v[i];
            suff.push_back(s);
        }
         
        int ans = max(pre[k-1],suff[k-1]);
        
        for(int i=0;i<k-1;i++){
            int cur = pre[i];
            cur += suff[k-i-2];
            ans = max(ans,cur);
        }
        
        return ans;
    }
};