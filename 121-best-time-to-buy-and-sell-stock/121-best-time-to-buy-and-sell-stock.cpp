class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        int ma = v[n-1];
        
        for(int i=n-2;i>=0;i--){
            int cur = ma-v[i];
            ans = max(ans,cur);
            ma = max(ma,v[i]);
        }
        
        return ans;
    }
};