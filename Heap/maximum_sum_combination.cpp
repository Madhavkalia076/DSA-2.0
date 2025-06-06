#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector<int> maxCombination(vector<int> &A, vector<int> &B, int k)
{
  int n = A.size();
  sort(A.begin(), A.end(), greater<int>());
  sort(B.begin(), B.end(), greater<int>());
  priority_queue<pair<int, pair<int, int>>> maxheap;
  set<pair<int, int>> visited;
  maxheap.push({A[0] + B[0], {0, 0}});
  visited.insert({0, 0});
  vector<int> result;
  while (k-- && !maxheap.empty())
  {
    auto top = maxheap.top();
    int sum = top.first;
    int i = top.second.first;
    int j = top.second.second;
    maxheap.pop();
    result.push_back(sum);
    if (i + 1 < n && visited.find({i + 1, j}) == visited.end())
    {
      maxheap.push({A[i + 1] + B[j], {i + 1, j}});
      visited.insert({i + 1, j});
    }
    if (j + 1 < n && visited.find({i, j + 1}) == visited.end())
    {
      maxheap.push({A[i] + B[j + 1], {i, j + 1}});
      visited.insert({i, j + 1});
    }
  }
  return result;
}
int main()
{
  vector<int> a, b;
  int temp;
  while (true)
  {
    cin >> temp;
    if (temp == -1)
      break;
    a.push_back(temp);
  }
  cout << "a: ";
  for (int i : a)
  {
    cout << i << " ";
  }
  cout << endl;
  for (int i = 0; i < a.size(); i++)
  {
    cin >> temp;
    b.push_back(temp);
  }
  cout << "b: ";
  for (int i : b)
  {
    cout << i << " ";
  }
  cout << "enter the value of k: " << endl;
  int k;
  cin >> k;
  vector<int> result = maxCombination(a, b, k);
  cout << "k max sum combinations: ";
  for (int i : result)
  {
    cout << i << " ";
  }
  return 0;
}