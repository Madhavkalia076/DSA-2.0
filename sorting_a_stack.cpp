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
void sort(stack<int> &st)
{
  if (st.empty())
    return;
  int temp = st.top();
  st.pop();
  sort(st);
  insert(st, temp);
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