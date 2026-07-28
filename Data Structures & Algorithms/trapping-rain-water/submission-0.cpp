class Solution {
public:
    int trap(vector<int>& h) {
        int s = h.size();
        int *rs = new int[s];
        int *ls = new int[s];
        for(int i{0}; i<s; i++){
            if(i==0){ls[0] = h[0]; continue;}
            ls[i] = max(ls[i-1], h[i]);
        }
        for(int i{s-1}; i>=0;i--){
            if(i==s-1){rs[s-1] = h[s-1]; continue;}
            rs[i] = max(rs[i+1], h[i]);
        }
        int T{0};
        // int *w = new int[s];
        for(int i{0}; i<s; i++){
            // w[i] = min(rs[i], ls[i]) - h[i];
            // T += w[i];
            T += min(rs[i], ls[i]) - h[i];
        }
        delete[] rs;
        delete[] ls;
        // delete[] w;
        return T;
    }
};
