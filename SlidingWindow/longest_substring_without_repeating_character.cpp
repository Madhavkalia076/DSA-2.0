#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s)
{
  if (s.length() == 0)
    return 0;
  int left = 0;
  int maxi = INT_MIN;
  unordered_set<char> seen;
  for (int right = 0; right < s.length(); right++)
  {
    if (seen.find(s[right]) != seen.end())
    {
      while (left < right && seen.find(s[right]) != seen.end())
      {
        seen.erase(s[left]);
        left++;
      }
    }
    seen.insert(s[right]);
    maxi = max(maxi, right - left + 1);
  }
  return maxi;
}

int main()
{
  string s;
  char c;
  while (true)
  {
    cin >> c;
    if (c == '#')
      break;
    s += c;
  }
  for (int i = 0; i < s.length(); i++)
  {
    cout << s[i];
  }
  cout << endl;
  cout << "length of longest substring without repeating characters: " << longestSubstring(s);
  return 0;
}