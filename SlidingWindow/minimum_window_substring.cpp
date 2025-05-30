#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
  if (s.empty() || t.empty())
    return "";
  unordered_map<char, int> need, window;
  for (auto ch : t)
  {
    need[ch]++;
  }
  int have = 0, needCount = need.size();
  int left = 0, minLen = INT_MAX, start = 0;

  for (int right = 0; right < s.size(); right++)
  {
    char c = s[right];
    window[c]++;
    if (need.count(c) && need[c] == window[c])
      have++;
    while (have == needCount)
    {
      if (right - left + 1 < minLen)
      {
        minLen = right - left + 1;
        start = left;
      }
      window[s[left]]--;
      if (need.count(s[left]) && need[s[left]] > window[s[left]])
        have--;
      left++;
    }
  }
  return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
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
  cout << endl
       << "enter the string t: " << endl;
  string t;
  while (true)
  {
    cin >> ch;
    if (ch == '#')
      break;
    t += ch;
  }
  for (int i = 0; i < t.length(); i++)
  {
    cout << t[i];
  }
  cout << endl;
  cout << "minimum window substring: " << minWindow(s, t);
  return 0;
}