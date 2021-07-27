class Twitter {
public:
    
    unordered_map<int,set<int>>followers; // map to store followes
    unordered_map<int,vector<pair<int,int>>>post; // map to store post of every userID
    int time ;
    /** Initialize your data structure here. */
    Twitter() {
        time = 0; // time is important beacuse as we had to display only 10 recent posts that can be done only with comparing time value
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({time,tweetId});
        time++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        
        // this will store the posts according to the maxtime
        priority_queue<pair<int,int>>maxheap;
        
        // first we will fetch the posts of our userID
        for(auto x:post[userId]){
            maxheap.push({x.first,x.second});
        }
        
        // now we will fetch the post of people which our user used to follow
        for(auto x:followers[userId]){
            // fetching all post of X
            for(auto y:post[x]){
                maxheap.push({y.first,y.second});
            }
        }
        
        vector<int>res;
        while(!maxheap.empty()){
            res.push_back(maxheap.top().second);
            maxheap.pop();
            if(res.size()==10){
                break;
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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
