#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long power(long long base, long long exp)
{
  if (exp == 0)
    return 1;
  long long half = power(base, exp / 2);
  long long full = (half * half) % MOD;

  if (exp % 2 == 0)
    return full;
  else
    return (full * base) % MOD;
}

int count(long long n)
{
  long long evenCount = (n + 1) / 2;
  long long oddCount = n / 2;
  return (power(5, evenCount) * power(4, oddCount)) % MOD;
}
int main()
{
  cout << "enter the value of n: ";
  long long n;
  cin >> n;
  cout << "number of good number with total number of digits n: " << count(n);
  return 0;
}