#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> ip, vector<int> op, vector<vector<int>> &ans)
{
  if (ip.size() == 0)
  {
    ans.push_back(op);
    return;
  }
  vector<int> op1 = op;
  op1.push_back(ip[0]);
  ip.erase(ip.begin() + 0);
  solve(ip, op1, ans);
  solve(ip, op, ans);
}
vector<vector<int>> subsets(vector<int> &nums)
{
  vector<vector<int>> ans;
  vector<int> op;
  solve(nums, op, ans);
  vector<vector<int>> result;
  set<vector<int>> unique;
  for (auto i : ans)
  {
    unique.insert(i);
  }
  for (auto i : unique)
  {
    result.push_back(i);
  }
  return result;
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
  for (auto i : nums)
  {
    cout << i << " ";
  }
  cout << endl;
  vector<vector<int>> ans = subsets(nums);
  for (auto i : ans)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}