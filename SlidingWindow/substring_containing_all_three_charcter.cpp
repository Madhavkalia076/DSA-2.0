#include <bits/stdc++.h>
using namespace std;
int findSubstring(string s)
{
  int lastseen[3] = {-1, -1, -1};
  int ans = 0;
  for (int i = 0; i < s.length(); i++)
  {
    lastseen[s[i] - 'a'] = i;
    if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1)
    {
      ans += 1 + min(lastseen[0], min(lastseen[1], lastseen[2]));
    }
  }
  return ans;
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
  for (int i = 0; i < s.length(); i++)
  {
    cout << s[i];
  }
  cout << endl;
  cout << "number of substring containing all three characters (a,b,c): " << findSubstring(s);
  return 0;
}