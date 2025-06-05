#include <bits/stdc++.h>
using namespace std;

class twitter
{
private:
  int timestamp;
  unordered_map<int, unordered_set<int>> followMap;
  unordered_map<int, vector<pair<int, int>>> tweets;

public:
  twitter()
  {
    timestamp = 0;
  }

  void postTweet(int userId, int tweetId)
  {
    tweets[userId].emplace_back(timestamp++, tweetId);
  }

  vector<int> getFeed(int userId)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    followMap[userId].insert(userId);

    for (int followeeId : followMap[userId])
    {
      if (tweets.count(followeeId))
      {
        for (auto &tweet : tweets[followeeId])
        {
          minheap.push(tweet);
          if (minheap.size() > 10)
          {
            minheap.pop();
          }
        }
      }
    }
    vector<int> feed;
    while (!minheap.empty())
    {
      feed.push_back(minheap.top().second);
      minheap.pop();
    }
    return feed;
  }

  void follow(int followerId, int followeeId)
  {
    if (followerId != followeeId)
    {
      followMap[followerId].insert(followeeId);
    }
  }
  void unfollow(int followerId, int followeeId)
  {
    followMap[followerId].erase(followeeId);
  }
};
int main()
{
  twitter twitter;

  twitter.postTweet(1, 5);                // User 1 posts tweet with ID 5
  vector<int> feed1 = twitter.getFeed(1); // Should return [5]

  twitter.follow(1, 2);                   // User 1 follows user 2
  twitter.postTweet(2, 6);                // User 2 posts tweet with ID 6
  vector<int> feed2 = twitter.getFeed(1); // Should return [6, 5]

  twitter.unfollow(1, 2);                 // User 1 unfollows user 2
  vector<int> feed3 = twitter.getFeed(1); // Should return [5]

  // Output
  cout << "Feed 1: ";
  for (int tweetId : feed1)
    cout << tweetId << " ";
  cout << endl;

  cout << "Feed 2: ";
  for (int tweetId : feed2)
    cout << tweetId << " ";
  cout << endl;

  cout << "Feed 3: ";
  for (int tweetId : feed3)
    cout << tweetId << " ";
  cout << endl;

  return 0;
}
