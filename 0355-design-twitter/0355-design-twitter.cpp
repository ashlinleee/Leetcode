#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Twitter {
private:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> [(timestamp, tweetId)]
    unordered_map<int, unordered_set<int>> following;  // userId -> {followeeIds}
public:
    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++, tweetId);
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap; // Use a max heap to store tweets in descending order of timestamp.    ts and photoid
        unordered_set<int> usersToFetch = following[userId];
        usersToFetch.insert(userId); // Include user's own tweets
        for (int user : usersToFetch) {
            if (tweets.count(user)) {
                for (const auto& tweet : tweets[user]) {
                    maxHeap.push(tweet);
                }
            }
        }
        vector<int> newsFeed;
        int count = 0;
        while (!maxHeap.empty() && count < 10) {//maxheap==recent post
            newsFeed.push_back(maxHeap.top().second); // Get tweetId second==photoid
            maxHeap.pop();
            count++;
        }
        return newsFeed;
    }
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
