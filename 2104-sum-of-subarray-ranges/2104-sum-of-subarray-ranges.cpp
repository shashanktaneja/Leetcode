typedef long long ll;

class Solution {
public:
    long long subArrayRanges(vector<int>& v) {
        int n = v.size();
        ll ans = 0;
        
        for(int i=1;i<n;i++){
            int ma = max(v[i],v[i-1]);
            int mi = min(v[i],v[i-1]);
            ans += (ma-mi);
            for(int j=i-2;j>=0;j--){
                ma = max(ma,v[j]);
                mi = min(mi,v[j]);
                ans += (ma-mi);
            }
        }
        
        return ans;
    }
};