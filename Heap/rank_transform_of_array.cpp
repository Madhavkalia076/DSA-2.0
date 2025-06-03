#include <bits/stdc++.h>
using namespace std;
vector<int> ranktransform(vector<int> &a)
{
  int n = a.size();
  unordered_map<int, vector<int>> mpp;
  priority_queue<int> maxheap;
  for (int i = 0; i < a.size(); i++)
  {
    mpp[a[i]].push_back(i);
  }
  for (auto it = mpp.begin(); it != mpp.end(); ++it)
  {
    maxheap.push(it->first);
  }
  vector<int> ans(n, -1);
  while (!maxheap.empty())
  {
    int val = maxheap.top();
    for (auto it : mpp[val])
    {
      ans[it] = maxheap.size();
    }
    maxheap.pop();
  }
  return ans;
}
int main()
{
  vector<int> a;
  int temp;
  while (true)
  {
    cin >> temp;
    if (temp == -1)
      break;
    a.push_back(temp);
  }
  for (int i : a)
  {
    cout << i << " ";
  }
  cout << endl
       << "rank transform of array a: ";
  vector<int> ans = ranktransform(a);
  for (int i : ans)
  {
    cout << i << " ";
  }
  return 0;
}