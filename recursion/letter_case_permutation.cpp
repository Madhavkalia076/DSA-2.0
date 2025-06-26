#include <bits/stdc++.h>
using namespace std;

void solve(string ip, string op)
{
  if (ip.length() == 0)
  {
    cout << op << " ";
    return;
  }
  if (isalpha(ip[0]))
  {
    string op1 = op;
    string op2 = op;
    op1 += tolower(ip[0]);
    op2 += toupper(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1);
    solve(ip, op2);
  }
  else
  {
    string op3 = op;
    op3 += ip[0];
    ip.erase(ip.begin() + 0);
    solve(ip, op3);
  }
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
  cout << "string: " << s;

  cout << endl
       << "letter case permutatiom: ";
  string op;
  solve(s, op);
  return 0;
}