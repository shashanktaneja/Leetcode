class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        vector<int> tp(n,1);

        for(int i=1;i<n;i++){
            if(v[i]>v[i-1]){
                tp[i] = tp[i-1]+1;
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(v[i]>v[i+1] and tp[i]<=tp[i+1]){
                tp[i] += (tp[i+1]-tp[i]+1);
            }
            ans+=tp[i];
        }
        
        ans += tp[n-1];
        
        return ans;
    }
};