class Solution {
public:
    int reverse(int x) {
        int T{0};
        while(x){
            int d = x%10;
            x /= 10;
            if(T > 0 ? (T > INT_MAX / 10 || (T == INT_MAX / 10 && d > 7)) : (T < INT_MIN / 10 || (T == INT_MIN / 10 && d < -8))) return 0;
            T = T*10 + d;
        }
        return T;
    }
};