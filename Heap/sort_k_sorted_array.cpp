#include <bits/stdc++.h>
using namespace std;

void sortK(vector<int> &nums, int k)
{
  int j = 0;
  priority_queue<int, vector<int>, greater<int>> minheap;
  for (auto num : nums)
  {
    minheap.push(num);
    if (minheap.size() > k)
    {
      nums[j] = minheap.top();
      j++;
      minheap.pop();
    }
  }
  while (!minheap.empty())
  {
    nums[j] = minheap.top();
    j++;
    minheap.pop();
  }
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
  cout << "array before sorting: " << endl;
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << " ";
  }
  cout << endl
       << "enter tha value of k:";
  int k;
  cin >> k;
  cout
      << "array after sorting: " << endl;
  sortK(a, k);
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << " ";
  }
  return 0;
}