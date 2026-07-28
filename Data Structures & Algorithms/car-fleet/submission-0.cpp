class Solution {
public:
    float time(int target, pair<int,int> car){
        return (float)(target - car.first) / car.second;
    }
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        // for the ith car -> p[i] is postion and s[i] is the speed @ time = 0;
        vector <pair<int,int>> car;
        for(int i{0}; i<p.size(); i++){
            car.push_back({p[i], s[i]});
        }
        int n = car.size();
        sort(car.begin(), car.end());
       
        // 1,3 4,2
        // 4,2 1,3

        // 7,1 4,2 1,3 0,2
        stack<pair<int,int>> c;
        c.push({car[n-1].first, car[n-1].second});
        for(int i{n-2}; i>=0; i--){
            if(time(target, c.top()) < time(target, car[i])) c.push(car[i]);
            
        }
        return c.size();
    }
};
