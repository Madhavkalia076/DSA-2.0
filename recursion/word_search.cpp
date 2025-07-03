#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>> &board, string word, int m, int n, int row, int col, int delrow[], int delcol[], vector<vector<int>> &vis, string curr, bool &ans)
{
  vis[row][col] = 1;
  if (curr.length() == word.length())
  {
    if (curr == word)
    {
      ans = true;
      return;
    }
    vis[row][col] = -1;
    return;
  }
  if (curr.length() > word.length())
    return;
  for (int i = 0; i < 4; i++)
  {
    int nrow = row + delrow[i];
    int ncol = col + delcol[i];

    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] == -1)
    {
      solve(board, word, m, n, nrow, ncol, delrow, delcol, vis, curr + board[nrow][ncol], ans);
      if (ans)
      {
        vis[row][col] = -1;
        return;
      }
    }
  }
  vis[row][col] = -1;
}
int main()
{
  vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                {'S', 'F', 'C', 'S'},
                                {'A', 'D', 'E', 'E'}};

  string word = " SEE";
  int m = board.size();
  int n = board[0].size();
  vector<vector<int>> vis(m, vector<int>(n, -1));
  int delrow[] = {-1, 0, 1, 0};
  int delcol[] = {0, 1, 0, -1};
  bool ans = false;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] == word[0])
      {
        solve(board, word, m, n, i, j, delrow, delcol, vis, string(1, board[i][j]), ans);
        if (ans)
        {
          cout << "true";
          break;
        }
      }
    }
  }
  cout << "false";
  return 0;
}