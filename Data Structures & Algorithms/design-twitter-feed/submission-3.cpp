class Twitter {
private:
    unordered_map<int, set<int>> follow_map;

    // { userId , {timestamp, tweetId} } format
    unordered_map<int, vector<pair<int, int>>> user_posts;
    int timeStamp = 0;

public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        user_posts[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> recent_tweets;

        // populate heap with user's own tweets
        if(user_posts.count(userId)) {
            for(auto &it : user_posts[userId]) 
                recent_tweets.push(it);
        }

        // populate heap with follower tweets
        if(follow_map.count(userId)) {
            for(int follower : follow_map[userId]) {
                if(user_posts.count(follower)) {
                    for(auto &it : user_posts[follower]) 
                        recent_tweets.push(it);
                }
            }         
        }

        vector<int> feed;
        int count = 10;
        while(count > 0 && !recent_tweets.empty()) {
            feed.push_back(recent_tweets.top().second);
            recent_tweets.pop();
            count--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            follow_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(follow_map[followerId].count(followeeId))
            follow_map[followerId].erase(followeeId);
    }
};
