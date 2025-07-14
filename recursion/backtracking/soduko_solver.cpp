#include <bits/stdc++.h>
using namespace std;
bool isplaced(char num, int r, int c, vector<vector<char>> &board)
{
  for (int j = 0; j < 9; j++)
  {
    if (board[r][j] == num)
      return false;
  }
  for (int i = 0; i < 9; i++)
  {
    if (board[i][c] == num)
      return false;
  }
  int sr = (r / 3) * 3;
  int sc = (c / 3) * 3;
  for (int i = sr; i < sr + 3; i++)
  {
    for (int j = sc; j < sc + 3; j++)
    {
      if (board[i][j] == num)
        return false;
    }
  }
  return true;
}
void solve(int row, int col, vector<vector<char>> &board, bool &flag)
{
  if (row == 9)
  {
    flag = true;
    return;
  }
  if (col == 9)
  {
    solve(row + 1, 0, board, flag);
    return;
  }
  if (board[row][col] != '.')
  {
    solve(row, col + 1, board, flag);
    return;
  }
  for (char num = '1'; num <= '9'; num++)
  {
    if (isplaced(num, row, col, board))
    {
      board[row][col] = num;
      solve(row, col + 1, board, flag);
      if (flag)
        return;
      board[row][col] = '.';
    }
  }
}
int main()
{
  vector<vector<char>> board = {
      {'5', '2', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  bool flag = false;
  solve(0, 0, board, flag);
  for (auto i : board)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}