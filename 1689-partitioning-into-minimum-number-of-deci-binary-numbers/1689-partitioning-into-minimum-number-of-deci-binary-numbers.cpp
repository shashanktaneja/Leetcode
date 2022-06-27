class Solution {
public:
    int minPartitions(string s) {
        int ans = 0;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            int cur = s[i]-'0';
            if(cur>ans){
                ans = cur;
            }
        }
        
        
        return ans;
    }
};