class Solution {
public:
    int minMoves2(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        int s=0,m=0;
        nth_element(v.begin(),v.begin()+(n/2),v.end());
        
        m = v[n/2];
        
        for(int i=0;i<n;i++){
            ans += abs(m-v[i]);
        }
        
        return ans;
    }
};