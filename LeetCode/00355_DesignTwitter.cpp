// https://leetcode.com/problems/design-twitter/

class Twitter {
private:
    static constexpr int maxNewsFeedSize = 10;
    int currTime;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    //           userId      tweetTime  tweetId
    
public:
    Twitter() {
        currTime = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({currTime, tweetId});
        currTime++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeedTweets;
        priority_queue<pair<int, int>> maxHeap;
        
        // Get all the tweets posted by user itself
        for(auto userTweets : tweets[userId])
            maxHeap.push(userTweets);
        
        // Get all the tweets posted by users followed by userId
        for(auto followingUser : following[userId])
            for(auto userTweets : tweets[followingUser])
                maxHeap.push(userTweets);
        
        int currNumTweets = maxHeap.size();
        int currNewsFeedSize = min(currNumTweets, maxNewsFeedSize);
        
        for(int i = 0; i < currNewsFeedSize; i++) {
            newsFeedTweets.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return newsFeedTweets;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */