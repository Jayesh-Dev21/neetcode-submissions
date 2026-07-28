class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[128] {0};
        int l{0};
        int T{0};
        for(int r{0}; r<s.size(); r++){
            while(cnt[s[r]]!=0){
                cnt[s[l]]--;
                l++;
            }
            cnt[s[r]]++;
            T = max(T, r-l+1);
        }
        return T;
    }
};
