class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int ans = 0;
      
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        
        for(int i=0;i<n;i++){
            if(s.find(nums[i]-1)!=s.end()){
                //this can't be the LB
                continue;
            }
            else{
                //this is the LB
                int count = 1;
                int j = nums[i]+1;
                while(s.find(j)!=s.end()){
                    count++;
                    j++;
                }
                
                ans = max(ans,count);
            }
        }
        
        return ans;
    }
};