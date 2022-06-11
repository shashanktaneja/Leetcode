class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
    unordered_map<int, int> left;
    int res = INT_MAX;
    for (auto l = 0, sum = 0; l <= nums.size() && sum <= x; ++l) {
        left[sum] = l;
        if (l < nums.size())
            sum += nums[l];
    }
    for (int r = nums.size() - 1, sum = 0; r >= 0 && sum <= x; --r) {
        auto it = left.find(x - sum);
        if (it != end(left) && r + 1 >= it->second) {
            res = min(res, (int)nums.size() - r - 1 + it->second);
        }
        sum += nums[r];
    }
    return res == INT_MAX ? -1 : res;
}
};