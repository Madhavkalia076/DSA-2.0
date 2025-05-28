#include <bits/stdc++.h>
using namespace std;
int findMax(vector<int> a, int k)
{
  int n = a.size();
  int ans = 0;
  vector<int> leftsum(k + 1, 0);
  vector<int> rightsum(k + 1, 0);

  for (int i = 1; i <= k; i++)
  {
    leftsum[i] = leftsum[i - 1] + a[i - 1];
    rightsum[i] = rightsum[i - 1] + a[n - i];
  }

  for (int i = 0; i <= k; i++)
  {
    ans = max(ans, leftsum[i] + rightsum[k - i]);
  }
  return ans;
}

int main()
{
  int size;
  cout << "enter the size of vector";
  cin >> size;
  vector<int> a;
  int temp;
  for (int i = 0; i < size; i++)
  {
    cin >> temp;
    a.push_back(temp);
  }
  for (int i = 0; i < size; i++)
  {
    cout << a[i] << " ";
  }
  cout << "enter the value of k: ";
  int k;
  cin >> k;
  cout << endl;
  cout << "maximum points obtained from cards: " << findMax(a, k);
  return 0;
}