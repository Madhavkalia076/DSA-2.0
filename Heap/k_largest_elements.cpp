#include <bits/stdc++.h>
using namespace std;

vector<int> findLargest(vector<int> &nums, int k)
{
  priority_queue<int, vector<int>, greater<int>> minheap;
  for (auto num : nums)
  {
    minheap.push(num);
    if (minheap.size() > k)
    {
      minheap.pop();
    }
  }
  vector<int> ans;
  while (!minheap.empty())
  {
    ans.push_back(minheap.top());
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
  cout << endl;
  cout << "enter the value of k: " << endl;
  int k;
  cin >> k;
  vector<int> ans = findLargest(nums, k);
  cout << "kth largest element: " << endl;
  for (int i = 0; i < k; i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}