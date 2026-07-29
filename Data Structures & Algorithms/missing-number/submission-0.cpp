class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto sum  = [&](int n){return (n*n + n)/2;};
        int Y{0}, n = nums.size();
        for(int i{0}; i<n; i++) Y += nums[i];
        return sum(n) - Y;
    }
};
