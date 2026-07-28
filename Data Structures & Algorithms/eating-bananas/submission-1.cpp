class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int s = p.size();
        int m = *max_element(p.begin(), p.end());
        int l{0}, r{m};
        int T{m};
        while(l<=r){
            int k = l + (r-l)/2; // mid
            long long time = 0;
            for(int i : p){
                time += ceil(static_cast<double>(i)/k);
            }
            if(h>=time){
                T = min(T, k);
                r = k-1;
            }
            else{l = k + 1;}
        }
        return T;
    }
};