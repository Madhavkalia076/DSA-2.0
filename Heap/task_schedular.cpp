#include <bits/stdc++.h>
using namespace std;

int time(vector<char> &tasks, int n)
{
  priority_queue<int> maxheap;
  unordered_map<char, int> freq;
  for (auto it : tasks)
  {
    freq[it]++;
  }
  for (auto it : freq)
  {
    maxheap.push(it.second);
  }
  int time = 0;
  while (!maxheap.empty())
  {
    int cycle = n + 1;
    vector<int> temp;

    while (cycle-- && !maxheap.empty())
    {
      int count = maxheap.top();
      maxheap.pop();
      if (count - 1 > 0)
        temp.push_back(count - 1);
      time++;
    }
    for (auto it : temp)
    {
      maxheap.push(it);
    }
    if (!maxheap.empty())
    {
      time += cycle + 1;
    }
  }
  return time;
}
int main()
{
  vector<char> tasks;
  char ch;
  while (true)
  {
    cin >> ch;
    if (ch == '#')
      break;
    tasks.push_back(ch);
  }
  for (auto it : tasks)
  {
    cout << it << " ";
  }
  cout << endl
       << "enter the value of k: ";
  int n;
  cin >> n;
  cout << "minimum time to process all the tasks: " << time(tasks, n);
  return 0;
}