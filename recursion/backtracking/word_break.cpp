#include <bits/stdc++.h>
using namespace std;
void solve(string &s, int idx, vector<string> &temp, unordered_set<string> dict)
{
  if (idx == s.size())
  {
    string sentence;
    for (int i = 0; i < temp.size(); i++)
    {
      sentence += temp[i];
      if (i != temp.size() - 1)
      {
        sentence += " ";
      }
    }
    cout << sentence << endl;
    return;
  }
  string word;
  for (int i = idx; i < s.size(); i++)
  {
    word += s[i];
    if (dict.find(word) != dict.end())
    {
      temp.push_back(word);
      solve(s, i + 1, temp, dict);
      temp.pop_back();
    }
  }
}
int main()
{
  string s = "catsanddog";
  vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
  unordered_set<string> dict(wordDict.begin(), wordDict.end());
  vector<string> temp;
  solve(s, 0, temp, dict);
  return 0;
}