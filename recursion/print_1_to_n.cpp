#include <bits/stdc++.h>
using namespace std;

void printN(int n)
{
  if (n == 1)
  {
    cout << n << " ";
    return;
  }

  printN(n - 1);
  cout << n << " ";
}
int main()
{
  printN(5);
  return 0;
}
