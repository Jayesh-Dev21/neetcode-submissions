class Solution {
public:
    int findDuplicate(vector<int>& n) {
        auto s{0}, f{0};
        while(true){
            s = n[s];
            f = n[n[f]];
            if(s==f){
                break;
            }
        }
        int s2{0};
        while(true){
            s = n[s];
            s2 = n[s2];
            if(s==s2) return s;
        }
    }
};
