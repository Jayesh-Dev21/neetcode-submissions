class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [](const vector<int>& p){
            int x=p[0], y=p[1];
            return sqrt(x*x + y*y);
        };
        auto comp = [=](const vector<int>& a, const vector<int>& b) {
            return dist(a) > dist(b);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);

        for(auto const p : points) minHeap.push({p[0], p[1]});
        vector<vector<int>> T;
        for (int i = 0; i < k; ++i) {
            T.push_back(minHeap.top());
            minHeap.pop();
        }
        return T;
    }
};