#include <bits/stdc++.h>
using namespace std;

int findLargest(vector<int> &nums, int k)
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
  return minheap.top();
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
  cout << "kth largest element: " << findLargest(nums, k);
  return 0;
}