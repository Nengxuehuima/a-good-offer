要解决这个问题，我们可以使用双指针（或者说双链表）方法，通过创建两个链表：一个用于存放所有小于x的节点，另一个用于存放所有大于等于x的节点。最后，我们将这两个链表连接起来。
以下是解题步骤的详细说明：
(1).初始化两个链表：lessHead用于存放小于x的节点，greaterHead用于存放大于等于x的节点。同时，我们还需要两个工作指针lessTail和greaterTail来跟踪这两个链表的末尾，以便我们可以轻松地添加新节点。
(2).遍历原链表：遍历给定的链表，对于每个节点，根据它的值与x的比较结果，将其添加到lessHead或greaterHead链表的末尾。
(3).连接两个链表：遍历结束后，我们将小于x的链表（如果存在）的末尾连接到大于等于x的链表的头部（如果存在）。
(4).处理边界情况：如果所有节点都小于x或所有节点都大于等于x，我们只需要返回对应的链表即可。


#include <iosteam>
using namespace std;

struct ListNode
{
int val;
ListNode* next;
ListNode(int x):val(x) , next(nullptr) {}
};

//分隔链表函数
ListNode* partition(ListNode* head,int x)
{
  //创建两个哑节点
  ListNode lessHead(0) , greaterHead(0);
  ListNode* lessTail = &lessHead , *greaterTail = &greaterHead;

  while(head!=nullptr)
    {
      if(head->val<x)
      {
        lessTail->next = head;
        lessTail = head;
      }
      else
      {
        greaterTail->next = head;
        greaterTail = head;
      }
      head = head->next;
    }

  lessTail->next = greaterHead.next;//连接两部分  “. ”用于直接通过对象访问其成员   “->” 用于通过指针访问对象的成员
  greaterTail->next = nullptr;//防止形成循环链表
  return lessHead.next;
}

//打印链表
void printfList(ListNode* head)
{
  while(head!=nullptr)
    {
      cout<<head->val<<" ";
      head = head->next;
    }
  cout<<endl;
}

int main()
{
  int n,val,x;
  cin>>n;//节点总数
  cin>>x;//指定x的值

  ListNode* head = nullptr,* tail = nullptr;
  //构建链表
  for(int i=0;i<n;i++)
    {
      cin>>val;
      if(head==nullptr)
      {
        head = tail = new ListNode(val);
      }
      else
      {
        tail->next = new ListNode(val);
        tail = tail->next;
      }
    }
  //分隔链表
  head = partition(head,x);
  printfList(head);

  //释放内存
  while(head!=nullptr)
    {
      ListNode* temp = head;
      head = head->next;
      delete temp;
    }
  return 0;
    
}
