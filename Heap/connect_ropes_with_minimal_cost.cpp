#include <bits/stdc++.h>
using namespace std;

int cost(vector<int> arr)
{
  priority_queue<int, vector<int>, greater<int>> minheap;
  for (auto it : arr)
  {
    minheap.push(it);
  }
  int ans = 0;
  while (minheap.size() >= 2)
  {
    int first = minheap.top();
    minheap.pop();
    int second = minheap.top();
    minheap.pop();
    minheap.push(first + second);
    ans += first + second;
  }
  return ans;
}
int main()
{
  vector<int> arr;
  int temp = 0;
  while (true)
  {
    cin >> temp;
    if (temp == -1)
      break;
    arr.push_back(temp);
  }
  for (auto it : arr)
  {
    cout << it << " ";
  }
  cout << endl
       << "minimal cost to connect n ropes: " << cost(arr);
  return 0;
}