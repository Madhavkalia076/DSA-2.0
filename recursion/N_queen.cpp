#include <bits/stdc++.h>
using namespace std;
void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftrow, vector<int> &upperdiagonal, vector<int> &lowerdiagonal, int n)
{
  if (col == n)
  {
    ans.push_back(board);
    return;
  }
  for (int row = 0; row < n; row++)
  {
    if (leftrow[row] == 0 && lowerdiagonal[row + col] == 0 && upperdiagonal[n - 1 + col - row] == 0)
    {
      board[row][col] = 'Q';
      leftrow[row] = 1;
      lowerdiagonal[row + col] = 1;
      upperdiagonal[n - 1 + col - row] = 1;
      solve(col + 1, board, ans, leftrow, upperdiagonal, lowerdiagonal, n);
      board[row][col] = '.';
      leftrow[row] = 0;
      upperdiagonal[n - 1 + col - row] = 0;
      lowerdiagonal[row + col] = 0;
    }
  }
}
vector<vector<string>> Nquuen(int n)
{
  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, '.');
  for (int i = 0; i < n; i++)
  {
    board[i] = s;
  }
  vector<int> leftrow(n, 0);
  vector<int> upperdiagonal(2 * (n - 1), 0);
  vector<int> lowerdiagonal(2 * (n - 1), 0);
  solve(0, board, ans, leftrow, upperdiagonal, lowerdiagonal, n);
  return ans;
}
int main()
{
  int n;
  cout << "enter the value of n: ";
  cin >> n;
  vector<vector<string>> s = Nquuen(n);
  for (auto i : s)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}