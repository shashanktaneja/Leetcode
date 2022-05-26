class Solution {
public:
    int hammingWeight(uint32_t &n) {
        int ans = 0;
        while(n>0){
            int cur = (n&1);
            n/=2;
            if(cur==1){
                ans++;
            }
        }
        return ans;
    }
};