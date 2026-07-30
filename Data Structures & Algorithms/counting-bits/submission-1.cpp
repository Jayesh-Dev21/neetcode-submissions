class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> T(n + 1,0);
        for (int i = 1; i <= n; i++) T[i] = __builtin_popcount(i);
        return T;
    }
};
