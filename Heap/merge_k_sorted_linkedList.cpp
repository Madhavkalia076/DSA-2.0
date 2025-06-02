#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct compare
{
  bool operator()(ListNode *a, ListNode *b)
  {
    return a->val > b->val;
  }
};
ListNode *Merge(vector<ListNode *> lists)
{
  priority_queue<ListNode *, vector<ListNode *>, compare> minheap;
  for (auto it : lists)
  {
    if (it)
    {
      minheap.push(it);
    }
  }
  if (minheap.size() == 0)
    return NULL;
  ListNode *head = minheap.top();
  minheap.pop();
  if (head->next)
  {
    minheap.push(head->next);
  }
  ListNode *temp = head;
  while (!minheap.empty())
  {
    ListNode *temp1 = minheap.top();
    minheap.pop();

    temp->next = temp1;
    temp = temp1;

    if (temp1->next)
    {
      minheap.push(temp1->next);
    }
  }
  return head;
}
void printList(ListNode *head)
{
  while (head != NULL)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
int main()
{
  int k;
  cout << "Enter number of linked lists: ";
  cin >> k;

  vector<ListNode *> lists(k);

  for (int i = 0; i < k; i++)
  {
    int n;
    cout << "Enter number of elements in list " << i + 1 << ": ";
    cin >> n;

    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    cout << "Enter " << n << " sorted values: ";
    for (int j = 0; j < n; j++)
    {
      int x;
      cin >> x;
      tail->next = new ListNode(x);
      tail = tail->next;
    }

    lists[i] = dummy->next;
  }

  ListNode *mergedHead = Merge(lists);

  cout << "Merged List: ";
  printList(mergedHead);

  return 0;
}