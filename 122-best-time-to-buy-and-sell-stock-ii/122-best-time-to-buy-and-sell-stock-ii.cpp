class Solution {
public:
    int maxProfit(vector<int>& v) {
        int ans = 0;
        int n = v.size();
        
        int i=0;
        while(i<n-1){
            int cur = v[i];
            while(i<n-1 and v[i]>=v[i+1]){
                i++;
                cur = v[i];
            }
            
            int j = i+1;
            if(j==n){
                break;
            }
            
            while(j<n-1 and v[j]<=v[j+1]){
                j++;
            }
            
            if(v[j]>cur){
                ans += (v[j]-cur);
            }
            
            i = j+1;
        }
        
        return ans;
    }
};