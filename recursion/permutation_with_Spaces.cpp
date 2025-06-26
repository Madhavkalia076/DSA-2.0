#include <bits/stdc++.h>
using namespace std;

void solve(string ip, string op)
{
  if (ip.length() == 0)
  {
    cout << op << "   ";
    return;
  }
  string op1 = op;
  string op2 = op;
  op1 += ' ';
  op1 += ip[0];
  op2 += ip[0];
  ip.erase(ip.begin() + 0);
  solve(ip, op1);
  solve(ip, op2);
}
int main()
{
  string s;
  char ch;
  while (true)
  {
    cin >> ch;
    if (ch == '#')
      break;
    s += ch;
  }
  cout << "string s: " << " ";
  for (char c : s)
  {
    cout << c;
  }
  string op;
  op += s[0];
  s.erase(s.begin() + 0);
  cout << endl
       << "permutation with spaces: ";
  solve(s, op);
  return 0;
}