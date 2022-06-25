class Solution {
public:
    vector<int> runningSum(vector<int>& v) {
        vector<int> ans;
        int n = v.size();
        int s = 0;
        for(int i=0;i<n;i++){
            s+=v[i];
            ans.push_back(s);
        }
        
        return ans;
    }
};