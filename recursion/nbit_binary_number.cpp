#include <bits/stdc++.h>
using namespace std;
void solve(int one, int zero, int n, string op)
{
  if (n == 0)
  {
    cout << op << " ";
    return;
  }
  string op1 = op;
  op1 += '1';
  solve(one + 1, zero, n - 1, op1);
  if (one > zero)
  {
    string op2 = op;
    op2 += '0';
    solve(one, zero + 1, n - 1, op2);
  }
}
int main()
{
  string op = "";
  int n;
  cout << "enter the value of n: ";
  cin >> n;
  solve(0, 0, n, op);
  return 0;
}