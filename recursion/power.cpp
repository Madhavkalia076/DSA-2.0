#include <bits/stdc++.h>
using namespace std;

double solve(double base, long long exp)
{
  if (exp == 0)
    return 1;
  double half = solve(base, exp / 2);
  double full = half * half;
  if (exp % 2 == 0)
    return full;
  return base * full;
}
double power(double x, int n)
{
  long long exp = llabs(n);
  double result = solve(x, exp);
  return (n > 0) ? result : 1 / result;
}
int main()
{
  int x, n;
  cout << "enter the value of base: ";
  cin >> x;
  cout << "enter the value of exponent: ";
  cin >> n;
  cout << "result: " << power(x, n);
  return 0;
}
