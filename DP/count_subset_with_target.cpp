#include <bits/stdc++.h>
using namespace std;
// int solve(vector<int> &arr, int n, int target, vector<vector<int>> &dp)
// {
//   if (n == 0 && target == 0)
//   {
//     return 1;
//   }
//   if (dp[n][target] != -1)
//     return dp[n][target];
//   if (arr[n - 1] <= target)
//   {
//     return dp[n][target] = solve(arr, n - 1, target - arr[n - 1], dp) + solve(arr, n - 1, target, dp);
//   }
//   else
//     return dp[n][target] = solve(arr, n - 1, target, dp);
// }

int main()
{
  vector<int> arr = {2, 3, 5, 8, 10};
  int target = 10;
  int n = arr.size();
  vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
  for (int i = 0; i < n + 1; i++)
  {
    dp[i][0] = 1;
  }
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < target + 1; j++)
    {
      if (arr[i - 1] <= j)
      {
        dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
      }
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  cout << dp[n][target];
  return 0;
}