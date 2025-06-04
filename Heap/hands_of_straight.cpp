#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &cards, int groupSize)
{
  int n = cards.size();
  if (n % groupSize == 0)
    return false;
  unordered_map<int, int> freq;
  for (auto it : cards)
  {
    freq[it]++;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
  for (auto it : freq)
  {
    minheap.push({it.first, it.second});
  }
  while (!minheap.empty())
  {
    int temp = groupSize;
    vector<pair<int, int>> rem;
    int prev = -1;
    while (temp > 0 && !minheap.empty())
    {
      int val = minheap.top().first;
      int f = minheap.top().second;
      minheap.pop();
      if (prev != -1 && val - prev != 1)
        return false;
      prev = val;
      temp--;
      if (f - 1 > 0)
        rem.push_back({val, f - 1});
    }
    if (temp != 0)
      return false;
    for (auto it : rem)
    {
      minheap.push({it.first, it.second});
    }
  }
  return true;
}
int main()
{
  vector<int> cards;
  int temp;
  while (true)
  {
    cin >> temp;
    if (temp == -1)
      break;
    cards.push_back(temp);
  }
  for (auto it : cards)
  {
    cout << it << " ";
  }
  cout << endl
       << "enter the group size: ";
  int x;
  cin >> x;
  cout << "Alice can rearrange consecutive number into group of group size of " << x << ": " << check(cards, x);
  return 0;
}