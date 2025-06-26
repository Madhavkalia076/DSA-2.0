#include <bits/stdc++.h>
using namespace std;
void solve(int open, int close, string op)
{
  if (open == 0 && close == 0)
  {
    cout << op << " ";
    return;
  }
  if (open != 0)
  {
    string op1 = op;
    op1 += '(';
    solve(open - 1, close, op1);
  }
  if (close > open)
  {
    string op2 = op;
    op2 += ')';
    solve(open, close - 1, op2);
  }
}
int main()
{
  int n;
  cout << "enter the value of n: ";
  cin >> n;
  string op = "";
  cout << "all balanced paranthesis: ";
  solve(n, n, op);
  return 0;
}