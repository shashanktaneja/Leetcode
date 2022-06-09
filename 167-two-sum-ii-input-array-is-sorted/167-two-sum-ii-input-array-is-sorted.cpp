class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int n = v.size();
        int s=0,e=n-1;
        vector<int> ans;
        
        while(s<e){
            int cur = v[s]+v[e];
            if(cur==t){
                ans = {s+1,e+1};
                break;
            }
            else if(cur<t){
                s++;
            }
            else{
                e--;
            }
        }
        
        return ans;
    }
};