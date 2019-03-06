class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        followList = unordered_map<int, unordered_set<int>>();
        tweetList = unordered_map<int, vector<pair<int, double>>>();
        timeStamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(tweetList.count(userId) == 0){
            tweetList.insert({userId, vector<pair<int, double>>()});
        }
        tweetList[userId].push_back(pair<int, double>(tweetId, timeStamp++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, double>> tweets = tweetList[userId];
        for(int id : followList[userId]){
            // perform a merge sort
            int pointer1 = 0, pointer2 = 0;
            vector<pair<int, double>> temp;
            while(pointer1 < tweets.size() || pointer2 < tweetList[id].size()){
                if(pointer1 >= tweets.size()){
                    temp.push_back(tweetList[id][pointer2++]);
                }else if(pointer2 >= tweetList[id].size()){
                    temp.push_back(tweets[pointer1++]);
                }else{
                    if(tweets[pointer1].second > tweetList[id][pointer2].second){
                        temp.push_back(tweetList[id][pointer2++]);
                    }else{
                        temp.push_back(tweets[pointer1++]);
                    }
                }
            }
            tweets = temp;
        }
        int size = min(10, (int)tweets.size());
        vector<int> result(size, 0);
        for(int i = 0; i < size; i++){
            result[i] = tweets[tweets.size() - 1 - i].first;
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        if(followList.count(followerId) == 0){
            followList.insert({followerId, unordered_set<int>()});
        }
        followList[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followList.count(followerId) != 0){
            followList[followerId].erase(followeeId);
        }
    }
private:
    double timeStamp;
    unordered_map<int, unordered_set<int>> followList;
    unordered_map<int, vector<pair<int, double>>> tweetList;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */