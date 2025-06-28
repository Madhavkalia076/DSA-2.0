#include <bits/stdc++.h>
using namespace std;
void solve(int index, vector<int> &v, int k, string &current)
{
  if (k == 0)
  {
    cout << current << " ";
    return;
  }
  if (k < 0)
    return;
  for (int i = index; i < v.size(); i++)
  {
    current += v[i];
    solve(i, v, k - v[i], current);
    current.pop_back();
  }
}
int main()
{
  vector<int> v;
  int temp = -1;
  while (true)
  {
    cin >> temp;
    if (temp == -1)
      break;
    v.push_back(temp);
  }
  for (int i : v)
  {
    cout << i << " ";
  }
  string current = "";
  cout << endl
       << "enter the value of target: ";
  int k;
  cin >> k;
  solve(0, v, k, current);
  return 0;
}