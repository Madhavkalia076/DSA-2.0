#include <bits/stdc++.h>
using namespace std;
void delete1(stack<int> &st, int k)
{
  if (k == 1)
  {
    st.pop();
    return;
  }
  int temp = st.top();
  st.pop();
  delete1(st, k - 1);
  st.push(temp);
}
void deleteMiddle(stack<int> &st)
{
  int k = st.size() / 2;
  delete1(st, k);
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
  stack<int> st2 = st;
  cout << "stack before deleting middle element: ";
  while (!st2.empty())
  {
    cout << st2.top() << " ";
    st2.pop();
  }
  deleteMiddle(st);
  cout << endl
       << "after deleting middle element: ";
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}