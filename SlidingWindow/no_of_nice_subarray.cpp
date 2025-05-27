#include <bits/stdc++.h>
using namespace std;
int count(vector<int> nums, int goal)
{
  int prefixsum = 0;
  unordered_map<int, int> mpp;
  mpp[0] = 1;
  int ans = 0;
  for (auto num : nums)
  {
    prefixsum += num % 2;
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
  int goal;
  cout << "enter the goal:" << endl;
  cin >> goal;
  vector<int> a;
  for (int i = 0; i < 10; i++)
  {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  for (int i = 0; i < 10; i++)
  {
    cout << a[i] << " ";
  }
  cout << "no. of nice subarray: " << count(a, goal);
  return 0;
}