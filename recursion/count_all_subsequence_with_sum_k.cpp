#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &v, int target, int index, int &count, int &sum)
{
  if (index == v.size())
  {
    if (sum == target)
    {
      count++;
    }
    return;
  }
  int sum1 = sum;
  sum1 += v[index];
  solve(v, target, index + 1, count, sum1);
  solve(v, target, index + 1, count, sum);
  return;
}
int main()
{
  vector<int> v;
  int temp;
  while (true)
  {
    cin >> temp;
    if (temp == -1)
      break;
    v.push_back(temp);
  }
  for (auto i : v)
  {
    cout << i << " ";
  }
  int target;
  cout << endl
       << "enter the target: ";
  cin >> target;
  int sum = 0;
  int count = 0;
  solve(v, target, 0, count, sum);
  cout << "no of subsequence with sum k: " << count;
  return 0;
}