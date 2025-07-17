#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &wt, vector<int> &val, int w, int n)
{
  if (n == 0 && w == 0)
    return 0;
  if (wt[n - 1] <= w)
  {
    return max(val[n - 1] + solve(wt, val, w - wt[n - 1], n - 1), solve(wt, val, w, n - 1));
  }
  else if (wt[n - 1 > w])
  {
    return solve(wt, val, w, n - 1);
  }
}
int main()
{
  vector<int> wt = {1, 2, 3};
  vector<int> val = {4, 5, 1};
  int w = 4;
  int n = wt.size();
  int ans = solve(wt, val, w, n);
  cout << ans << endl;
  return 0;
}