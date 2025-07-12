#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &maze, vector<vector<bool>> &visited, int drow[], int dcol[], char directions[], string op, int row, int col, int n)
{
  visited[row][col] = true;
  if (row == n - 1 && col == n - 1)
  {
    cout << op << endl;
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    int nrow = row + drow[i];
    int ncol = col + dcol[i];
    char ch = directions[i];
    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && maze[nrow][ncol] == 1 && visited[nrow][ncol] == false)
    {
      solve(maze, visited, drow, dcol, directions, op + ch, nrow, ncol, n);
      visited[nrow][ncol] = false;
    }
  }
}
int main()
{
  vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
  int n = maze.size();
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  string op = "";
  int drow[] = {-1, 0, 1, 0};
  int dcol[] = {0, 1, 0, -1};
  char directions[] = {'U', 'R', 'D', 'L'};
  solve(maze, visited, drow, dcol, directions, op, 0, 0, n);
  return 0;
}