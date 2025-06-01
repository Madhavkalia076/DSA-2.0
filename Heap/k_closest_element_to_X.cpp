#include <bits/stdc++.h>
using namespace std;

vector<int> closest(vector<int> &nums, int k, int x)
{
  priority_queue<pair<int, int>> maxheap;
  for (auto num : nums)
  {
    maxheap.push({abs(x - num), num});
    if (maxheap.size() > k)
    {
      maxheap.pop();
    }
  }
  vector<int> ans;
  while (!maxheap.empty())
  {
    ans.push_back(maxheap.top().second);
    maxheap.pop();
  }
  sort(ans.begin(), ans.end());
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
  int k, x;
  cin >> k;
  cout << "enter the value of x: ";
  cin >> x;
  vector<int> ans = closest(nums, k, x);
  cout << "output: ";
  for (int i = 0; i < k; i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}