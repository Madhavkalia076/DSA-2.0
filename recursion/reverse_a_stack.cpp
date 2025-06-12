#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &st, int temp)
{
  if (st.size() == 0)
  {
    st.push(temp);
    return;
  }
  int val = st.top();
  st.pop();
  insert(st, temp);
  st.push(val);
}
void reverse(stack<int> &st)
{
  if (st.size() == 1)
    return;
  int temp = st.top();
  st.pop();
  reverse(st);
  insert(st, temp);
}
int main()
{
  stack<int> st;
  int temp;
  while (true)
  {
    cin >> temp;
    if (temp == -1)
      break;
    st.push(temp);
  }
  stack<int> s = st;
  cout << "before reversing: ";
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl
       << "after reversing: ";
  reverse(st);
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}