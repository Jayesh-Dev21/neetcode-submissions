class Solution {
public:
    int hammingWeight(int n) {
       int T{0};
       while(n > 0) {T += (n&1); n >>= 1;}
       return T;
    }
};