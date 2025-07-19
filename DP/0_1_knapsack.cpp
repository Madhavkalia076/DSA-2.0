#include <bits/stdc++.h>
using namespace std;
// int solve(vector<int> &wt, vector<int> &val, int w, int n)
// {
//   if (n == 0 && w == 0)
//     return 0;
//   if (wt[n - 1] <= w)
//   {
//     return max(val[n - 1] + solve(wt, val, w - wt[n - 1], n - 1), solve(wt, val, w, n - 1));
//   }
//   else if (wt[n - 1 > w])
//   {
//     return solve(wt, val, w, n - 1);
//   }
// }
// int solve(vector<int> &wt, vector<int> &val, int w, int n, vector<vector<int>> &dp)
// {
//   if (w == 0 || n == 0)
//   {
//     return dp[n][w] = 0;
//   }
//   if (dp[n][w] != -1)
//     return dp[n][w];
//   if (wt[n - 1] <= w)
//   {
//     return dp[n][w] = max(val[n - 1] + solve(wt, val, w - wt[n - 1], n - 1, dp), solve(wt, val, w, n - 1, dp));
//   }
//   else
//   {
//     return dp[n][w] = solve(wt, val, w, n - 1, dp);
//   }
// }
int main()
{
  vector<int> wt = {1, 2, 3};
  vector<int> val = {4, 5, 1};
  int w = 4;
  int n = wt.size();
  vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < w + 1; j++)
    {
      if (wt[i - 1] <= j)
      {
        dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  cout << dp[n][w] << endl;
  return 0;
}