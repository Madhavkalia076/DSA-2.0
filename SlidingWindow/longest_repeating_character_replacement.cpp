#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
  int l = 0, r = 0;
  int maxlen = 0, maxf = 0;
  int hash[26] = {0};
  while (r < s.size())
  {
    hash[s[r] - 'A']++;
    maxf = max(maxf, hash[s[r] - 'A']);
    if ((r - l + 1) - maxf > k)
    {
      hash[s[l] - 'A']--;
      // maxf=0;
      // for(int i=0;i<26;i++){
      //     maxf=max(maxf,hash[i]);
      // }
      l++;
    }
    if ((r - l + 1) - maxf <= k)
    {
      maxlen = max(maxlen, r - l + 1);
    }
    r++;
  }
  return maxlen;
}
int main()
{
  int k;
  cout << "enter the value of k" << endl;
  cin >> k;
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
  cout << "length of repeating character replacement: " << characterReplacement(s, k);
  return 0;
}