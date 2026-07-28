class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> res(t.size(),0);
        stack<pair<int,int>>s; // {temp, idx}

        for(auto i{0}; i<t.size(); i++){
            int _t = t[i];
            while(!s.empty() && _t>s.top().first){
                auto p = s.top();
                s.pop();
                res[p.second] = i - p.second;
            }
            s.push({_t,i});
        }
        return res;
    }
};
