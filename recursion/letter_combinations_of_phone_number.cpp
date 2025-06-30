#include <bits/stdc++.h>
using namespace std;
void solve(string digits, int index, string current, string mapping[])
{
  if (index == digits.length())
  {
    cout << current << " ";
    return;
  }
  string letters = mapping[digits[index] - '0'];
  for (char ch : letters)
  {
    solve(digits, index + 1, current + ch, mapping);
  }
}
int main()
{
  string digits = "23";

  cout << "digits: " << digits;
  string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  cout << endl
       << "different combination: ";
  solve(digits, 0, "", mapping);
  return 0;
}