#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &a, int k)
{
  int l = 0, r = 0, count = 0;
  unordered_map<int, int> mpp;
  while (r < a.size())
  {
    mpp[a[r]]++;
    while (mpp.size() > k)
    {
      mpp[a[l]]--;
      if (mpp[a[l]] == 0)
        mpp.erase(a[l]);
      l++;
    }
    count += (r - l + 1);
    r++;
  }
  return count;
}
int NoOfSubstring(vector<int> &a, int k)
{
  int atmostK = f(a, k);
  int atmostK_1 = f(a, k - 1);
  return atmostK - atmostK_1;
}

int main()
{
  vector<int> a;
  int temp;
  while (true)
  {
    cin >> temp;
    if (temp == -1)
      break;
    a.push_back(temp);
  }
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  cout << "enter the value of k: ";
  int k;
  cin >> k;
  cout << "no. of substring with exactly k different integers: " << NoOfSubstring(a, k);
  return 0;
}
