class TimeMap {
private:
    unordered_map <string, vector<pair<int,string>>> keyStore;
public:
    TimeMap() {
        keyStore.clear();
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& vals = keyStore[key];
        int l = 0, r = vals.size()-1;
        string res = "";
        while(l<=r){
            int m = l + (r-l)/2;
            if(timestamp>= vals[m].first){
                res = vals[m].second;
                l = m+1;
            }
            else{r=m-1;}
        }
        return res;
    }
};