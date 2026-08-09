class Twitter {
private:
    int time = 0;   // timestamp
    unordered_map<int, vector<vector<int>>> tweetMap;  // userId : [[timestamp, tweetId]]
    unordered_map<int, set<int>> followMap;  // userId : {userId}

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        auto Compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(Compare)> maxHeap(Compare); // {timestamp, tweetId, followeeid, index}

        if (followMap[userId].find(userId) == followMap[userId].end()) followMap[userId].insert(userId);

        for (int followeeId : followMap[userId]) {
            if (tweetMap.count(followeeId)) {
                const vector<vector<int>> tweets = tweetMap[followeeId];

                int index = tweets.size() - 1;
                maxHeap.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }

        while (result.size() < 10 && !maxHeap.empty()) {
            vector<int> curr = maxHeap.top();
            maxHeap.pop();
            result.push_back(curr[1]);

            int index = curr[3];
            if (index > 0) {
                const vector<int>& tweet = tweetMap[curr[2]][index - 1];
                maxHeap.push({tweet[0], tweet[1], curr[2], index - 1});
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
