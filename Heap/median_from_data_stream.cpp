#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
  priority_queue<int> maxheap;
  priority_queue<int, vector<int>, greater<int>> minheap;

public:
  MedianFinder()
  {
  }

  void addNum(int num)
  {
    maxheap.push(num);
    minheap.push(maxheap.top());
    maxheap.pop();
    if (minheap.size() > maxheap.size())
    {
      maxheap.push(minheap.top());
      minheap.pop();
    }
  }

  double findMedian()
  {
    if (maxheap.size() > minheap.size())
      return maxheap.top();
    return (maxheap.top() + minheap.top()) / 2.0;
  }
};
int main()
{
  MedianFinder m;
  m.addNum(1);
  m.addNum(2);
  cout << m.findMedian() << endl;
  m.addNum(3);
  cout << m.findMedian() << endl;
  m.addNum(4);
  cout << m.findMedian() << endl;
  return 0;
}