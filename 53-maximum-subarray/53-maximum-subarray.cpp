class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int n = v.size();
        int ans = INT_MIN;
        int ma = INT_MIN;
        
        int csum = 0;
        
        int i=0;
        while(i<n){        
            ma = max(ma,v[i]);
            csum+=v[i];
            if(csum<0){
                csum = 0;
            }
            ans = max(ans,csum);
            i++;
        }
        
        if(ma<0){
            return ma;
        }
        
        return ans;
    }
};