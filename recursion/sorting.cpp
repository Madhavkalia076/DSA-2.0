#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &nums, int temp)
{
  if (nums.size() == 0 || nums[nums.size() - 1] <= temp)
  {
    nums.push_back(temp);
    return;
  }
  int val = nums[nums.size() - 1];
  nums.pop_back();
  insert(nums, temp);
  nums.push_back(val);
  return;
}
void sort(vector<int> &nums)
{
  if (nums.size() == 0)
    return;
  int temp = nums[nums.size() - 1];
  nums.pop_back();
  sort(nums);
  insert(nums, temp);
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
  for (int i : nums)
  {
    cout << i << " ";
  }
  cout << endl;
  cout << "after sorting nums will be: ";
  sort(nums);
  for (int i : nums)
  {
    cout << i << " ";
  }
  return 0;
}