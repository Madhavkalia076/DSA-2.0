#include <bits/stdc++.h>
using namespace std;

void solve(char s, char d, char h, int n)
{
  if (n == 1)
  {
    cout << "move disk " << n << " from " << s << " to " << d << endl;
    return;
  }
  solve(s, h, d, n - 1);
  cout << "move disk " << n << " from " << s << " to " << d << endl;
  solve(h, d, s, n - 1);
}
int main()
{
  char s, d, h;
  cin >> s >> d >> h;
  int n;
  cin >> n;
  solve(s, d, h, n);
  return 0;
}