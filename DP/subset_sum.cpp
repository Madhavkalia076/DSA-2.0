#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6,7};
  int n = arr.size();
  int sum = 6;
  vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
  for (int i = 0; i < n + 1; i++)
  {
    dp[i][0] = true;
  }
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < sum + 1; j++)
    {
      if (arr[i - 1] <= j)
      {
        dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  dp[n][sum] == 1 ? cout << "true" : cout << "false";
  return 0;
}