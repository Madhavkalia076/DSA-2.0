#include <bits/stdc++.h>
using namespace std;

int findSmallest(vector<int> &nums, int k)
{
  priority_queue<int> maxheap;
  for (auto num : nums)
  {
    maxheap.push(num);
    if (maxheap.size() > k)
    {
      maxheap.pop();
    }
  }
  return maxheap.top();
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
  cout << "kth smallest element: " << findSmallest(nums, k);
  return 0;
}