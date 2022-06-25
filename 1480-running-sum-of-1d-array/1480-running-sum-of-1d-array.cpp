class Solution {
public:
    vector<int> runningSum(vector<int>& v) {
        vector<int> ans;
        int s = 0;
        for(int i=0;i<v.size();i++){
            s+=v[i];
            ans.push_back(s);
        }
        
        return ans;
    }
};