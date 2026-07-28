class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for (auto num : nums) {
            if (m.count(num)) {
                return true;
            }
            m.insert(num);
        }
        return false;
    }
};