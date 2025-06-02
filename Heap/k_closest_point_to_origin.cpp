#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> a, int k)
{
  priority_queue<pair<int, pair<int, int>>> maxheap;
  for (auto it : a)
  {
    maxheap.push({(it[0] * it[0]) + (it[1] * it[1]), {it[0], it[1]}});
    if (maxheap.size() > k)
    {
      maxheap.pop();
    }
  }
  vector<vector<int>> ans;
  while (!maxheap.empty())
  {
    pair<int, int> temp = maxheap.top().second;
    ans.push_back({temp.first, temp.second});
    maxheap.pop();
  }
  return ans;
}
int main()
{
  vector<vector<int>> a;
  int x, y;
  while (true)
  {
    cin >> x >> y;
    if (x == -1 && y == -1)
      break;
    a.push_back({x, y});
  }
  for (auto it : a)
  {
    cout << "[" << it[0] << "," << it[1] << "]" << " ";
  }
  cout << endl
       << "enter the value of k: ";
  int k;
  cin >> k;
  vector<vector<int>> ans = kClosest(a, k);
  cout << "K closest points to origin: ";
  for (auto it : ans)
  {
    cout << "[" << it[0] << "," << it[1] << "]" << " ";
  }
  return 0;
}