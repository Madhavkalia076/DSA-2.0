#include <bits/stdc++.h>
using namespace std;
int numSubarraysWithSum(vector<int> &nums, int goal)
{
  int prefixsum = 0;
  int ans = 0;
  unordered_map<int, int> mpp;
  mpp[0] = 1;
  for (auto num : nums)
  {
    prefixsum += num;
    if (mpp.find(prefixsum - goal) != mpp.end())
    {
      ans += mpp[prefixsum - goal];
    }
    mpp[prefixsum]++;
  }
  return ans;
}
int main()
{
  vector<int> a;
  for (int i = 0; i < 5; i++)
  {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }

  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  cout << "enter the goal:";
  int goal;
  cin >> goal;
  cout << "binary subarray with sum=goal: " << numSubarraysWithSum(a, goal);
  return 0;
}