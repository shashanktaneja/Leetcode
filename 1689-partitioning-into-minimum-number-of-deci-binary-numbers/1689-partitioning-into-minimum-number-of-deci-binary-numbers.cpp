class Solution {
public:
    int minPartitions(string &s) {
        int ans = 0;
        
        for(int i=0;i<s.size();i++){
            int cur = s[i]-'0';
            if(cur>ans){
                ans = cur;
            }
        }
        
        
        return ans;
    }
};