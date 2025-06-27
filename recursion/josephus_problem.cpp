#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, int index, int k, int &ans)
{
  if (v.size() == 1)
  {
    ans = v[0];
    return;
  }
  index = (index + k - 1) % v.size();
  v.erase(v.begin() + index);
  solve(v, index, k, ans);
}
int main()
{
  int n, k;
  cout << "enter the value of n: ";
  cin >> n;
  cout << "enter the value of k: ";
  cin >> k;
  vector<int> v(n, -1);
  for (int i = 0; i < n; i++)
  {
    v[i] = i + 1;
  }
  int ans = -1;
  solve(v, 0, k, ans);
  cout << "output: " << ans;
  return 0;
}