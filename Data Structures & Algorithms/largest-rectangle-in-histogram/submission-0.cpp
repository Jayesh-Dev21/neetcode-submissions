class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<pair<int,int>> s; // index , height
        int T{0}; // maxArea
        for(int i{0}; i<h.size(); i++){
            int srt = i;
            while(!s.empty() && h[i]<s.top().second){
                pair<int, int> top = s.top();
                auto [idx, heig] = top;
                T = max(T, heig*(i-idx));
                srt = idx;
                s.pop();
            }
            s.push({srt, h[i]});
        }
        while(!s.empty()){
            auto [idx, heig] = s.top();
            T = max(T, heig*(static_cast<int>(h.size()) - idx));
            s.pop();
        }
        return T;
    }
};
