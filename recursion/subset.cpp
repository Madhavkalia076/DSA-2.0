#include <bits/stdc++.h>
using namespace std;

void solve(string ip, string op)
{
  if (ip.length() == 0)
  {
    cout << "'" << op << "'" << " ";
    return;
  }
  string op1 = op;
  string op2 = op;
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
  cout << "string : ";
  for (char c : s)
  {
    cout << c;
  }
  string op = "";
  cout << endl
       << "subset of string: ";
  solve(s, op);
  return 0;
}