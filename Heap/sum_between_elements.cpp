#include <bits/stdc++.h>
using namespace std;

int kthsmallest(vector<int> &a, int k)
{
  priority_queue<int> maxheap;
  for (auto it : a)
  {
    maxheap.push(it);
    if (maxheap.size() > k)
      maxheap.pop();
  }
  return maxheap.top();
}

int findSum(vector<int> &a, int k1, int k2)
{
  int first = kthsmallest(a, k1);
  int second = kthsmallest(a, k2);
  int ans = 0;
  for (auto it : a)
  {
    if (it > first && it < second)
    {
      ans += it;
    }
  }
  return ans;
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
  for (auto it : a)
  {
    cout << it << " ";
  }
  cout << endl
       << "enter the value of k1 and k2: ";
  int k1, k2;
  cin >> k1 >> k2;
  cout << "sum of elements between k1th smallest and k2th smallest element in array: " << findSum(a, k1, k2);
  return 0;
}