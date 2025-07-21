#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> &nums, int target)
{
  int n = nums.size();
  vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
  for (int i = 0; i < n + 1; i++)
  {
    dp[i][0] = true;
  }
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < target + 1; j++)
    {
      if (nums[i - 1] <= j)
      {
        dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
      }
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][target];
}

bool equalsum(vector<int> nums)
{
  int sum = 0;
  for (int i : nums)
  {
    sum += i;
  }
  if (sum % 2 != 0)
    return false;
  else
    return subsetSum(nums, sum / 2);
}
int main()
{
  vector<int> nums = {2, 1, 11, 8};
  cout << equalsum(nums);
  return 0;
}