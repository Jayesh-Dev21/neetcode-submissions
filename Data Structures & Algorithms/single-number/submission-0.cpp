class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int T{0}, n = nums.size();
        for(int i{0}; i<n; i++) T ^= nums[i];
        return T;
    }
};