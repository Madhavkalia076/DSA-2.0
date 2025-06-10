#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp)
{
  if (s.empty() || s.top() <= temp)
  {
    s.push(temp);
    return;
  }
  int val = s.top();
  s.pop();
  insert(s, temp);
  s.push(val);
}
void sort(stack<int> &s)
{
  if (s.empty())
    return;
  int temp = s.top();
  s.pop();
  sort(s);
  insert(s, temp);
}
int main()
{
  stack<int> s;
  int temp;
  while (true)
  {
    cin >> temp;
    if (temp == -1)
      break;
    s.push(temp);
  }
  sort(s);
  cout << s.top();
  return 0;
}