#include <bits/stdc++.h>
using namespace std;

int longest(vector<int> &nums, int k)
{
  int left = 0;
  int right = 0;
  int zeros = 0;
  int maxi = INT_MIN;
  while (right < nums.size())
  {
    if (nums[right] == 0)
      zeros++;
    while (zeros > k)
    {
      if (nums[left] == 0)
        zeros--;
      left++;
    }
    if (zeros <= k)
    {

      maxi = max(maxi, right - left + 1);
    }
    right++;
  }
  return maxi;
}
int main()
{
  vector<int> a;
  int k;
  cout << "enter the value of k: " << endl;
  cin >> k;
  for (int i = 0; i < 10; i++)
  {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  cout << "max_consecutive 1 by flipping k zeros: " << longest(a, k);
  return 0;
}