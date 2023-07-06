#include<bits/stdc++.h>
using namespace std;

class Twitter {
public:
    int count = 1;
    // save all users Tweets
    unordered_map<int, vector<pair<int, int>>> m1;
    // Followers
    unordered_map<int, vector<int>> m2;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        m1[userId].push_back({tweetId, count});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        vector<int> arr = m2[userId];
        
        auto it = find(arr.begin(), arr.end(), userId);
        if(it == arr.end()){
            arr.push_back(userId);
        }

        for(auto x1: arr){
            for(auto x2: m1[x1]){
                pq.push({x2.second, x2.first});
            }
        }
        int t = 10;

        vector<int> ans;
        while(!pq.empty() && t--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        vector<int> arr = m2[followerId];
        auto it = find(arr.begin(), arr.end(), followeeId);

        if(it == arr.end()){
            m2[followerId].push_back(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        vector<int> arr = m2[followerId];
        
        auto it = find(arr.begin(), arr.end(), followeeId);
        if(it != arr.end()){
            arr.erase(it);
        }
        m2[followerId] = arr;
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