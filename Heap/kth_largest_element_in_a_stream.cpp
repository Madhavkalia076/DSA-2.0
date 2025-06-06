#include <bits/stdc++.h>
using namespace std;

class kthlargest
{
private:
  int temp;
  priority_queue<int, vector<int>, greater<int>> minheap;

public:
  kthlargest(int k, vector<int> &num)
  {
    temp = k;
    for (auto i : num)
    {
      minheap.push(i);
      if (minheap.size() > k)
        minheap.pop();
    }
  }

  int add(int val)
  {
    minheap.push(val);
    if (minheap.size() > temp)
      minheap.pop();
    return minheap.top();
  }
};
int main()
{
  vector<int> num = {3, 4, 5, 6};
  kthlargest a(3, num);
  cout << "kth largest on adding 7: " << a.add(7) << endl;
  cout << "kth largest on adding 8: " << a.add(8) << endl;
  cout << "kth largest on adding 9: " << a.add(9) << endl;
  return 0;
}