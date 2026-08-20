class Twitter {
    int time;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int,int>>> tweets;
public:
    Twitter() : time(0) {}        

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> feed = tweets[userId];
        for(int followeeId : followers[userId]){ feed.insert(feed.end(), tweets[followeeId].begin(), tweets[followeeId].end()); }
        sort(feed.begin(), feed.end(), [](auto &a, auto &b){return a.first > b.first;});
        vector<int> resFeed;
        for(int i{0}; i<min(10, static_cast<int>(feed.size())); i++){ resFeed.push_back(feed[i].second); }
        return resFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
