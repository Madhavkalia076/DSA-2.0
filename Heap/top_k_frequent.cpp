#include <bits/stdc++.h>
using namespace std;
vector<int> topK(vector<int> &nums, int k)
{
  unordered_map<int, int> mpp;
  for (auto num : nums)
  {
    mpp[num]++;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
  for (auto it : mpp)
  {
    minheap.push({it.second, it.first});
    if (minheap.size() > k)
    {
      minheap.pop();
    }
  }
  vector<int> ans;
  while (!minheap.empty())
  {
    ans.push_back(minheap.top().second);
    minheap.pop();
  }
  return ans;
}
int main()
{
  vector<int> nums;
  int temp;
  while (true)
  {
    cin >> temp;
    if (temp == -1)
      break;
    nums.push_back(temp);
  }
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << " ";
  }
  cout << endl
       << "enter the value of k: ";
  int k;
  cin >> k;
  vector<int> ans = topK(nums, k);
  cout << "top k frequent elements: " << endl;
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}